/*
 ===============================================================================
 Name        :  library.h
 Author      :  Maulik Patel
 Version     :
 Description :  Standard library H file
                This file is part of Autosar ComStack Project
 ===============================================================================
 */

#ifndef LIBRARY_TYPES_H_
#define LIBRARY_TYPES_H_

#define NULL 			(0U)
#define TRUE 			(1U)
#define FALSE 			(0U)
/* Standard Autosar types */
#define E_OK          	(0U)
#define E_NOT_OK        (1U)

#define BIT_MASK(n,size)            (((size)1U << n ) - 1U )

typedef uint8_t Std_ReturnType;


/* CONFIG MAP UTILITY */
#define CONFIG_TABLE(x)             _CONFIG_TABLE(x, x##_COUNT)
#define _CONFIG_TABLE(x, i)         _CONFIG_TABLE_N(x, i)
#define _CONFIG_TABLE_N(x, i)       {_ENTRY##i(x)}

#define _CONFIG(name, entry)        __CONFIG(name, entry)
#define __CONFIG(name,entry)        name (entry)
#define _ENTRY(x)                   x

#define CONFIG_PARAMS(x)            { x }


#define _CONFIG0(name, entry)       _CONFIG_HASH_DECORATE(error "Invalid Configuration!")
#define _CONFIG1(name, entry)       _CONFIG(name, entry ## 0)
#define _CONFIG2(name, entry)       _CONFIG1(name, entry), _CONFIG(name, entry ## 1)
#define _CONFIG3(name, entry)       _CONFIG2(name, entry), _CONFIG(name, entry ## 2)
#define _CONFIG4(name, entry)       _CONFIG3(name, entry), _CONFIG(name, entry ## 3)
#define _CONFIG5(name, entry)       _CONFIG4(name, entry), _CONFIG(name, entry ## 4)
#define _CONFIG6(name, entry)       _CONFIG5(name, entry), _CONFIG(name, entry ## 5)
#define _CONFIG7(name, entry)       _CONFIG6(name, entry), _CONFIG(name, entry ## 6)
#define _CONFIG8(name, entry)       _CONFIG7(name, entry), _CONFIG(name, entry ## 7)
#define _CONFIG9(name, entry)       _CONFIG8(name, entry), _CONFIG(name, entry ## 8)
#define _CONFIG10(name, entry)      _CONFIG9(name, entry), _CONFIG(name, entry ## 9)
#define _CONFIG11(name, entry)      _CONFIG10(name, entry), _CONFIG(name, entry ## 10)
#define _CONFIG12(name, entry)      _CONFIG11(name, entry), _CONFIG(name, entry ## 11)
#define _CONFIG13(name, entry)      _CONFIG12(name, entry), _CONFIG(name, entry ## 12)
#define _CONFIG14(name, entry)      _CONFIG13(name, entry), _CONFIG(name, entry ## 13)
#define _CONFIG15(name, entry)      _CONFIG14(name, entry), _CONFIG(name, entry ## 14)
#define _CONFIG16(name, entry)      _CONFIG15(name, entry), _CONFIG(name, entry ## 15)
#define _CONFIG17(name, entry)      _CONFIG16(name, entry), _CONFIG(name, entry ## 16)
#define _CONFIG18(name, entry)      _CONFIG17(name, entry), _CONFIG(name, entry ## 17)
#define _CONFIG19(name, entry)      _CONFIG18(name, entry), _CONFIG(name, entry ## 18)
#define _CONFIG20(name, entry)      _CONFIG19(name, entry), _CONFIG(name, entry ## 19)
#define _CONFIG21(name, entry)      _CONFIG20(name, entry), _CONFIG(name, entry ## 20)

