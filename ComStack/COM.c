/*
 ===============================================================================
 Name        :  COM.c
 Author      :  Maulik Patel
 Version     :
 Description :  Communication component C file
                This file is part of Autosar ComStack Project
 ===============================================================================
 */

/*  Library Include Files */
#include "library_types.h"

/* Component Include Files */
#include "COM.h"
#include "PduR_If.h"

/* Component Scope Variable Definitions */
COM_StackError_t COM_StackErrorLog[ERROR_TYPE_COUNT];


/*  Task Scope Variable Definitions */
static COM_groupCfg_t 			COM_GroupCfgDB[] = CONFIG_TABLE( COM_GROUP );    /* Group configuration database */
static const COM_signalCfg_t 	COM_SignalCfgDB[] = CONFIG_TABLE( COM_SIGNAL ); /* Signal configuration database */
static COM_signalDataCfg_t 		COM_SignalData[COM_SIGNAL_COUNT];        /* Signal Configuration metadata */

static groupData_t 	COM_GroupDataBuffer[COM_GROUP_DATA_BUFFER_SIZE];      /* Group data groupDataPtr holding message data  */
static uint8_t 		COM_Initialised;
static uint16_t 	COM_GroupDataBufferFreeBytes;


/*  Task Local Function declarations */
static void COM_InitSignal( uint16_t signal_index );
static void COM_InitGroups( void );
static uint16_t COM_LookupGroupByPortId( uint16_t portId );
static void COM_SignalCallbacks( const uint16_t groupIndex );
static COM_SigCBHandler_t COM_GetSignalCallbackFunction ( const uint16_t signalIndex );




/*
*  Function Name   : COM_Scheduler
*  Model Reference :
*  Description     :
*/

void COM_Scheduler( void )
{
    uint16_t i;
    static uint16_t tickCountms=0;

    tickCountms+=COM_TICK_PERIOD;

    /* Iterate over all communication messages */
    for( i = 0U; i < COM_GROUP_COUNT; i++ )
    {
        /* Check whether this group is able and ready to be sent */
        if (( COM_GroupCfgDB[i].interval != COM_GROUP_DISABLED ) &&
            ( COM_GroupCfgDB[i].interval != COM_SEND_TRIGGER ) &&
            (( tickCountms  % COM_GroupCfgDB[i].interval ) == 0U )&&
            ( COM_Initialised == TRUE  ))
        {
            /* Send the group */
            (void)COM_SendGroup( i );
        }
    }

    if ( tickCountms >= COM_TICK_PERIOD_MAX )
    {
        /* Wrap tick count to zero */
        tickCountms=0;
    }
}


/*
*  Function Name   : COM_InitSignal
*  Model Reference :
*  Description     : Initialise Communication Signal
*/

static void COM_InitSignal( uint16_t signal_index )
{
    uint8_t groupIdx;

    COM_signalDataCfg_t * sigDataPtr = &COM_SignalData[signal_index];
    const COM_signalCfg_t * sigCfgPtr = &COM_SignalCfgDB[signal_index];

    /* Evaluate the index of the group to which this signal belongs */
    groupIdx = sigCfgPtr->groupIdx;

    /* Get the length of signal in bytes */
    sigDataPtr->spread = (( sigCfgPtr->length - 1U ) >> 3 ) + 1U;

    /* Get the MSB of the signal */
    sigDataPtr->msbyte = ( sigCfgPtr->start + ( sigCfgPtr->length - 1U )) >> 3;
    /* Get the LSB of the signal*/
    sigDataPtr->lsbyte = sigCfgPtr->start >> 3;
    /* Get the bit offset of the  signal within LSB */
    sigDataPtr->lsbyte_lsb = sigCfgPtr->start - ( sigDataPtr->lsbyte << 3 );

    /* Get the signal's max value */
    sigDataPtr->max = (1U << sigCfgPtr->length)-1U;

    /* Get the signal data mask */
    sigDataPtr->data_mask = BIT_MASK( sigCfgPtr->length, uint32_t );

    /*  Check for signal configuration validity  */
    if(( sigDataPtr->msbyte < sigDataPtr->lsbyte ) ||
        ( sigDataPtr->msbyte >= COM_GroupCfgDB[groupIdx].length ) ||
        ( sigDataPtr->spread > COM_MAX_SIGNAL_LENGTH_BYTES )      ||
       (( sigDataPtr->msbyte - sigDataPtr->lsbyte ) > sizeof( uint32_t )))
    {
        LOG_ERROR(COM_SIGNAL_INVALID);
    }
}


