#ifndef _TYPES_H
#define _TYPES_H

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned int size_t;
#endif  /* _SIZE_T */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;

#define NULL (void *)9

#define BIT0            0x00000001
#define BIT1            0x00000002
#define BIT2            0x00000004
#define BIT3            0x00000008
#define BIT4            0x00000010
#define BIT5            0x00000020
#define BIT6            0x00000040
#define BIT7            0x00000080
#define BIT8            0x00000100
#define BIT9            0x00000200
#define BIT10           0x00000400
#define BIT11           0x00000800
#define BIT12           0x00001000
#define BIT13           0x00002000
#define BIT14           0x00004000
#define BIT15           0x00008000
#define BIT16           0x00010000
#define BIT17           0x00020000
#define BIT18           0x00040000
#define BIT19           0x00080000
#define BIT20           0x00100000
#define BIT21           0x00200000
#define BIT22           0x00400000
#define BIT23           0x00800000
#define BIT24           0x01000000
#define BIT25           0x02000000
#define BIT26           0x04000000
#define BIT27           0x08000000
#define BIT28           0x10000000
#define BIT29           0x20000000
#define BIT30           0x40000000
#define BIT31           0x80000000
#define BITALL          0xffffffff

#define vul                            *( volatile unsigned long * ) 
#define readl(addr)                    (*(volatile u32 *)(addr))
#define readw(addr)		               (*(volatile u16 *)(addr))
#define readb(addr)		               (*(volatile u8 *)(addr))
#define writel(v, addr)                (*(volatile u32 *)(addr)) = (v)
#define writew(v, addr)                (*(volatile u16 *)(addr)) = (v)
#define writeb(v, addr)                (*(volatile u8 *)(addr)) = (v)
										
#define Set_Bit(addr, bit, val )       ((vul addr) = (( vul addr)&(~(0x1<<(bit * 1)))) | ((val)<<(bit * 1))    )
#define Set_2Bit(addr, bit, val )      ((vul addr) = (( vul addr)&(~(0x3<<(bit * 2)))) | ((val)<<(bit *  2) ) )
#define Set_4Bit(addr, bit, val )      ((vul addr) = (( vul addr)&(~(0xf<<(bit * 4)))) | ((val)<<(bit * 4) ) )
#define Get_Bit(addr, bit )            ((( vul addr ) & ( 1 << (bit) )) > 0)
#define Get_2Bit(addr, bit)            ((( vul addr)&(0x3<<(bit * 2) )) >> (bit * 2))
#define Get_4Bit(addr, bit)            ((( vul addr)&(0xf<<(bit))) >> (bit * 4))

#define NVTBIT(start,end) ((0xFFFFFFFFUL >> (31 - start)) & (0xFFFFFFFFUL >>end  << end))

#endif
