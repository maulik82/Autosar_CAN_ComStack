/*
 ===============================================================================
 Name        :  PduR_If_Cfg.h
 Author      :  Maulik Patel
 Version     :
 Description :  PDU Router Interface Configuration H File
                This file is part of Autosar ComStack Project
 ===============================================================================
 */



#ifndef _PDUR_IF_CFG_H_
#define _PDUR_IF_CFG_H_

/*  PDU Router Configuration */

#define PDUR_IF_NA 0xFFFF  /* Value not defined or not applicable */

#define PDUR_IF_PORT_COUNT            31

/*     Interface port  port id, interfaceType,   txPduId,     rxPduId     */
#define  PDUR_IF_PORT0  {  10U,  PDUR_IF_CAN,  PDUR_IF_NA,           0 } /*Rx    1*/
#define  PDUR_IF_PORT1  {  20U,  PDUR_IF_CAN,  PDUR_IF_NA,           1 } /*Rx    2  CCP/XCP  DTO  -  TBC  */
#define  PDUR_IF_PORT2  {  30U,  PDUR_IF_CAN,  PDUR_IF_NA,           2 } /*Rx    3*/
#define  PDUR_IF_PORT3  {  40U,  PDUR_IF_CAN,  PDUR_IF_NA,           3 } /*Rx    4*/
#define  PDUR_IF_PORT4  {  50U,  PDUR_IF_CAN,  PDUR_IF_NA,           4 } /*Rx    5*/
#define  PDUR_IF_PORT5  {  60U,  PDUR_IF_CAN,  PDUR_IF_NA,           5 } /*Rx    6  -  TBC  */
#define  PDUR_IF_PORT6  {  70U,  PDUR_IF_CAN,  PDUR_IF_NA,           6 } /*Rx    7  -  TBC  */
#define  PDUR_IF_PORT7  {  80U,  PDUR_IF_CAN,  PDUR_IF_NA,           7 } /*Rx    8  -  TBC  */
#define  PDUR_IF_PORT8  {  90U,  PDUR_IF_CAN,  PDUR_IF_NA,           8 } /*Rx    9  -  TBC  */


#define  PDUR_IF_PORT9  { 100U,  PDUR_IF_CAN,           0,  PDUR_IF_NA } /*Tx    10*/
#define  PDUR_IF_PORT10 { 110U,  PDUR_IF_CAN,           1,  PDUR_IF_NA } /*Tx    11  CCP/XCP  DTO  -  TBC  */
#define  PDUR_IF_PORT11 { 120U,  PDUR_IF_CAN,           2,  PDUR_IF_NA } /*Tx    12*/
#define  PDUR_IF_PORT12 { 130U,  PDUR_IF_CAN,           3,  PDUR_IF_NA } /*Tx    13*/
#define  PDUR_IF_PORT13 { 140U,  PDUR_IF_CAN,           4,  PDUR_IF_NA } /*Tx    14*/
#define  PDUR_IF_PORT14 { 150U,  PDUR_IF_CAN,           5,  PDUR_IF_NA } /*Tx    15*/
#define  PDUR_IF_PORT15 { 160U,  PDUR_IF_CAN,           6,  PDUR_IF_NA } /*Tx    16*/
#define  PDUR_IF_PORT16 { 170U,  PDUR_IF_CAN,           7,  PDUR_IF_NA } /*Tx    17*/
#define  PDUR_IF_PORT17 { 180U,  PDUR_IF_CAN,           8,  PDUR_IF_NA } /*Tx    18*/
#define  PDUR_IF_PORT18 { 190U,  PDUR_IF_CAN,           9,  PDUR_IF_NA } /*Tx    19*/
#define  PDUR_IF_PORT19 { 200U,  PDUR_IF_CAN,          10,  PDUR_IF_NA } /*Tx    20*/
#define  PDUR_IF_PORT20 { 210U,  PDUR_IF_CAN,          11,  PDUR_IF_NA } /*Tx    21*/
#define  PDUR_IF_PORT21 { 220U,  PDUR_IF_CAN,          12,  PDUR_IF_NA } /*Tx    22*/
#define  PDUR_IF_PORT22 { 230U,  PDUR_IF_CAN,          13,  PDUR_IF_NA } /*Tx    23*/
#define  PDUR_IF_PORT23 { 240U,  PDUR_IF_CAN,          14,  PDUR_IF_NA } /*Tx    24*/
#define  PDUR_IF_PORT24 { 250U,  PDUR_IF_CAN,          15,  PDUR_IF_NA } /*Tx    25*/
#define  PDUR_IF_PORT25 { 260U,  PDUR_IF_CAN,          16,  PDUR_IF_NA } /*Tx    26*/
#define  PDUR_IF_PORT26 { 270U,  PDUR_IF_CAN,          17,  PDUR_IF_NA } /*Tx    27*/
#define  PDUR_IF_PORT27 { 280U,  PDUR_IF_CAN,          18,  PDUR_IF_NA } /*Tx    28*/
#define  PDUR_IF_PORT28 { 290U,  PDUR_IF_CAN,          19,  PDUR_IF_NA } /*Tx    29*/
#define  PDUR_IF_PORT29 { 300U,  PDUR_IF_CAN,          20,  PDUR_IF_NA } /*Tx    30*/
#define  PDUR_IF_PORT30 { 310U,  PDUR_IF_CAN,          21,  PDUR_IF_NA } /*Tx    31*/

#endif /* PDUR_IF_CFG_H */