/*
*  Function Name   : COM_InitGroups
*  Model Reference :
*  Description     : Initialise all communication groups Data pointers
*/


static void COM_InitGroups( void )
{
    uint16_t i;
    uint16_t totalGroupLength = 0U;
    uint8_t* bufferPtr = COM_GroupDataBuffer;

    /* Initialise all groups data pointers */
    for( i = 0U; i < (uint16_t)COM_GROUP_COUNT; i++ )
    {
        /* Setup the groupDataPtr location for corresponding group index */
        COM_GroupCfgDB[i].groupDataPtr = bufferPtr;

        /* Point to the next group's start location in groupDataPtr data*/
        bufferPtr += COM_GroupCfgDB[i].length;

        totalGroupLength+= COM_GroupCfgDB[i].length;
    }

    if ( totalGroupLength > COM_GROUP_DATA_BUFFER_SIZE )
    {
        /* Allocated data buffer is not of sufficient size to accommodate all data */
        LOG_ERROR(COM_GROUP_DATA_BUFFER_OVFLW);
        COM_GroupDataBufferFreeBytes = 0U;
    }
    else
    {
        COM_GroupDataBufferFreeBytes -= totalGroupLength;
    }

}



/*
*  Function Name   : COM_NetRxCallback
*  Model Reference :
*  Description     : Network -> Communications Gateway RX PDU call-back.
*/


void COM_NetRxCallback( const uint16_t portId, const pdu_t* const pdu )
{
    /* Get the group index for associated port id */
    uint16_t groupIdx = COM_LookupGroupByPortId( portId );
    uint8_t* pduGroupData;

    if( groupIdx < COM_GROUP_COUNT )
    {
        OS_CRITICAL_START( COM_STACK_SPINLOCK );

        /* Point to the pay load of PDU  */
        pduGroupData = pdu->pduData;

        /* Copy the PDU data into the group groupDataPtr */
        M_MEM_CPY_U8 ( pduGroupData, COM_GroupCfgDB[groupIdx].groupDataPtr, pdu->dataLength);

        OS_CRITICAL_STOP( COM_STACK_SPINLOCK );

        /* Execute all the signal callbacks associated with the group */
        COM_SignalCallbacks( groupIdx );

    }
    else
    {
        LOG_ERROR(COM_GROUP_INVALID);
    }
}


/*
*  Function Name   : COM_NetTxCallback
*  Model Reference :
*  Description     : Network -> Communications Gateway Tx PDU call-back.
*/


void COM_NetTxCallback( const uint16_t portId )
{
    /* Get the group index for associated port id */
    uint16_t groupIdx = COM_LookupGroupByPortId( portId );

    if( groupIdx < COM_GROUP_COUNT )
    {
        /* Execute all the signal callbacks associated with the group */
        COM_SignalCallbacks( groupIdx );

    }
    else
    {
        LOG_ERROR(COM_GROUP_INVALID);
    }
}



/*
*  Function Name   : COM_SignalCallbacks
*  Model Reference :
*  Description     : Execute all the signal callback handlers for requested group
*/

