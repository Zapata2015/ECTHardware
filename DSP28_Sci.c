
#include "DSP28_Device.h"

//---------------------------------------------------------------------------
// InitSPI: 
//---------------------------------------------------------------------------
// This function initializes the SPI(s) to a known state.
//



void InitSci(void)
{
	// Initialize SCI-A:
	
	EALLOW;
	GpioMuxRegs.GPFMUX.all = 0x0030;//ʹ��SCITXD��SCIRXD�ܽ�
	EDIS;	

   
	//SciaRegs.SCIFFTX.all = 0xE040;
	//SciaRegs.SCIFFRX.all = 0x2021;
	//SciaRegs.SCIFFCT.all = 0x0;
	
	SciaRegs.SCICTL1.bit.SWRESET=0;//��λSCI
	/* loopback   8 bit data */
	SciaRegs.SCICCR.all = 0x07;	// 1 bit stop, disable parity, idle mode, 8 bits data 
	
	SciaRegs.SCICTL1.all = 0x03; // ��дʹ�� 
	SciaRegs.SCICTL2.all = 0x03; //��д�ж�ʱ��
	
//	SciaRegs.SCIHBAUD = 0x01;//���ò�����
//	SciaRegs.SCILBAUD = 0xE7;//���ò�����  9600
	SciaRegs.SCIHBAUD = 0x00;
	SciaRegs.SCILBAUD = 0xF3; //���ò�����  19200

	
	SciaRegs.SCICTL1.all = 0x23;//ʹ��SCI��ʹ�ܷ�����������
	PieCtrl.PIEIER9.bit.INTx1=1; //ʹ��PIE�ж�SCIARXINT

	//tbd...
 	

	// Initialize SCI-B:

	//tbd...
}
/*
int SciaTx_Ready(void)
{
	unsigned int i;
	if(SciaRegs.SCICTL2.bit.TXRDY == 1)
	{
		i = 1;
	}
	else
	{
		i = 0;
	}
	return(i);
}
*/


