/*
 ===============================================================================
 Name        :  CanIf_Cfg.c
 Author      :  Maulik Patel
 Version     :
 Description :  Can Interface Configuration C file
                This file is part of Autosar ComStack Project
 ===============================================================================
 */

/*  Library Include Files */
#include "library_types.h"

/* Component Include Files */
#include "CanIf_Cfg.h"


/* Component Scope Variable Definitions */
const CANDRV_OBJECT_TYPE CANIF_TX0_OBJECT =
{
   CANIF_CAN_DEFAULT,                         	/* CAN_DEVICE_NUMBER */
   CANIF_TX0_MSG_NUM,                          	/* CAN_MB_NUMBER     */
   {
       CANIF_TX0_MSG_ID,                       	/* CAN_FD_MSG_ID */
       CANIF_MASK_STD0,                        	/* MSG_ID_MASK */
       CANIF_TX0_LENGTH,                       	/* MSG_DATA_LENGTH */
       CANIF_DEFAULT_BYTE_STUFF_VALUE,         	/* BYTE_STUFFING_VAL */
       CANIF_ONLY,                            	/* CAN_PROTOCOL */
       CANIF_TX,                              	/* DIRECTION */
       FALSE,                                   /* CALLBACK REQ */
       FALSE                                    /* BAUDRATE SWITCH REQ */
   }
};
const CANDRV_OBJECT_TYPE CANIF_TX1_OBJECT =
{
   CANIF_CAN_DEFAULT,                         	/* CAN_DEVICE_NUMBER */
   CANIF_TX1_MSG_NUM,                          	/* CAN_MB_NUMBER     */
   {
       CANIF_TX1_MSG_ID,                       	/* CAN_FD_MSG_ID */
       CANIF_MASK_STD0,                        	/* MSG_ID_MASK */
       CANIF_TX1_LENGTH,                       	/* MSG_DATA_LENGTH */
       CANIF_DEFAULT_BYTE_STUFF_VALUE,         	/* BYTE_STUFFING_VAL */
       CANIF_ONLY,                            	/* CAN_PROTOCOL */
       CANIF_TX,                              	/* DIRECTION */
       FALSE,                                   /* CALLBACK REQ */
       FALSE                                    /* BAUDRATE SWITCH REQ */
   }
};
const CANDRV_OBJECT_TYPE CANIF_TX2_OBJECT =
{
   CANIF_CAN_DEFAULT,                         	/* CAN_DEVICE_NUMBER */
   CANIF_TX2_MSG_NUM,                          	/* CAN_MB_NUMBER     */
   {
       CANIF_TX2_MSG_ID,                       	/* CAN_FD_MSG_ID */
       CANIF_MASK_STD0,                        	/* MSG_ID_MASK */
       CANIF_TX2_LENGTH,                       	/* MSG_DATA_LENGTH */
       CANIF_DEFAULT_BYTE_STUFF_VALUE,         	/* BYTE_STUFFING_VAL */
       CANIF_ONLY,                            	/* CAN_PROTOCOL */
       CANIF_TX,                              	/* DIRECTION */
       FALSE,                                   /* CALLBACK REQ */
       FALSE                                    /* BAUDRATE SWITCH REQ */
   }
};
const CANDRV_OBJECT_TYPE CANIF_TX3_OBJECT =
{
   CANIF_CAN_DEFAULT,                         	/* CAN_DEVICE_NUMBER */
   CANIF_TX3_MSG_NUM,                          	/* CAN_MB_NUMBER     */
   {
       CANIF_TX3_MSG_ID,                       	/* CAN_FD_MSG_ID */
       CANIF_MASK_STD0,                        	/* MSG_ID_MASK */
       CANIF_TX3_LENGTH,                       	/* MSG_DATA_LENGTH */
       CANIF_DEFAULT_BYTE_STUFF_VALUE,         	/* BYTE_STUFFING_VAL */
       CANIF_ONLY,                            	/* CAN_PROTOCOL */
       CANIF_TX,                              	/* DIRECTION */
       FALSE,                                   /* CALLBACK REQ */
       FALSE                                    /* BAUDRATE SWITCH REQ */
   }
};
const CANDRV_OBJECT_TYPE CANIF_TX4_OBJECT =
{
   CANIF_CAN_DEFAULT,                         	/* CAN_DEVICE_NUMBER */
   CANIF_TX4_MSG_NUM,                          	/* CAN_MB_NUMBER     */
   {
       CANIF_TX4_MSG_ID,                       	/* CAN_FD_MSG_ID */
       CANIF_MASK_STD0,                        	/* MSG_ID_MASK */
       CANIF_TX4_LENGTH,                       	/* MSG_DATA_LENGTH */
       CANIF_DEFAULT_BYTE_STUFF_VALUE,         	/* BYTE_STUFFING_VAL */
       CANIF_ONLY,                            	/* CAN_PROTOCOL */
       CANIF_TX,                              	/* DIRECTION */
       FALSE,                                   /* CALLBACK REQ */
       FALSE                                    /* BAUDRATE SWITCH REQ */
   }
};