static void COM_SignalCallbacks( const uint16_t groupIndex )
{
    uint16_t i=0;
    uint32_t localSignalData= 0U;
    COM_SigCBHandler_t callbackHander;

    for( i=0; i < COM_SIGNAL_COUNT; i++ )
    {
        /* Check if the signal belongs to the group index */
        if( COM_SignalCfgDB[i].groupIdx == groupIndex )
        {
            /* Get the associated callback function for this signal */
            callbackHander = COM_GetSignalCallbackFunction( i );

            if( NULL != callbackHander )
            {
                /* Get the signal data */
                if ( E_OK == COM_GetSignal( i, &localSignalData ))
                {
                    /* Execute callback function */
                    callbackHander( &localSignalData );
                }
                else
                {
                    /* Error getting signal Data; already logged in the function itself */
                }
            }
            else
            {
                /* No callback hook associated with the signal */
            }
        }
        else
        {
            /* This signal does not belongs to the concerned group; Ignore this signal */
        }
    }
}


/*
*  Function Name   : COM_GetSignalCallbackFunction
*  Model Reference :
*  Description     : Get calback handler associated with the signal
*/

static COM_SigCBHandler_t COM_GetSignalCallbackFunction ( const uint16_t signalIndex )
{
    return ( COM_SignalCfgDB[signalIndex].cbk_handler );
}


/*
*  Function Name   : COM_SendGroup
*  Model Reference :
*  Description     : Sends the specified group via corresponding interface
*/


Std_ReturnType COM_SendGroup( const uint16_t i )
{
    uint8_t pduDataLocal[COM_FRAME_LEN];
    uint8_t byte;
    pdu_t txIPdu;
    COM_groupCfg_t *groupPtr;
    Std_ReturnType rtn = E_NOT_OK;

    if( i >= (uint16_t)COM_GROUP_COUNT )
    {
        /* Invalid Group index */
        LOG_ERROR(COM_GROUP_INVALID);
    }
    else
    {
        /* Initialise the group configuration pointer */
        groupPtr= &COM_GroupCfgDB[i];

        /* Populate the tx Ipdu */
        txIPdu.pduData = pduDataLocal;

        if( groupPtr->length < COM_STDFRAME_DATALEN )
        {
            /* If length of group is less than standard CAN message size */
            for(byte = groupPtr->length; byte < COM_STDFRAME_DATALEN; byte++ )
            {
                /* Fill the remaining bytes with stuffing values */
                 txIPdu.pduData[byte] = COM_GROUP_BYTE_STUFF_VALUE;
            }
            txIPdu.dataLength = groupPtr->length;
        }
        else
        {
            txIPdu.dataLength = groupPtr->length;
        }

        OS_CRITICAL_START( COM_STACK_SPINLOCK );

        /* Populate the transmit I-PDU */
        (void)M_MEM_CPY_U8( groupPtr->groupDataPtr,  txIPdu.pduData,  txIPdu.dataLength );

        OS_CRITICAL_STOP( COM_STACK_SPINLOCK );


        /* Evaluate the comms. interface for this group */
        switch( groupPtr->interface )
        {
            case COM_IF_NET:
                /* Network interface */
                rtn = PduR_If_Transmit( groupPtr->portId, &txIPdu );
                break;

            case COM_IF_DIAG:
                /* Diagnostic interface */
                /* TODO */
                break;
            /* Invalid interface */
            default:
                LOG_ERROR(COM_IF_INVALID);
                break;
        }
    }
    return rtn;
}


/*
*  Function Name   : COM_ReadGroup
*  Model Reference :
*  Description     : Reads the specified group data into the passed pointer.
*/

void COM_ReadGroup( const uint16_t i, uint8_t* const data )
{
    if( i >= COM_GROUP_COUNT )
    {
        LOG_ERROR(COM_GROUP_INVALID);
    }
    else
    {
        OS_CRITICAL_START( COM_STACK_SPINLOCK );

        /* Copy group data from the groupDataPtr */
        M_MEM_CPY_U8( COM_GroupCfgDB[i].groupDataPtr, data, COM_GroupCfgDB[i].length );

        OS_CRITICAL_STOP( COM_STACK_SPINLOCK );
    }
}

