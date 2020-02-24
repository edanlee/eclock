#include "include.h"

//数码管驱动

//数码管数据缓存 
u8 gSegDatbuf[SEG_SIZE];

//数码管码表
/*
 _
| |
 -
| |
 _ .
 */
const u8 segNumCode[] = {
    0xFF & ~(SEG_G | SEG_DP),             /*0*/
    SEG_B | SEG_C,                        /*1*/
    SEG_A | SEG_B | SEG_G | SEG_E | SEG_D,/*2*/
    SEG_A | SEG_B | SEG_G | SEG_C | SEG_D,/*3*/
    SEG_F | SEG_G | SEG_B | SEG_C,        /*4*/
    SEG_A | SEG_F | SEG_G | SEG_C | SEG_D,/*5*/
    SEG_F | SEG_E | SEG_D | SEG_C | SEG_G,/*6*/
    SEG_A | SEG_B | SEG_C,                /*7*/
    0xFF,                                 /*8*/
    0xFF & ~(SEG_E| SEG_D),               /*9*/
    0x00                                  /*bland*/
};



/*===============================================================================
** 函数名:    SegScan
** 输   入: none
** 输   出: none
** 其   它: 数码管扫描 
=================================================================================*/
void SegScan(void)
{
    static u8 index = 0;
    u8 cs = 0xFF & ~(0x1<< index);
    
    if(!TimeIsUp(T_SEG_SCAN))
        return;
    SetSoftTimer(T_SEG_SCAN, MS_2);
    SEG_OFF();
    SEG_WRITE_DAT(gSegDatbuf[index]);
    SEG_SET_CS(cs);
    if(++index >= SEG_SIZE)
        index = 0;
}

/*===============================================================================
** 函数名:    SetSegDat(u8 position, u8 dat, u8 dp)
** 输   入: position: 片选位置  dat:数字, dp：tur则亮点
** 输   出: none
** 其   它: 送数据到数码管  
=================================================================================*/
void SetSegDat(u8 position, u8 dat, u8 dp)
{
    if(position >= sizeof(segNumCode))
        return;
    gSegDatbuf[position] = segNumCode[dat]; //送数字信息
    if(dp)
    {
        gSegDatbuf[position] |= SEG_DP;     //点信息
    }
}