#define _ENTRY0(x)         _ENTRY_HASH_DECORATE(error "Invalid Configuration!")
#define _ENTRY1(x)         _ENTRY(x ## 0)
#define _ENTRY2(x)         _ENTRY1(x), _ENTRY(x ## 1)
#define _ENTRY3(x)         _ENTRY2(x), _ENTRY(x ## 2)
#define _ENTRY4(x)         _ENTRY3(x), _ENTRY(x ## 3)
#define _ENTRY5(x)         _ENTRY4(x), _ENTRY(x ## 4)
#define _ENTRY6(x)         _ENTRY5(x), _ENTRY(x ## 5)
#define _ENTRY7(x)         _ENTRY6(x), _ENTRY(x ## 6)
#define _ENTRY8(x)         _ENTRY7(x), _ENTRY(x ## 7)
#define _ENTRY9(x)         _ENTRY8(x), _ENTRY(x ## 8)
#define _ENTRY10(x)        _ENTRY9(x), _ENTRY(x ## 9)
#define _ENTRY11(x)        _ENTRY10(x), _ENTRY(x ## 10)
#define _ENTRY12(x)        _ENTRY11(x), _ENTRY(x ## 11)
#define _ENTRY13(x)        _ENTRY12(x), _ENTRY(x ## 12)
#define _ENTRY14(x)        _ENTRY13(x), _ENTRY(x ## 13)
#define _ENTRY15(x)        _ENTRY14(x), _ENTRY(x ## 14)
#define _ENTRY16(x)        _ENTRY15(x), _ENTRY(x ## 15)
#define _ENTRY17(x)        _ENTRY16(x), _ENTRY(x ## 16)
#define _ENTRY18(x)        _ENTRY17(x), _ENTRY(x ## 17)
#define _ENTRY19(x)        _ENTRY18(x), _ENTRY(x ## 18)
#define _ENTRY20(x)        _ENTRY19(x), _ENTRY(x ## 19)
#define _ENTRY21(x)        _ENTRY20(x), _ENTRY(x ## 20)
#define _ENTRY22(x)        _ENTRY21(x), _ENTRY(x ## 21)
#define _ENTRY23(x)        _ENTRY22(x), _ENTRY(x ## 22)
#define _ENTRY24(x)        _ENTRY23(x), _ENTRY(x ## 23)
#define _ENTRY25(x)        _ENTRY24(x), _ENTRY(x ## 24)
#define _ENTRY26(x)        _ENTRY25(x), _ENTRY(x ## 25)
#define _ENTRY27(x)        _ENTRY26(x), _ENTRY(x ## 26)
#define _ENTRY28(x)        _ENTRY27(x), _ENTRY(x ## 27)
#define _ENTRY29(x)        _ENTRY28(x), _ENTRY(x ## 28)
#define _ENTRY30(x)        _ENTRY29(x), _ENTRY(x ## 29)
#define _ENTRY31(x)        _ENTRY30(x), _ENTRY(x ## 30)
#define _ENTRY32(x)        _ENTRY31(x), _ENTRY(x ## 31)
#define _ENTRY33(x)        _ENTRY32(x), _ENTRY(x ## 32)
#define _ENTRY34(x)        _ENTRY33(x), _ENTRY(x ## 33)
#define _ENTRY35(x)        _ENTRY34(x), _ENTRY(x ## 34)
#define _ENTRY36(x)        _ENTRY35(x), _ENTRY(x ## 35)
#define _ENTRY37(x)        _ENTRY36(x), _ENTRY(x ## 36)
#define _ENTRY38(x)        _ENTRY37(x), _ENTRY(x ## 37)
#define _ENTRY39(x)        _ENTRY38(x), _ENTRY(x ## 38)
#define _ENTRY40(x)        _ENTRY39(x), _ENTRY(x ## 39)
#define _ENTRY41(x)        _ENTRY40(x), _ENTRY(x ## 40)
#define _ENTRY42(x)        _ENTRY41(x), _ENTRY(x ## 41)
#define _ENTRY43(x)        _ENTRY42(x), _ENTRY(x ## 42)
#define _ENTRY44(x)        _ENTRY43(x), _ENTRY(x ## 43)
#define _ENTRY45(x)        _ENTRY44(x), _ENTRY(x ## 44)
#define _ENTRY46(x)        _ENTRY45(x), _ENTRY(x ## 45)
#define _ENTRY47(x)        _ENTRY46(x), _ENTRY(x ## 46)
#define _ENTRY48(x)        _ENTRY47(x), _ENTRY(x ## 47)
#define _ENTRY49(x)        _ENTRY48(x), _ENTRY(x ## 48)
#define _ENTRY50(x)        _ENTRY49(x), _ENTRY(x ## 49)




#endif /* LIBRARY_TYPES_H_ */