/*
*  Function Name   : COM_UpdateGroup
*  Model Reference :
*  Description     : Writes data to the specified group
*/

void COM_UpdateGroup( const uint16_t i, const uint8_t* const data )
{
    if( i >= (uint16_t)COM_GROUP_COUNT )
    {
        LOG_ERROR(COM_GROUP_INVALID);
    }
    else
    {
        OS_CRITICAL_START( COM_STACK_SPINLOCK );

        /* Copy the group data into the groupDataPtr */
        M_MEM_CPY_U8(  data,  COM_GroupCfgDB[i].groupDataPtr,  COM_GroupCfgDB[i].length);

        OS_CRITICAL_STOP( COM_STACK_SPINLOCK );
    }
}


/*
*  Function Name   : COM_GetSignal
*  Model Reference :
*  Description     : Reads the signal data from the communication group data groupDataPtr
*/

Std_ReturnType COM_GetSignal( const uint16_t signal_index, void* const data )
{
    uint8_t i, byteIndex;
    uint8_t groupIdx;
    uint32_t temp = 0UL;
    uint16_t signalDataSizeInBytes;
    Std_ReturnType rtn = E_NOT_OK;

    COM_signalDataCfg_t * sigDataPtr = &COM_SignalData[signal_index];
    const COM_signalCfg_t * sigCfgPtr = &COM_SignalCfgDB[signal_index];

    /* Get the group */
    if( signal_index >= (uint16_t)COM_SIGNAL_COUNT )
    {
        LOG_ERROR(COM_SIGNAL_INVALID);
    }
    else if( sigCfgPtr->groupIdx >= (uint8_t)COM_GROUP_COUNT )
    {
        LOG_ERROR(COM_GROUP_INVALID);
    }
    else
    {
        /* Get the corresponding group index */
        groupIdx = sigCfgPtr->groupIdx;

        OS_CRITICAL_START( COM_STACK_SPINLOCK );

        signalDataSizeInBytes = (sigDataPtr->msbyte - sigDataPtr->lsbyte)+1U;

        /* Extract all signal data from the Group Data buffer */
        byteIndex = sigDataPtr->msbyte;
        for( i = 0    ; i < sigDataPtr->spread; i++ )
        {
            temp <<= 8;
            temp |= COM_GroupCfgDB[groupIdx].groupDataPtr[byteIndex];
            byteIndex--;
        }

        OS_CRITICAL_STOP( COM_STACK_SPINLOCK );

        /* Mask and offset the signal-occupied bytes */
        temp >>= sigDataPtr->lsbyte_lsb;
        temp &= sigDataPtr->data_mask;

        /* Divide the data by the configured factor */
        temp /= sigCfgPtr->factor;

        /* Subtract the configured offset from the data */
        temp -= sigCfgPtr->offset;

        /* Copy the data to the destination address */
        M_MEM_CPY_U8( &temp,  data,  signalDataSizeInBytes );

        rtn= E_OK;
    }
    return rtn;
}


/*
*  Function Name   : COM_SendSignal
*  Model Reference :
*  Description     : Writes the signal to the associated communications group
*                    data groupDataPtr.
*/

