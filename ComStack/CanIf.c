/*
 ===============================================================================
 Name        :  CanIf.c
 Author      :  Maulik Patel
 Version     :
 Description :  Can Interface C file
                This file is part of Autosar ComStack Project
 ===============================================================================
 */

/*  Library Include Files */
#include "library_types.h"


/* Component Include Files */


#include "CanIf.h"
#include "Com.h"
#include "PduR_If.h"


/* Component Level Variables: Inputs from other Tasks */


extern const CANDRV_OBJECT_TYPE * CANIF_TX_OBJECT_TABLE[CANIF_NUM_TX_OBJECTS];
extern const CANDRV_OBJECT_TYPE * CANIF_RX_OBJECT_TABLE[CANIF_NUM_RX_OBJECTS];
extern COM_StackError_t COM_StackErrorLog[ERROR_TYPE_COUNT];


/* Component Level Variables: Outputs to other Tasks */


#ifdef CANIF_UT
volatile uint8_t TestEnable = FALSE;


const CANDRV_OBJECT_TYPE TEST_OBJECT =
{
	P_L_CAN2,                                    /* CAN_DEVICE_NUMBER */
    0x91,                          /* CAN_MB_NUMBER     */
    {
        0x91,                       /* CAN_FD_MSG_ID */
        CANIF_MASK_STD0,                        /* MSG_ID_MAS */
        0x8,                       /* MSG_DATA_LENGTH */
        CANIF_DEFAULT_BYTE_STUFF_VALUE,         /* BYTE_STUFFING_VAL */
        CANIF_ONLY,                            /* CAN_PROTOCOL */
        CANIF_STD,                             /* STD_TYPE */
        CANIF_TX,                              /* DIRECTION */
        TRUE,                                    /* CALLBACK REQ */
        FALSE                                    /* BAUDRATE SWITCH REQ */
    }
};
#endif


/*  Task Scope Variable Definitions */
static uint16_t canIf_SendError[CANIF_NUM_TX_OBJECTS];


/*  Task Local Function Prototypes */
static uint16_t CanIf_LookupRxPduId( const uint32_t msgId );
static uint16_t CanIf_LookupTxPduId( const uint32_t msgId );


/*
*  Function Name   : CanIf_Transmit
*  Model Reference :
*  Description     : Transmits the S-PDU via appropriate channel
*/


Std_ReturnType CanIf_Transmit( uint16_t txPduId, const pdu_t* const sPdu )
{
    Std_ReturnType rtn = E_NOT_OK;
    uint16_t sendError;

#ifdef CANIF_UT
	if (TestEnable)
	{
		uint8_t data[]={0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8};
		canIf_SendError = CanDrv_Send_Message( &TEST_OBJECT, data );
		TestEnable= FALSE;
	}
	else
	{
#else
    if( txPduId < CANIF_NUM_TX_OBJECTS )
    {
    	sendError= (uint16_t)CanDrv_Send_Message( CANIF_TX_OBJECT_TABLE[txPduId], sPdu->pduData );

    	if( sendError != (uint16_t)E_NOT_OK )
    	{
    		/* Log any send error for now */
    		canIf_SendError[txPduId] = sendError;
       	    LOG_ERROR(CANIF_SEND_ERROR);
    	}
    	else
    	{
    		/* TxPdu sent successfully */
    		rtn = E_OK;
    	}
    }
    else
    {
   	    LOG_ERROR(CANIF_PDU_ID_INVALID);
    }
#endif
#ifdef CANIF_UT
	}
#endif
	return rtn;
}



/*
*  Function Name   : CanIf_TxConfirmation
*  Model Reference :
*  Description     : This service confirms a previously successfully processed
*                    transmission of a CAN TxPDU.
*/

void CanIf_TxConfirmation( PduIdType msgNum )
{

	uint16_t txPduId;

	txPduId = CanIf_LookupTxPduId( msgNum );

    if( txPduId < CANIF_NUM_TX_OBJECTS )
    {
    	/* Route to network */
	    PduR_If_CanTxIndication( txPduId  );
    }
    else
    {
    	/* Pdu id invalid or could not be found in the configuration */
    	LOG_ERROR(CANIF_PDU_ID_INVALID);
    }

}


/*
*  Function Name   : CanIf_Receive
*  Model Reference :
*  Description     : Receives the  S-PDU from CAN channel
*/

void CanIf_Receive(  PduIdType msgId, uint8_t * const p_l_cc_data_ptr )
{
	uint16_t rxPduId;

	pdu_t sPdu;

	rxPduId = CanIf_LookupRxPduId( msgId );

    if( rxPduId < CANIF_NUM_RX_OBJECTS )
    {
    	/* Populate the SPDU */
    	sPdu.dataLength = CANIF_RX_OBJECT_TABLE[rxPduId]->CANIF_MSG_STRUCT.MSG_DATA_LENGTH;
    	sPdu.pduData = p_l_cc_data_ptr;
    	/* Route to network */
	    PduR_If_CanRxIndication( rxPduId, &sPdu );
    }
    else
    {
    	/* Pdu id invalid or could not be found in the configuration */
    	LOG_ERROR(CANIF_PDU_ID_INVALID);
    }
}



/*
*  Function Name   : CanIf_LookupRxPduId
*  Model Reference :
*  Description     : Returns PDU id with matching msg number
*/

static uint16_t CanIf_LookupRxPduId( const PduIdType msgId )
{
    uint16_t i;
    uint16_t pduId = 0xFFFF;

    for ( i=0; i < CANIF_NUM_RX_OBJECTS; i++ )
    {
        /* continue till matching message id is found */
        if ( CANIF_RX_OBJECT_TABLE[i]->CANIF_MSG_STRUCT.CAN_FD_MSG_ID  == msgId )
        {
            return i;
        }
    }
    return pduId;
}


/*
*  Function Name   : CanIf_LookupTxPduId
*  Model Reference :
*  Description     : Returns PDU id with matching msg number
*/

static uint16_t CanIf_LookupTxPduId( const PduIdType msgNum )
{
    uint16_t i;
    uint16_t pduId = 0xFFFF;

    for ( i=0; i < CANIF_NUM_TX_OBJECTS; i++ )
    {
        /* continue till matching message number is found */
        if ( CANIF_TX_OBJECT_TABLE[i]->CAN_MB_NUMBER  == msgNum )
        {
            return i;
        }
    }
    return pduId;
}




/*
*  Function Name   : CanIf_Initalise
*  Model Reference :
*  Description     :
*/

void CanIf_Initialise( void )
{
	uint16_t i;

	/* Initialise all Tx objects */
	for ( i=0; i < CANIF_NUM_TX_OBJECTS; i++ )
	{
		P_L_Can_Configure_Object( CANIF_TX_OBJECT_TABLE[i] ) ;
		canIf_SendError[i]=0;
	}

	/* Initialise all Rx objects */
	for ( i=0; i < CANIF_NUM_RX_OBJECTS; i++ )
	{
		P_L_Can_Configure_Object( CANIF_RX_OBJECT_TABLE[i] );
	}

#ifdef CANIF_UT
	P_L_Can_Configure_Object( &TEST_OBJECT );
#endif
}
