/*
 ===============================================================================
 Name        :  CanIf.h
 Author      :  Maulik Patel
 Version     :
 Description :  Can Interface H file
                This file is part of Autosar ComStack Project
 ===============================================================================
 */



#ifndef _CANIF_H_
#define _CANIF_H_

#include "CanIf_Cfg.h"
#include "Com.h"


typedef  uint32_t PduIdType;

extern Std_ReturnType CanIf_Transmit( uint16_t txPduId, const pdu_t* const sPdu );
extern void CanIf_Receive(  uint32_t msgId, uint8_t * const p_l_cc_data_ptr );
extern void CanIf_Initialise( void );
extern void CanIf_TxConfirmation( PduIdType msgNum );

#endif /* CANIF_H */