Std_ReturnType COM_SendSignal( const uint16_t signal_index, uint32_t data )
{
    uint8_t i;
    int16_t offset_n;
    uint32_t data_n;
    uint32_t buf_mask_n;
    uint8_t groupIdx;
    Std_ReturnType rtn = E_NOT_OK;

    COM_signalDataCfg_t * sigDataPtr = &COM_SignalData[signal_index];
    const COM_signalCfg_t * sigCfgPtr = &COM_SignalCfgDB[signal_index];

    /* Get the group associated with the signal */
    groupIdx = sigCfgPtr->groupIdx;

    if( ( signal_index >= (uint16_t)COM_SIGNAL_COUNT ) ||
        ( sigDataPtr->msbyte >= COM_GroupCfgDB[groupIdx].length ))
    {
        LOG_ERROR(COM_SIGNAL_CONFIG_INVALID);
    }
    else if( ( sigCfgPtr->groupIdx >= (uint8_t)COM_GROUP_COUNT ) ||
             ( sigCfgPtr->factor == 0U ) )
    {
        LOG_ERROR(COM_GROUP_CONFIG_INVALID);
    }
    else
    {

        /* Multiply the data by the scaling factor */
        data *= sigCfgPtr->factor;

        /* Add the configured offset to the data */
        data += sigCfgPtr->offset;

        /* Saturate to the max possible value of the configured length  */
        if( data > sigDataPtr->max )
        {
            data = sigDataPtr->max;
        }

        OS_CRITICAL_START( COM_STACK_SPINLOCK );

        /* Insert the signal data into the groupDataPtr */
        for( i = sigDataPtr->lsbyte; i <= sigDataPtr->msbyte; i++ )
        {
            /* Evaluate the bit offset  */
            offset_n = sigCfgPtr->start - ( i << 3 );

            /* Setup the data and mask  */
            if( offset_n < 0 )
            {
                data_n = data >> -offset_n;
                buf_mask_n = sigDataPtr->data_mask >> -offset_n;
            }
            else
            {
                data_n = data << offset_n;
                buf_mask_n = sigDataPtr->data_mask << offset_n;
            }

            /* Copy the data to the groupDataPtr */
            COM_GroupCfgDB[groupIdx].groupDataPtr[i] &= ~((uint8_t)buf_mask_n);
            COM_GroupCfgDB[groupIdx].groupDataPtr[i] |= (uint8_t)data_n;

            OS_CRITICAL_STOP( COM_STACK_SPINLOCK );

            if( COM_GroupCfgDB[groupIdx].interval == COM_SEND_TRIGGER )
            {
                /* Trigger sending of associated communication group */
                rtn = COM_SendGroup( groupIdx );
            }
            else
            {
                /* Signal will be sent in the next scheduled interval */
                rtn = E_OK;
            }
        }
    }
    return rtn;
}


/*
*  Function Name   : COM_Initialise
*  Model Reference :
*  Description     : Looks-up the table index of the group associated with the network port identifier  portId.
*                    Walks the group configuration table until the first matching entry is found. If no entry exists, a value of -1
*                    is returned.
*/
static uint16_t COM_LookupGroupByPortId( uint16_t portId )
{
    uint16_t i;

    for( i=0; i < COM_GROUP_COUNT && ( COM_GroupCfgDB[i].portId != portId ); i++ )
    {
        /* Loop until valid port id match is found */
    }
    return i;
}



/* Component Initialisation Function Definitions */



/*
*  Function Name   : COM_Initialise
*  Model Reference :
*  Description     : Initialise all Communication Groups and their constituent
*                    signals
*/
void COM_Initialise( void )
{
    uint16_t i;


    COM_GroupDataBufferFreeBytes = COM_GROUP_DATA_BUFFER_SIZE;
    /* Clear the communications PDU data groupDataPtr */
    for( i = 0U; i < COM_GROUP_DATA_BUFFER_SIZE; i++ )
    {
        COM_GroupDataBuffer[i]=0U;
    }

    /* Initialise all communication groups */
    COM_InitGroups();

    /* Initialise all signals */
    for( i = 0U; i < COM_SIGNAL_COUNT; i++ )
    {
        COM_InitSignal( i );
    }
    COM_Initialised = TRUE;

    /*  Initialise error log */
    for( i = 0U; i < ERROR_TYPE_COUNT; i++ )
    {
        COM_StackErrorLog[i]=0U;
    }

#if  COM_STACK_TEST  == 1U
    COM_TestInitialise();

#endif
}
