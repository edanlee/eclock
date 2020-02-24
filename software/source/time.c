
#include <reg52.h>
#include "sys.h"
#include "time.h"

/*定义定时器初值,加上10是为了减了误差*/
/*中断周期2ms*/
#define TIMER1VALUE    (65536 - FOSC/12/500 + 10)  //=65530

/*软件定时器*/
u16 SoftTimer[T_MAX];

//===============================================================================
void SoftTimerPro(void);

/*===============================================================================
** 函数名:    timer1Init
** 输   入: none
** 输   出: none
** 其   它: 定时器1初始化
=================================================================================*/
void timer1Init(void)
{
    /*定时器工作在方式1，16位定时器*/
    TMOD  = 0x10;

    /*高位赋值*/
    TH1   = TIMER1VALUE >> 8;

    /*低位赋值*/
    TL1   = TIMER1VALUE;

    /*清除定时中断*/
    TF1   = 0;

    /*开启定时器1中断*/
    ET1   = 1;

    /*开启全局中断*/
    EA    = 1;

    /*启动定时器1*/
    TR1   = 1;
}


/*===============================================================================
** 函数名:    T1Interrput
** 输   入: none
** 输   出: none
** 其   它: 定时器1中断处理
=================================================================================*/
void T1Interrput(void) interrupt 3 using 1
{
    /*TF1为系统自动清除,不需要手动清除*/
    //TF1

    /*因为是不是自动重载,所以需要对定时器的初值再赋值,对TH1赋值和TL1的赋值顺序
      会影响定时精度,所以不同的赋值顺序要对应相应的修正值*/    
    /*高位赋值*/
    TH1   = TIMER1VALUE >> 8;
    /*低位赋值*/
    TL1   = TIMER1VALUE;

    //软件定时器自检
    SoftTimerPro();
}

/*===============================================================================
** 函数名:    SoftTimerPro
** 输   入: none
** 输   出: none
** 其   它: 软件定时器处理 
=================================================================================*/
void SoftTimerPro(void)
{
    u8 i;

    for(i = 0; i < T_MAX; i++)
    {
        if(0 != SoftTimer[i])
        {
            SoftTimer[i]--;
        }
    }
}

/*===============================================================================
** 函数名:    SetSoftTimer
** 输   入: none
** 输   出: none
** 其   它: 设置软件定时器初值 
=================================================================================*/
void SetSoftTimer(u8 index, u16 value)
{
    SoftTimer[index] = value;
}

/*===============================================================================
** 函数名:    GetSoftTimer
** 输   入: none
** 输   出: none
** 其   它: 读取软件定时器值 
=================================================================================*/
u16 GetSoftTimer(u8 index) 
{
    return SoftTimer[index];
}


