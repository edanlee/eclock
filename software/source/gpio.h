#ifndef _GPIO_H_
#define _GPIO_H_

//数码管引脚定义   
#define SEG_DAT          P2              //数据端口
#define SEG_CS_PORT      P3              //位选端口
sbit SEG_BIT_0           = P3^0;         //位选端口0
sbit SEG_BIT_1           = P3^1; 
sbit SEG_BIT_2           = P3^2; 
sbit SEG_BIT_3           = P3^3; 
sbit SEG_BIT_4           = P3^4; 
sbit SEG_BIT_5           = P3^5; 

//按键引脚定义
sbit PIN_KEY_ESC         = P1^0;
sbit PIN_KEY_UP          = P1^1;
sbit PIN_KEY_DOWN        = P1^2;
sbit PIN_KEY_OK          = P1^3;

//i2c引脚定义 
sbit I2C_SCL             = P1^6;
sbit I2C_SDA             = P1^6;

#endif
