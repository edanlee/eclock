/* Main.c file generated by New Project wizard
 *
 * Created:   周一 二月 24 2020
 * Processor: 80C52
 * Compiler:  Keil for 8051
 */

#include <reg52.h>
#include <stdio.h>
#include "include.h"
#include "test.h"
void main(void)
{ 
    timer1Init();       //定时器初始化
    TestPro();          //功能测试程序
    while (1)
    {
              
    }
 }