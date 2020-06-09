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



/* Component Macro Definitions */


/* NONE */


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


#define COM_GROUP_COUNT             31

/*    group_name      { port_id, length, interval, interface, ptr_dataBuffer ) */
/* Main Micro Tx (Master) -> our Slave Micro Rx (Slave) */
#define COM_GROUP0   { 10U,    3U,   10U,                COM_IF_NET, NULL}  /* Rx SAC 1*/
#define COM_GROUP1   { 20U,    8U,   COM_GROUP_DISABLED, COM_IF_NET, NULL}  /* Rx SAC 2    CCP/XCP DTO - TBC */
#define COM_GROUP2   { 30U,    4U,   10U,                COM_IF_NET, NULL}  /* Rx SAC 3*/
#define COM_GROUP3   { 40U,    2U,   10U,                COM_IF_NET, NULL}  /* Rx SAC 4*/
#define COM_GROUP4   { 50U,    8U,   10U,                COM_IF_NET, NULL}  /* Rx SAC 5*/
#define COM_GROUP5   { 60U,    8U,   COM_GROUP_DISABLED, COM_IF_NET, NULL}  /* Rx SAC 6 - TBC */
#define COM_GROUP6   { 70U,    8U,   COM_GROUP_DISABLED, COM_IF_NET, NULL}  /* Rx SAC 7 - TBC */
#define COM_GROUP7   { 80U,    8U,   COM_GROUP_DISABLED, COM_IF_NET, NULL}  /* Rx SAC 8 - TBC */
#define COM_GROUP8   { 90U,    8U,   COM_GROUP_DISABLED, COM_IF_NET, NULL}  /* Rx SAC 9 - TBC */


/* our Slave Micro Tx (Slave) -> Main Micro Rx (Master) ->  */
#define COM_GROUP9   { 100U,    4U,   10U,                COM_IF_NET, NULL}  /* Tx SAC 10*/
#define COM_GROUP10  { 110U,    8U,   COM_GROUP_DISABLED, COM_IF_NET, NULL}  /* Tx SAC 11    CCP/XCP DTO - TBC */
#define COM_GROUP11  { 120U,    2U,   10U,	              COM_IF_NET, NULL}  /* Tx SAC 12*/
#define COM_GROUP12  { 130U,    8U,   10U,	              COM_IF_NET, NULL}  /* Tx SAC 13*/
#define COM_GROUP13  { 140U,    8U,   10U,	              COM_IF_NET, NULL}  /* Tx SAC 14*/
#define COM_GROUP14  { 150U,    3U,   10U,	              COM_IF_NET, NULL}  /* Tx SAC 15*/
#define COM_GROUP15  { 160U,    8U,   10U,	              COM_IF_NET, NULL}  /* Tx SAC 16*/
#define COM_GROUP16  { 170U,    8U,   10U,	              COM_IF_NET, NULL}  /* Tx SAC 17*/
#define COM_GROUP17  { 180U,    8U,   10U,	              COM_IF_NET, NULL}  /* Tx SAC 18*/
#define COM_GROUP18  { 190U,    8U,   10U,	              COM_IF_NET, NULL}  /* Tx SAC 19*/
#define COM_GROUP19  { 200U,    4U,   10U,	              COM_IF_NET, NULL}  /* Tx SAC 20*/
#define COM_GROUP20  { 210U,    8U,   10U,	              COM_IF_NET, NULL}  /* Tx SAC 21*/
#define COM_GROUP21  { 220U,    8U,   10U,	              COM_IF_NET, NULL}  /* Tx SAC 22*/
#define COM_GROUP22  { 230U,    8U,   10U,	              COM_IF_NET, NULL}  /* Tx SAC 23*/
#define COM_GROUP23  { 240U,    8U,   10U,	              COM_IF_NET, NULL}  /* Tx SAC 24*/
#define COM_GROUP24  { 250U,    4U,   10U,	              COM_IF_NET, NULL}  /* Tx SAC 25*/
#define COM_GROUP25  { 260U,    8U,   10U,	              COM_IF_NET, NULL}  /* Tx SAC 26*/
#define COM_GROUP26  { 270U,    8U,   10U,	              COM_IF_NET, NULL}  /* Tx SAC 27*/
#define COM_GROUP27  { 280U,    8U,   10U,	              COM_IF_NET, NULL}  /* Tx SAC 28*/
#define COM_GROUP28  { 290U,    8U,   10U,	              COM_IF_NET, NULL}  /* Tx SAC 29*/
#define COM_GROUP29  { 300U,    4U,   10U,	              COM_IF_NET, NULL}  /* Tx SAC 30*/
#define COM_GROUP30  { 310U,    2U,  100U,	              COM_IF_NET, NULL}  /* Tx SAC 31*/



#endif /* COM_GROUPCFG */
