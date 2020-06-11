/*
 ===============================================================================
 Name        :  Com.h
 Author      :  Maulik Patel
 Version     :
 Description :  Communication Header file
                This file is part of Autosar ComStack Project
 ===============================================================================
 */


#ifndef _COM_H_
#define _COM_H_


#include "COM_SignalCfg.h"
#include "COM_GroupCfg.h"
#include "COM_types.h"


/* Component Macro Definitions */
#define COM_STACK_SPINLOCK          /* Spinlock associated with COM stack */

#define COM_PORT_INVALID            0xFFFFU
#define COM_GROUP_DISABLED          0xFFFFU
#define COM_GROUP_BYTE_STUFF_VALUE  0U
#define COM_SEND_TRIGGER            0U
#define COM_TICK_PERIOD             5U
#define COM_TICK_PERIOD_MAX         60000U
#define COM_TXBUF_LEN               50U
#define COM_STDFRAME_DATALEN        8U
#define COM_FD_FRAME_DATALEN        64U

#define COM_FD_FUNC                 0U
#if COM_FD_FUNC == 1
#define COM_FRAME_LEN               COM_FD_FRAME_DATALEN
#else
#define COM_FRAME_LEN               COM_STDFRAME_DATALEN
#endif

/* Total Group data length in bytes for COMMS */
#define COM_GROUP_DATA_BUFFER_SIZE  ( COM_FRAME_LEN * COM_GROUP_COUNT )

#define COM_MAX_SIGNAL_LENGTH_BYTES (4U)

#define COM_TICK_INTERVAL           10U
#define COM_NEVER_SEND              0xFFFFU
#define COM_TRIGGER_SEND            0U
#define COM_MAX_INTERVAL_TICKS      60000UL
#define COM_TXBUF_LEN               50U

#define LOG_ERROR(type) COM_StackErrorLog[type]++

extern void COM_Scheduler( void );
extern void COM_NetRxCallback( const uint16_t portId, const pdu_t* const pdu );
extern void COM_NetTxCallback( const uint16_t portId );
extern Std_ReturnType COM_SendGroup( const uint16_t i );
extern void COM_ReadGroup( const uint16_t i, uint8_t* const data );
extern void COM_UpdateGroup( const uint16_t i, const uint8_t* const data );
extern Std_ReturnType COM_GetSignal( const uint16_t signal_index, void* const data );
extern Std_ReturnType COM_SendSignal( const uint16_t signal_index, uint32_t data );
extern void COM_Initialise( void );


#endif /*COM_H */
