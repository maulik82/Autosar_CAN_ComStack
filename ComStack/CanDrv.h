/*
 ===============================================================================
 Name        :  CanDrv.h
 Author      :  Maulik Patel
 Version     :
 Description :  Can Driver H file
                This file is part of Autosar ComStack Project
 ===============================================================================
 */

#ifndef CANDRV_H_
#define CANDRV_H_

#include "library_types.h"


typedef enum
{
	CAN0=0,
	CAN1,
	CAN2
}CanDrv_devNum_t;


typedef enum
{
	CANIF_MASK_STD0 =0,
	CANIF_MASK_XTD
}CanDrv_idMask_t;

#define CANDRV_MSG0   0u
#define CANDRV_MSG1   1u
#define CANDRV_MSG2   2u
#define CANDRV_MSG3   3u
#define CANDRV_MSG4   4u
#define CANDRV_MSG5   5u
#define CANDRV_MSG6   6u
#define CANDRV_MSG7   7u
#define CANDRV_MSG8   8u
#define CANDRV_MSG9   9u
#define CANDRV_MSG10 10u
#define CANDRV_MSG11 11u
#define CANDRV_MSG12 12u
#define CANDRV_MSG13 13u
#define CANDRV_MSG14 14u
#define CANDRV_MSG15 15u

typedef enum
{
	CANIF_ONLY = 0,
	CAN_FD
}CanDrv_protocol_t;

typedef enum
{
	CANIF_RX = 0,
	CANIF_TX
}CanDrv_dir_t;


typedef struct
{
	uint32_t 			CAN_FD_MSG_ID;
	CanDrv_idMask_t 	MSG_ID_MASK;
	uint8_t 			MSG_DATA_LENGTH;
	uint8_t 			BYTE_STUFFING_VAL;
	CanDrv_protocol_t 	CAN_PROTOCOL;
	CanDrv_dir_t 		DIRECTION;
	uint8_t 			CALLBACK_REQ;
	uint8_t 			BAUDRATE_SWITCH_REQ;
}CANIF_MSG_TYPE;


typedef struct CANIF_OBJECT_TYPE
{
	CanDrv_devNum_t 	CAN_DEVICE_NUMBER;
	CanDrv_devNum_t 	CAN_MB_NUMBER;
	CANIF_MSG_TYPE 		CANIF_MSG_STRUCT;
}CANDRV_OBJECT_TYPE;



#endif /* CANDRV_H_ */