const CANDRV_OBJECT_TYPE CANIF_RX0_OBJECT =
{
   CANIF_CAN_DEFAULT,                         	/* CAN_DEVICE_NUMBER */
   CANIF_RX0_MSG_NUM,                          	/* CAN_MB_NUMBER     */
   {
       CANIF_RX0_MSG_ID,                       	/* CAN_FD_MSG_ID */
       CANIF_MASK_STD0,                        	/* MSG_ID_MASK */
       CANIF_RX0_LENGTH,                       	/* MSG_DATA_LENGTH */
       CANIF_DEFAULT_BYTE_STUFF_VALUE,         	/* BYTE_STUFFING_VAL */
       CANIF_ONLY,                            	/* CAN_PROTOCOL */
       CANIF_RX,                              	/* DIRECTION */
       TRUE,                                    /* CALLBACK REQ */
       FALSE                                    /* BAUDRATE SWITCH REQ */
   }
};
const CANDRV_OBJECT_TYPE CANIF_RX1_OBJECT =
{
   CANIF_CAN_DEFAULT,                         	/* CAN_DEVICE_NUMBER */
   CANIF_RX1_MSG_NUM,                          	/* CAN_MB_NUMBER     */
   {
       CANIF_RX1_MSG_ID,                       	/* CAN_FD_MSG_ID */
       CANIF_MASK_STD0,                        	/* MSG_ID_MASK */
       CANIF_RX1_LENGTH,                       	/* MSG_DATA_LENGTH */
       CANIF_DEFAULT_BYTE_STUFF_VALUE,         	/* BYTE_STUFFING_VAL */
       CANIF_ONLY,                            	/* CAN_PROTOCOL */
       CANIF_RX,                              	/* DIRECTION */
       TRUE,                                    /* CALLBACK REQ */
       FALSE                                    /* BAUDRATE SWITCH REQ */
   }
};
const CANDRV_OBJECT_TYPE CANIF_RX2_OBJECT =
{
   CANIF_CAN_DEFAULT,                         	/* CAN_DEVICE_NUMBER */
   CANIF_RX2_MSG_NUM,                          	/* CAN_MB_NUMBER     */
   {
       CANIF_RX2_MSG_ID,                       	/* CAN_FD_MSG_ID */
       CANIF_MASK_STD0,                        	/* MSG_ID_MASK */
       CANIF_RX2_LENGTH,                       	/* MSG_DATA_LENGTH */
       CANIF_DEFAULT_BYTE_STUFF_VALUE,         	/* BYTE_STUFFING_VAL */
       CANIF_ONLY,                            	/* CAN_PROTOCOL */
       CANIF_RX,                              	/* DIRECTION */
       TRUE,                                    /* CALLBACK REQ */
       FALSE                                    /* BAUDRATE SWITCH REQ */
   }
};
const CANDRV_OBJECT_TYPE CANIF_RX3_OBJECT =
{
   CANIF_CAN_DEFAULT,                         	/* CAN_DEVICE_NUMBER */
   CANIF_RX3_MSG_NUM,                          	/* CAN_MB_NUMBER     */
   {
       CANIF_RX3_MSG_ID,                       	/* CAN_FD_MSG_ID */
       CANIF_MASK_STD0,                        	/* MSG_ID_MASK */
       CANIF_RX3_LENGTH,                       	/* MSG_DATA_LENGTH */
       CANIF_DEFAULT_BYTE_STUFF_VALUE,         	/* BYTE_STUFFING_VAL */
       CANIF_ONLY,                            	/* CAN_PROTOCOL */
       CANIF_RX,                              	/* DIRECTION */
       TRUE,                                    /* CALLBACK REQ */
       FALSE                                    /* BAUDRATE SWITCH REQ */
   }
};
const CANDRV_OBJECT_TYPE CANIF_RX4_OBJECT =
{
   CANIF_CAN_DEFAULT,                         	/* CAN_DEVICE_NUMBER */
   CANIF_RX4_MSG_NUM,                          	/* CAN_MB_NUMBER     */
   {
       CANIF_RX4_MSG_ID,                       	/* CAN_FD_MSG_ID */
       CANIF_MASK_STD0,                        	/* MSG_ID_MASK */
       CANIF_RX4_LENGTH,                       	/* MSG_DATA_LENGTH */
       CANIF_DEFAULT_BYTE_STUFF_VALUE,         	/* BYTE_STUFFING_VAL */
       CANIF_ONLY,                            	/* CAN_PROTOCOL */
       CANIF_RX,                              	/* DIRECTION */
       TRUE,                                    /* CALLBACK REQ */
       FALSE                                    /* BAUDRATE SWITCH REQ */
   }
};



const CANDRV_OBJECT_TYPE * CANIF_TX_OBJECT_TABLE[CANIF_NUM_TX_OBJECTS] =
{
    &CANIF_TX0_OBJECT,    /* txPduId = 0 */
    &CANIF_TX1_OBJECT,    /* txPduId = 1 */
    &CANIF_TX2_OBJECT,    /* txPduId = 2 */
    &CANIF_TX3_OBJECT,    /* txPduId = 3 */
    &CANIF_TX4_OBJECT,    /* txPduId = 4 */
};

const CANDRV_OBJECT_TYPE * CANIF_RX_OBJECT_TABLE[CANIF_NUM_RX_OBJECTS] =
{
    &CANIF_RX0_OBJECT,    /* rxPduId = 0 */
    &CANIF_RX1_OBJECT,    /* rxPduId = 1 */
    &CANIF_RX2_OBJECT,    /* rxPduId = 2 */
    &CANIF_RX3_OBJECT,    /* rxPduId = 3 */
    &CANIF_RX4_OBJECT,    /* rxPduId = 4 */
};
