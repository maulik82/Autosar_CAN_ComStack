/*
 ===============================================================================
 Name        :  COM_SignalCfg.h
 Author      :  Maulik Patel
 Version     :
 Description :  COM Signal Configuration H file
                This file is part of Autosar ComStack Project
 ===============================================================================
 */


#ifndef _COM_SIGNALCFG_
#define _COM_SIGNALCFG_


/*  Communication Signal Configuration */
/*
 #define signal_name    group, start, length, offset, factor, CB Func

     * signal_name  Name of the signal
     * group:       Index of the comms group where signal resides
     * start:       Bit offset of the signal within the group
     * length:      Size of signal in bits
     * offset:      offset bias
     * factor:      Scaling factor
     * CB Func:     Callback handler associated with signal, If any

*/

#define COM_SIGNAL_COUNT            13

/*      signal_name   group, start, length, offset, factor, Callback Function */
#define COM_SIGNAL0    { 0U,   0U,  16U,  0U,  1U,  NULL } /* Rx  */
#define COM_SIGNAL1    { 0U,  16U,   1U,  0U,  1U,  NULL } /* Rx  */
#define COM_SIGNAL2    { 1U,   0U,   8U,  0U,  1U,  NULL } /* Rx  */
#define COM_SIGNAL3    { 1U,   8U,   8U,  0U,  1U,  NULL } /* Rx  */
#define COM_SIGNAL4    { 1U,  16U,   8U,  0U,  1U,  NULL } /* Rx  */
#define COM_SIGNAL5    { 1U,  24U,   8U,  0U,  1U,  NULL } /* Rx  */
#define COM_SIGNAL6    { 2U,   0U,  32U,  0U,  1U,  NULL } /* Rx  */

#define COM_SIGNAL7    { 3U,  32U,  32U,  0U,  1U,  NULL } /* Tx  */
#define COM_SIGNAL8    { 4U,   0U,  16U,  0U,  1U,  NULL } /* Tx  */
#define COM_SIGNAL9    { 4U,  16U,   8U,  0U,  1U,  NULL } /* Tx  */
#define COM_SIGNAL10   { 4U,  24U,   1U,  0U,  1U,  NULL } /* Tx  */
#define COM_SIGNAL11   { 5U,   0U,  32U,  0U,  1U,  NULL } /* Tx  */
#define COM_SIGNAL12   { 5U,  32U,  32U,  0U,  1U,  NULL } /* Tx  */



#endif /*COM_SIGNALCFG */
