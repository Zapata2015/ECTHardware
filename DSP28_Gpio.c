
/****************************************************************************
*
*�ļ�����DSP28_Gpio.c
*
*��  �ܣ�2812ͨ�����������GPIO�ĳ�ʼ������
*
*��  ��: likyo from hellodsp
*
****************************************************************************/

#include "DSP28_Device.h"

/****************************************************************************
*
*��    �ƣ�InitGpio()
*
*��    �ܣ���ʼ��Gpio��ʹ��Gpio�����Ŵ�����֪��״̬������ȷ���书�����ض�����
*          ����ͨ��I/O�������ͨ��I/O�������뻹��������ȵȡ�
*
*��ڲ�������
*
*���ڲ�������
*
****************************************************************************/

void InitGpio(void)
{

     EALLOW;
	 
     GpioMuxRegs.GPAMUX.all=0x0000;     
     GpioMuxRegs.GPADIR.all=0xFFFF;    	// upper byte as output/low byte as input
     GpioMuxRegs.GPAQUAL.all=0x0000;	// Input qualifier disabled

// Set GPIO B port pins, configured as GPIO
// Input Qualifier =0, none
// Set bits to 1 to configure peripherals signals on the pins
     GpioMuxRegs.GPBMUX.all=0x0000; 
     GpioMuxRegs.GPBDIR.all=0xFFFF;  
     GpioMuxRegs.GPBQUAL.all=0x0000;	// Input qualifier disabled

     GpioMuxRegs.GPFMUX.all=0x0FFF; 
     GpioMuxRegs.GPFDIR.all=0xF000;  
     //GpioMuxRegs.GPFQUAL.all=0x0000;	// Input qualifier disabled

     GpioMuxRegs.GPEMUX.all=0x0000; 
     GpioMuxRegs.GPEDIR.all=0xFFFF;  
     GpioMuxRegs.GPEQUAL.all=0x0000;	// Input qualifier disabled       
     EDIS;

}	
	
//===========================================================================
// No more.
//===========================================================================
