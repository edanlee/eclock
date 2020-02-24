#include "include.h"
#include "test.h"


/*===============================================================================
** ������:    TestTimer
** ��   ��: none
** ��   ��: none
** ��   ��: ���Զ�ʱ�� 
=================================================================================*/
#ifdef TEST_TIMER
void TestTimer(void)
{
    while(1)
    {
        if(!TimeIsUp(T_TEST))
            continue;
        SetSoftTimer(T_TEST, MS_500);
        SEG_BIT_0 ^= 1;
    }
}
#endif

/*===============================================================================
** ������:    TEST_SEG
** ��   ��: none
** ��   ��: none
** ��   ��: ���������
=================================================================================*/

#ifdef TEST_SEG
void TestSeg(void)
{
    u8 i,flag = 0;
    
    
    while(1)
    {
        SegScan();
        if(TimeIsUp(T_TEST))
        {
            SetSoftTimer(T_TEST, S_1);
            if(++flag & 0x01)
            {
                for(i = 0; i < 6; i++)
                {
                    SetSegDat(i,i,true);
                }
            }
            else
            {
                i = 0;
                while(i < 6)
                {
                    SetSegDat(i++,SEG_BLAND,false);
                }
            }
        }
    }
}

#endif

/*===============================================================================
** ������:    TestPro
** ��   ��: none
** ��   ��: none
** ��   ��: ���Գ��򣬲��Ը�������ģ�� 
=================================================================================*/
void TestPro(void)
{
    #ifdef TEST_TIMER
    TestTimer();
    #endif

    #ifdef TEST_SEG
    TestSeg();
    #endif
}
