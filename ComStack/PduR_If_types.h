/*
 ===============================================================================
 Name        :  PduR_If_types.h
 Author      :  Maulik Patel
 Version     :
 Description :  PDU Router Interface Types H file
                This file is part of Autosar ComStack Project
 ===============================================================================
 */


#ifndef _PDUR_IF_TYPES_
#define _PDUR_IF_TYPES_



typedef enum
{
    PDUR_IF_CAN,          			/* Can network interface */
    PDUR_IF_TYPE_COUNT       /* pduR interface type count */
} PduR_If_t;

typedef struct
{
    uint16_t id;                 /* port id */
    PduR_If_t interface;    /* pduR interface type */
    uint16_t txPduId;            /* Transmit pdu id */
    uint16_t rxPduId;            /* Receive pdu id */
} PduR_If_portConfig_t;


#endif /* _COM_TYPES_H_ */
