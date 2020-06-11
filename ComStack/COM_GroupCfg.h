/*
 ===============================================================================
 Name        :  COM_GroupCfg.h
 Author      :  Maulik Patel
 Version     :
 Description :  COM Group Configuration H file
                This file is part of Autosar ComStack Project
 ===============================================================================
 */


#ifndef _COM_GROUPCFG_
#define _COM_GROUPCFG_


/*  Communication Group Configuration */


/* "#define group_name      ( port_id, length, interval, interface, ptr_dataBuffer )"
 *
 *    group_name       Name of the group
 *    port_id          Network port id
 *    size             Size of Group (in bytes)
 *    interval         Send/receive interval
 *    interface        Communication interface type for the group
 *    ptr_dataBuffer   Always NULL in config, will be set at run time
 *
 */


#define COM_GROUP_COUNT             10

/*    group_name      { port_id, length, interval, interface, ptr_dataBuffer ) */
/* Main Micro Tx (Master) -> our Slave Micro Rx (Slave) */
#define COM_GROUP0   { 10U,    3U,   10U,                COM_IF_NET, NULL}  /* Rx 1  */
#define COM_GROUP1   { 20U,    8U,   COM_GROUP_DISABLED, COM_IF_NET, NULL}  /* Rx  2 */
#define COM_GROUP2   { 30U,    4U,   10U,                COM_IF_NET, NULL}  /* Rx  3 */
#define COM_GROUP3   { 40U,    2U,   10U,                COM_IF_NET, NULL}  /* Rx  4 */
#define COM_GROUP4   { 50U,    8U,   10U,                COM_IF_NET, NULL}  /* Rx  5 */


/* our Slave Micro Tx (Slave) -> Main Micro Rx (Master) ->  */
#define COM_GROUP5  { 110U,    8U,   COM_GROUP_DISABLED, COM_IF_NET, NULL}   /* Tx  6 */
#define COM_GROUP6  { 120U,    2U,   10U,	              COM_IF_NET, NULL}  /* Tx  7 */
#define COM_GROUP7  { 130U,    8U,   10U,	              COM_IF_NET, NULL}  /* Tx  8 */
#define COM_GROUP8  { 140U,    8U,   10U,	              COM_IF_NET, NULL}  /* Tx  9 */
#define COM_GROUP9  { 150U,    3U,   10U,	              COM_IF_NET, NULL}  /* Tx  10 */



#endif /* COM_GROUPCFG */
