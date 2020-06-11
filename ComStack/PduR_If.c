/*
 ===============================================================================
 Name        :  PduR_If.c
 Author      :  Maulik Patel
 Version     :
 Description :  PDU Router Interface C file
                This file is part of Autosar ComStack Project
 ===============================================================================
 */


/*  Library Include Files */
#include "library_types.h"


/* Component Include Files */
#include "PduR_If.h"


/*  Task Scope Variable Definitions */
static const PduR_If_portConfig_t PduR_IfConfig[] = CONFIG_TABLE( PDUR_IF_PORT );

/*  Task Local Function Declaration */
static uint16_t PduR_If_LookupPortById( const uint16_t portId );
static uint16_t PduR_If_LookupRxPort( const PduR_If_t interface, const uint16_t rxPduId );
static uint16_t PduR_If_LookupTxPort( const PduR_If_t interface, const uint16_t txPduId );


/*
*  Function Name   : PduR_If_Transmit
*  Description     : Sends a network PDU to the specified port
*/

Std_ReturnType PduR_If_Transmit( uint16_t portId, const pdu_t* const Ipdu )
{
    uint16_t port;
    uint16_t txPduId;
    Std_ReturnType rtn = E_NOT_OK;

    /* Lookup the PDU ID for this port */
    port = PduR_If_LookupPortById( portId );

    if( port < PDUR_IF_PORT_COUNT )
    {
        /* Get the TX PDU ID for this port */
        txPduId = PduR_IfConfig[port].txPduId;

        /* Check that their is an associated TX PDU for this port */
        if( txPduId != (uint16_t)PDUR_IF_NA )
        {
            /* Route the I-pdu the appropriate interface */
            switch( PduR_IfConfig[port].interface )
            {
                /* Transmit on the CAN interface */
                case PDUR_IF_CAN:
                    rtn= CanIf_Transmit( txPduId, Ipdu );
                    break;

                default:
                    LOG_ERROR(PDUR_IF_INVALID);
                    break;
            }
        }
        else
        {
            /* This might be rx port or invalid configuration */
            /* is there an RxPdu associated with it? */
            if (PduR_IfConfig[port].rxPduId == (uint16_t)PDUR_IF_NA )
            {
                /* No rx port associated with pdu */
                LOG_ERROR(PDUR_CONFIG_INVALID);
            }
        }
    }
    else
    {
        LOG_ERROR(PDUR_PORT_INVALID);
    }
    return rtn;
}


/*
*  Function Name   : PduR_If_CanRxIndication
*  Description     : CAN RX PDU call-back handler from lower layer
*/

void PduR_If_CanRxIndication( uint16_t rxPduId, const pdu_t* const Ipdu )
{
    uint16_t portId;

    /* Lookup the port ID for this interface and RX PDU ID */
    portId = PduR_If_LookupRxPort( PDUR_IF_CAN, rxPduId );

    if( portId!= PDUIF_PORT_INVALID )
    {
        /* Pass the callback to the COMMS */
        COM_NetRxCallback( portId, Ipdu );
    }
    else
    {
        LOG_ERROR(PDUR_PORT_INVALID);
    }
}



/*
*  Function Name   : PduR_If_CanTxIndication
*  Description     : CAN TX PDU call-back handler from lower layer
*/

void PduR_If_CanTxIndication( uint16_t txPduId  )
{
    uint16_t portId;

    /* Lookup the port ID for this interface and RX PDU ID */
    portId = PduR_If_LookupTxPort( PDUR_IF_CAN, txPduId );

    if( portId!= PDUIF_PORT_INVALID )
    {
        /* Pass the callback to the COMMS */
        COM_NetTxCallback( portId );
    }
    else
    {
        LOG_ERROR(PDUR_PORT_INVALID);
    }
}


/*
*  Function Name   : PduR_If_LookupPortById
*  Description     : Returns Port index matching to port Id
*/


static uint16_t PduR_If_LookupPortById( const uint16_t portId )
{
    uint16_t i;

    for ( i=0; i < PDUR_IF_PORT_COUNT && ( PduR_IfConfig[i].id != portId ); i++ )
    {
        /* continue till matching id is found */
    }
    return i;
}


/*
*  Function Name   : PduR_If_LookupRxPort
*  Description     : Return port id matching to port index.
*/


static uint16_t PduR_If_LookupRxPort( const PduR_If_t interface, const uint16_t rxPduId )
{
    uint16_t i;
    uint16_t portId = PDUIF_PORT_INVALID;
    /* Until more interfaces are introduced, ignore this param */
    (void)interface;

    for ( i=0; i < PDUR_IF_PORT_COUNT; i++ )
    {
        /* continue till matching id is found */
        if ( PduR_IfConfig[i].rxPduId == rxPduId )
        {
            portId=  PduR_IfConfig[i].id;
            return portId;
        }

    }
    return portId;

}



/*
*  Function Name   : PduR_If_LookupTxPort
*  Description     : Return port id matching to port index.
*/


static uint16_t PduR_If_LookupTxPort( const PduR_If_t interface, const uint16_t txPduId )
{
    uint16_t i;
    uint16_t portId = PDUIF_PORT_INVALID;


    for ( i=0; i < PDUR_IF_PORT_COUNT; i++ )
    {
        /* continue till matching id is found */
        if ( PduR_IfConfig[i].txPduId == txPduId )
        {
            portId=  PduR_IfConfig[i].id;
            return portId;
        }

    }
    return portId;

}


/* Component Initialisation Function Definitions */
/*
*  Function Name   : PduR_If_Initialise
*  Description     : Initialise all the network interfaces
*/

void PduR_If_Initialise( void )
{
    uint16_t i;

    /* Initialise all port interfaces */
    for( i = 0U; i < (uint16_t)PDUR_IF_TYPE_COUNT; i++ )
    {
        switch( i )
        {
            /* CAN interface */
            case PDUR_IF_CAN:
                CanIf_Initialise();
                break;
            default:
                LOG_ERROR(PDUR_IF_INVALID);
                break;
        }
    }
}
