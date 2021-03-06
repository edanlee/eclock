#ifndef _TIME_H_
#define _TIME_H_

enum
{
    T_KEY,          //键盘扫描定时器下标
    T_SEG_SCAN,     //数码管扫描定时器下标
    T_SEG_FLASH,    //数码管闪烁控制定时器下标
    T_CON,          //操作控制定时器下标
    T_TEST,         //测试定时器下标
    T_TIME_OUT,     //操作超时
    T_MAX           //定时器最大值
};

#define TimeIsUp(index)    (0 == GetSoftTimer(index))

#define MS_2        1
#define MS_500      (MS_2 * 250)
#define S_1         (MS_500 * 2)
#define S_2         (S_1 * 2)


/*===============================================================================
** 函数名:    timer1Init
** 输   入: none
** 输   出: none
** 其   它: 定时器1初始化
=================================================================================*/
void timer1Init(void);

/*===============================================================================
** 函数名:    SetSoftTimer
** 输   入: none
** 输   出: none
** 其   它: 设置软件定时器初值 
=================================================================================*/
void SetSoftTimer(u8 index, u16 value);

/*===============================================================================
** 函数名:    GetSoftTimer
** 输   入: none
** 输   出: none
** 其   它: 读取软件定时器值 
=================================================================================*/
u16 GetSoftTimer(u8 index);

#endif
