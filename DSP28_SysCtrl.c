
/****************************************************************************
*
*�ļ�����DSP28_SysCtrl.c
*
*��  �ܣ���2812��ϵͳ����ģ����г�ʼ��
*
*��  ��: likyo from hellodsp
*
****************************************************************************/

#include "DSP28_Device.h"

/****************************************************************************
*
*��    �ƣ�InitSysCtrl()
*
*��    �ܣ��ú�����2812��ϵͳ���ƼĴ������г�ʼ��
*
*��ڲ�������
*
*���ڲ�������
*
****************************************************************************/

void InitSysCtrl(void)
{
   Uint16 i;
   EALLOW;
// On TMX samples, to get the best performance of on chip RAM blocks M0/M1/L0/L1/H0 internal
// control registers bit have to be enabled. The bits are in Device emulation registers.
   DevEmuRegs.M0RAMDFT = 0x0300;
   DevEmuRegs.M1RAMDFT = 0x0300;
   DevEmuRegs.L0RAMDFT = 0x0300;
   DevEmuRegs.L1RAMDFT = 0x0300;
   DevEmuRegs.H0RAMDFT = 0x0300;
   
           
// Disable watchdog module
   SysCtrlRegs.WDCR= 0x0068;

// Initalize PLL
   SysCtrlRegs.PLLCR = 0xA;
   // Wait for PLL to lock
   for(i= 0; i< 5000; i++){}
       
// HISPCP/LOSPCP prescale register settings, normally it will be set to default values
   SysCtrlRegs.HISPCP.all = 0x0001;
   SysCtrlRegs.LOSPCP.all = 0x0002;	
// Peripheral clock enables set for the selected peripherals.   
   SysCtrlRegs.PCLKCR.bit.EVAENCLK=1;
   SysCtrlRegs.PCLKCR.bit.EVBENCLK=1;
   SysCtrlRegs.PCLKCR.bit.SCIENCLKA=1;
// SysCtrlRegs.PCLKCR.bit.SCIENCLKB=1;
		
   		
   EDIS;
	
}

/****************************************************************************
*
*��    �ƣ�KickDog()
*
*��    �ܣ�ι����������ʹ�ÿ��Ź���ʱ��Ϊ�˷�ֹ���Ź��������Ҫ���ϵĸ�����
*          ��"ιʳ"�������Ź���Կ�Ĵ��������Ե�д��0x55+0xAA���У�������Ź�
*          �������Ĵ�����ֵ
*
*��ڲ�������
*
*���ڲ�������
*
****************************************************************************/


void KickDog(void)
{
    EALLOW;
    SysCtrlRegs.WDKEY = 0x0055;
    SysCtrlRegs.WDKEY = 0x00AA;
    EDIS;
}

//===========================================================================
// No more.
//===========================================================================
