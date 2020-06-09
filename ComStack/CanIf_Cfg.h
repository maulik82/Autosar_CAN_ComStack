/*
 ===============================================================================
 Name        :  CanIf_Cfg.h
 Author      :  Maulik Patel
 Version     :
 Description :  Can Interface Configuration H file
                This file is part of Autosar ComStack Project
 ===============================================================================
 */



#ifndef _CANIF_CFG_H_
#define _CANIF_CFG_H_

#include "CanDrv.h"


/* Component Macro Definitions */

#define CANIF_DEFAULT_BYTE_STUFF_VALUE 0x00


#define CANIF_CAN_DEFAULT  CAN0


#define CANIF_NUM_TX_OBJECTS (5U)
#define CANIF_NUM_RX_OBJECTS (5U)


/*  RX MESSAGES */

#define CANIF_RX0_MSG_NUM    CANDRV_MSG0
#define CANIF_RX0_MSG_ID     0x1
#define CANIF_RX0_LENGTH     0x3

#define CANIF_RX1_MSG_NUM    CANDRV_MSG1
#define CANIF_RX1_MSG_ID     0x2
#define CANIF_RX1_LENGTH     0x8

#define CANIF_RX2_MSG_NUM    CANDRV_MSG2
#define CANIF_RX2_MSG_ID     0x3
#define CANIF_RX2_LENGTH     0x4

#define CANIF_RX3_MSG_NUM    CANDRV_MSG3
#define CANIF_RX3_MSG_ID     0x4
#define CANIF_RX3_LENGTH     0x2

#define CANIF_RX4_MSG_NUM    CANDRV_MSG4
#define CANIF_RX4_MSG_ID     0x5
#define CANIF_RX4_LENGTH     0x8



/*  TX MESSAGES */

#define CANIF_TX0_MSG_NUM    CANDRV_MSG10
#define CANIF_TX0_MSG_ID     0x0A
#define CANIF_TX0_LENGTH     0x8

#define CANIF_TX1_MSG_NUM    CANDRV_MSG11
#define CANIF_TX1_MSG_ID     0x0B
#define CANIF_TX1_LENGTH     0x8

#define CANIF_TX2_MSG_NUM    CANDRV_MSG12
#define CANIF_TX2_MSG_ID     0x0C
#define CANIF_TX2_LENGTH     0x8

#define CANIF_TX3_MSG_NUM    CANDRV_MSG13
#define CANIF_TX3_MSG_ID     0x0D
#define CANIF_TX3_LENGTH     0x8

#define CANIF_TX4_MSG_NUM    CANDRV_MSG14
#define CANIF_TX4_MSG_ID     0x0E
#define CANIF_TX4_LENGTH     0x8



#endif /* CANIF_CFG_H */
