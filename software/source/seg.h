#ifndef _SEG_H_
#define _SEG_H_

#define SEG_SIZE 6      //六位数码管

#define SEG_A   (1 << 0)
#define SEG_B   (1 << 1)
#define SEG_C   (1 << 2)
#define SEG_D   (1 << 3)
#define SEG_E   (1 << 4)
#define SEG_F   (1 << 5)
#define SEG_G   (1 << 6)
#define SEG_DP  (1 << 7)

#define SEG_OFF()        SEG_CS_PORT = 0xFF    //关闭数码管显示
#define SEG_SET_CS(ch)   SEG_CS_PORT = ch      //写片选
#define SEG_WRITE_DAT(x) SEG_DAT = x           //写数码数据

#define SEG_FIRST    0
#define SEG_SECOND   1
#define SEG_THIRD    2
#define SEG_FOUR     3
#define SEG_FIVE     4
#define SEG_SIX      5

#define SEG_BLAND    10                        //显空编码下标

/*===============================================================================
** 函数名:    SegScan
** 输   入: none
** 输   出: none
** 其   它: 数码管扫描 
=================================================================================*/
void SegScan(void);

/*===============================================================================
** 函数名:    SetSegDat(u8 position, u8 dat, u8 dp)
** 输   入: position: 片选位置  dat:数字, dp：tur则亮点
** 输   出: none
** 其   它: 送数据到数码管  
=================================================================================*/
void SetSegDat(u8 position, u8 dat, u8 dp);








#endif
