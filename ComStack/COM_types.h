/*
 ===============================================================================
 Name        :  COM_types.h
 Author      :  Maulik Patel
 Version     :
 Description :  Communication Types H file
                This file is part of Autosar ComStack Project
 ===============================================================================
 */


#ifndef _COM_TYPES_H_
#define _COM_TYPES_H_



/* Communications PDU type */
typedef struct
{
    uint8_t* pduData;
    uint8_t dataLength;
} pdu_t;

/* Communication interface type */
typedef uint8_t groupData_t;
typedef uint32_t COM_StackError_t;
typedef void (* COM_SigCBHandler_t)( uint32_t* const );

typedef enum
{
    COM_IF_NET,            /* Network Interface    */
    COM_IF_DIAG,           /* Diagnostic Interface */
    COM_NUM_INTERFACE
} COM_interface_t;

/* Communication group config type */
typedef struct
{
    uint16_t portId;              	/* Network port id */
    uint16_t length;              	/* size of group (in bytes) */
    uint16_t interval;            	/* Group send/receive interval (milliseconds) */
    COM_interface_t interface; 		/* Comms. interface associated with this group */
    groupData_t * groupDataPtr;    	/* Pointer to corresponding group data */
} COM_groupCfg_t;

/* Comms. signal configuration table entry */
typedef struct
{
    uint16_t groupIdx;            	/* Index of the comms group where signal resides */
    uint16_t start;               	/* Start bit-position of the signal within the group */
    uint16_t length;              	/* Size of signal in bits  */
    int16_t offset;              	/* Signal offset bias */
    uint16_t factor;              	/* Signal Scaling factor */
    COM_SigCBHandler_t cbk_handler; /* Callback function associated with the signal */
} COM_signalCfg_t;

typedef struct
{
    uint8_t spread;              /* Signal data spread (bytes) */
    uint8_t msbyte;              /* Most-significant byte offset */
    uint8_t lsbyte;              /* Least-significant byte offset */
    uint8_t lsbyte_lsb;          /* Offset of lsb in least-significant byte */
    uint32_t max;                /* Maximum signal value */
    uint32_t data_mask;          /* Data mask */
} COM_signalDataCfg_t;

typedef enum
{
	COM_SIGNAL_CONFIG_INVALID    =  0,
	COM_SIGNAL_INVALID           =  1,
	COM_GROUP_CONFIG_INVALID     =  2,
	COM_GROUP_INVALID            =  3,
	COM_INVALID_PORTID           =  4,
	COM_IF_INVALID               =  5,
	COM_GROUP_DATA_BUFFER_OVFLW  =  6,
	PDUR_IF_INVALID              =  7,
	PDUR_PORT_INVALID            =  8,
	PDUR_CONFIG_INVALID          =  9,
	CANIF_PDU_ID_INVALID         = 10,
	CANIF_SEND_ERROR             = 11,
	ERROR_TYPE_COUNT     /* DO NOT ADD ANY ENUM AFTER THIS */
}COMMS_ErrorType;




#endif /* _COM_TYPES_H_ */
