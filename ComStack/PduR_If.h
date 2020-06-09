/*
 ===============================================================================
 Name        :  PduR_If.h
 Author      :  Maulik Patel
 Version     :
 Description :  PDU Router Interface H file
                This file is part of Autosar ComStack Project
 ===============================================================================
 */



#ifndef _PDUR_IF_H_
#define _PDUR_IF_H_

#include "PduR_If_Cfg.h"
#include "CanIf.h"
#include "Com.h"
#include "PduR_If_types.h"


#define PDUIF_PORT_INVALID COM_PORT_INVALID

extern COM_StackError_t COM_StackErrorLog[ERROR_TYPE_COUNT];


extern void PduR_If_Initialise( void );
extern Std_ReturnType PduR_If_Transmit( uint16_t portId, const pdu_t* const Ipdu );
extern void PduR_If_CanRxIndication( uint16_t rxPduId, const pdu_t* const Ipdu );
extern void PduR_If_CanTxIndication( uint16_t txPduId  );


#endif /*PDUR_IF_H*/
