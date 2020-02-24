#ifndef _SEG_H_
#define _SEG_H_

#define SEG_SIZE 6      //��λ�����

#define SEG_A   (1 << 0)
#define SEG_B   (1 << 1)
#define SEG_C   (1 << 2)
#define SEG_D   (1 << 3)
#define SEG_E   (1 << 4)
#define SEG_F   (1 << 5)
#define SEG_G   (1 << 6)
#define SEG_DP  (1 << 7)

#define SEG_OFF()        SEG_CS_PORT = 0xFF    //�ر��������ʾ
#define SEG_SET_CS(ch)   SEG_CS_PORT = ch      //дƬѡ
#define SEG_WRITE_DAT(x) SEG_DAT = x           //д��������

#define SEG_FIRST    0
#define SEG_SECOND   1
#define SEG_THIRD    2
#define SEG_FOUR     3
#define SEG_FIVE     4
#define SEG_SIX      5

#define SEG_BLAND    10                        //�Կձ����±�

/*===============================================================================
** ������:    SegScan
** ��   ��: none
** ��   ��: none
** ��   ��: �����ɨ�� 
=================================================================================*/
void SegScan(void);

/*===============================================================================
** ������:    SetSegDat(u8 position, u8 dat, u8 dp)
** ��   ��: position: Ƭѡλ��  dat:����, dp��tur������
** ��   ��: none
** ��   ��: �����ݵ������  
=================================================================================*/
void SetSegDat(u8 position, u8 dat, u8 dp);








#endif
