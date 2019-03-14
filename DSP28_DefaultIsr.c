
/****************************************************************************
*
*�ļ�����DSP28_DefaultIsr.c
*
*��  �ܣ����ļ���������F2812����Ĭ����ص��жϺ�����������ֻ������Ӧ���жϺ���
*        �м��������ʵ���жϺ����Ĺ��ܾͿ���
*
*��  ��: likyo from hellodsp
*
****************************************************************************/

#include "DSP28_Device.h"

//---------------------------------------------------------------------------
// INT13, INT14, NMI, XINT1, XINT2 ���жϷ�����:
//
interrupt void INT13_ISR(void)     // INT13 ���� CPU-Timer1�жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);
  
  // ����;
}

interrupt void INT14_ISR(void)     // CPU-Timer2�жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);
  
  // ����;
}

interrupt void NMI_ISR(void)       // �ⲿ�����ε��жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);
  
  // ����;
}

interrupt void  XINT1_ISR(void)     //XINT1���ⲿ�ӿڣ��жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);
  
  // ����;
}     

interrupt void  XINT2_ISR(void)     //XINT2���ⲿ�ӿڣ��жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;); 
  
  // ����;
}

//---------------------------------------------------------------------------
// DATALOG, RTOSINT, EMUINT, RTOS �жϷ�����:
//
interrupt void DATALOG_ISR(void)   // CPU���ݼ�¼�жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;); 
  
  // ����;

}

interrupt void RTOSINT_ISR(void)   // CPUʵʱOS�жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;); 
  
  // ����;
}

interrupt void EMUINT_ISR(void)    // CPU�����жϺ���
{
   // ����������жϺ����Ĵ���
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);
  
  // ����;
}

//---------------------------------------------------------------------------
// ILLEGAL Instruction Trap �жϷ�����:
//
interrupt void ILLEGAL_ISR(void)   // �Ƿ����������ж�
{
  // ����������жϺ����Ĵ���
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);
  
  // ����;
}

//---------------------------------------------------------------------------
// �û���������ж�:
//
interrupt void USER0_ISR(void)     // �û�������ж�0
{
  // ����������жϺ����Ĵ���
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;); 
  
  // ����;
}

interrupt void USER1_ISR(void)     // �û�������ж�1
{
  // ����������жϺ����Ĵ���
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;); 
  
  // ����;
}

interrupt void USER2_ISR(void)     // �û�������ж�2
{
  // ����������жϺ����Ĵ���
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);
  
  // ����;

}

interrupt void USER3_ISR(void)     // �û�������ж�3
{
  // ����������жϺ����Ĵ���
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);
  
  // ����;

}

interrupt void USER4_ISR(void)     // �û�������ж�4
{
  // ����������жϺ����Ĵ���
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);  

  // ����;
}

interrupt void USER5_ISR(void)     // �û�������ж�5
{
  // ����������жϺ����Ĵ���
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);
  
  // ����;
}

interrupt void USER6_ISR(void)     // �û�������ж� 6
{
  // ����������жϺ����Ĵ���
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);
  
  // ����;
}

interrupt void USER7_ISR(void)     // �û�������ж�7
{
  // ����������жϺ����Ĵ���
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);
  
  // ����;
}

interrupt void USER8_ISR(void)     // �û�������ж�8
{
  // ����������жϺ����Ĵ���
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);
  
  // ����;
}

interrupt void USER9_ISR(void)     // �û�������ж�9
{
  // ����������жϺ����Ĵ���
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);
  
  // ����;
}

interrupt void USER10_ISR(void)    // �û�������ж�10
{
  // ����������жϺ����Ĵ���
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;); 
  
  // ����;
}

interrupt void USER11_ISR(void)    // �û�������ж�11
{
  // ����������жϺ����Ĵ���
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);
  
  // ����;
}

//---------------------------------------------------------------------------
//����Ϊ�����жϺ��� 
//
interrupt void  ADCINT_ISR(void)     // ADC�жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP1;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}


interrupt void  TINT0_ISR(void)      // CPU-Timer0�жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP1;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}


interrupt void  WAKEINT_ISR(void)    // WD�жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP1;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}


interrupt void PDPINTA_ISR( void )    // EV-A�������������жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP1;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}


interrupt void CMP1INT_ISR(void)    // �Ƚϵ�Ԫ1�ıȽ��ж�
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP2;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void CMP2INT_ISR(void)    // �Ƚϵ�Ԫ2�ıȽ��ж�
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP2;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void CMP3INT_ISR(void)    // �Ƚϵ�Ԫ3�ıȽ��ж�
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP2;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void T1PINT_ISR(void)    // ͨ�ö�ʱ��T1�������ж�
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP2;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void T1CINT_ISR(void)    // ͨ�ö�ʱ��T1�ıȽ��ж�
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP2;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void T1UFINT_ISR(void)   // ͨ�ö�ʱ��1�������ж�
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP2;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void T1OFINT_ISR(void)   // ͨ�ö�ʱ��1�������ж�
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP2;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}
      
interrupt void T2PINT_ISR(void)     //ͨ�ö�ʱ��2�������ж�
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP3;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void T2CINT_ISR(void)     // ͨ�ö�ʱ��2�ıȽ��ж�
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP3;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void T2UFINT_ISR(void)    // ͨ�ö�ʱ��2�������ж�
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP3;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void T2OFINT_ISR(void)    // ͨ�ö�ʱ��2�������ж�
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP3;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void CAPINT1_ISR(void)    // ����Ԫ1�ж�
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP3;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void CAPINT2_ISR(void)    // ����Ԫ2�ж�
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP3;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void CAPINT3_ISR(void)    // ����Ԫ3�ж�
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP3;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}
      

interrupt void  PDPINTB_ISR(void)   // EV-B�������������жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP1;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void CMP4INT_ISR(void)    // �Ƚϵ�Ԫ4�ıȽ��жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP4;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void CMP5INT_ISR(void)    // �Ƚϵ�Ԫ5�ıȽ��жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP4;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void CMP6INT_ISR(void)    // �Ƚϵ�Ԫ6�ıȽ��жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP4;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void T3PINT_ISR(void)     // ͨ�ö�ʱ��3�������жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP4;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void T3CINT_ISR(void)     // ͨ�ö�ʱ��3�ıȽ��жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP4;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void T3UFINT_ISR(void)    // ͨ�ö�ʱ��3�������жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP4;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void T3OFINT_ISR(void)    // ͨ�ö�ʱ��3�������жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP4;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}
     
interrupt void T4PINT_ISR(void)    // ͨ�ö�ʱ��4�������жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP5;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void T4CINT_ISR(void)    // ͨ�ö�ʱ��4�ıȽ��жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP5;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void T4UFINT_ISR(void)   // ͨ�ö�ʱ��4�������жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP5;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void T4OFINT_ISR(void)   // ͨ�ö�ʱ��4�������жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP5;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void CAPINT4_ISR(void)   // ����Ԫ4�жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP5;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void CAPINT5_ISR(void)   // ����Ԫ5�жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP5;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void CAPINT6_ISR(void)   // ����Ԫ6�жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP5;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}


interrupt void MRINTA_ISR(void)     // McBSP-A�����жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP6;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void MXINTA_ISR(void)     // McBSP-A�����жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP6;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}


interrupt void SPIRXINTA_ISR(void)    // SPI-A�����жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP6;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}


interrupt void SPITXINTA_ISR(void)     // SPI-A�����жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP6;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}


interrupt void ISRTimer0(void)
{
    int t=2000;
	CpuTimer0Regs.TCR.bit.TSS = 1;  ///�ر�CPU��ʱ��0
	 if((z==6)&&(Sci_Bufdec[0]==0x65)&&(Sci_Bufdec[1]==0x56)&&(Sci_Bufdec[2]==0x01)&&(Sci_Bufdec[4]==0x05)&&(Sci_Bufdec[5]==0x20))
	   {
          GpioDataRegs.GPEDAT.bit.GPIOE2=1;
           if (Sci_Bufdec[3]==0x00)
		       {
		  	   SciaRegs.SCITXBUF =0x65;            
        	   delay(t);
			   SciaRegs.SCITXBUF =0x56;            
        	   delay(t);
			   SciaRegs.SCITXBUF =0x01;            
        	   delay(t);
			   SciaRegs.SCITXBUF =0x00;            
        	   delay(t);
			   SciaRegs.SCITXBUF =0x05;            
        	   delay(t);
			   SciaRegs.SCITXBUF =0x20;            
        	   delay(t);
               GpioDataRegs.GPEDAT.bit.GPIOE2 = 0;
		       z=0;
			   }
			   else if(Sci_Bufdec[3]==0x01)
			   {
			        if((E_empty[1]==0x00)&&(E_empty[2]==0x00)&&(E_empty[3]==0x00)&&(E_empty[7]==0x00)&&(E_empty[9]==0x00)&&(E_empty[11]==0x00)&&(E_empty[13]==0x00)&&(E_empty[15]==0x00)&&(E_empty[17]==0x00)&&(E_full[1]==0x00)&&(E_full[3]==0x00)&&(E_full[5]==0x00)&&(E_full[7]==0x00)&&(E_full[9]==0x00)&&(E_full[11]==0x00)&&(E_full[13]==0x00)&&(E_full[15]==0x00)&&(E_full[17]==0x00))
					{
					  SciaRegs.SCITXBUF =0x65;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x56;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x01;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x01;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x02;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x00;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x00;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x00;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x00;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x05;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x20;            
        	          delay(t);
                      GpioDataRegs.GPEDAT.bit.GPIOE2 = 0;
		              z=0;
					}
					else if((E_empty[1]==0x00)&&(E_empty[2]==0x00)&&(E_empty[3]==0x00)&&(E_empty[7]==0x00)&&(E_empty[9]==0x00)&&(E_empty[11]==0x00)&&(E_empty[13]==0x00)&&(E_empty[15]==0x00)&&(E_empty[17]==0x00))
					{
					  SciaRegs.SCITXBUF =0x65;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x56;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x01;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x01;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x02;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x00;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x00;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x01;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x01;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x05;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x20;            
        	          delay(t);
                      GpioDataRegs.GPEDAT.bit.GPIOE2 = 0;
		              z=0;
					}
					else if((E_full[1]==0x00)&&(E_full[2]==0x00)&&(E_full[3]==0x00)&&(E_full[7]==0x00)&&(E_full[9]==0x00)&&(E_full[11]==0x00)&&(E_full[13]==0x00)&&(E_full[15]==0x00)&&(E_full[17]==0x00))
					{
					  SciaRegs.SCITXBUF =0x65;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x56;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x01;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x01;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x02;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x01;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x01;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x00;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x00;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x05;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x20;            
        	          delay(t);
                      GpioDataRegs.GPEDAT.bit.GPIOE2 = 0;
		              z=0;
					}
                    else
					{
					  SciaRegs.SCITXBUF =0x65;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x56;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x01;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x01;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x02;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x01;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x01;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x01;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x01;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x05;            
        	          delay(t);
			          SciaRegs.SCITXBUF =0x20;            
        	          delay(t);
                      GpioDataRegs.GPEDAT.bit.GPIOE2 = 0;
		              z=0;
					}

			   }
			   else if(Sci_Bufdec[3]==0x02)
			   {
		  	   SciaRegs.SCITXBUF =0x65;            
        	   delay(t);
			   SciaRegs.SCITXBUF =0x56;            
        	   delay(t);
			   SciaRegs.SCITXBUF =0x01;            
        	   delay(t);
			   SciaRegs.SCITXBUF =0x02;            
        	   delay(t);
			   SciaRegs.SCITXBUF =0x1C;            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[0];  
			   E_empty[0]=Sci_VarRx2[0];          
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[1];  
			   E_empty[1]=Sci_VarRx2[1];           
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[2];  
			   E_empty[2]=Sci_VarRx2[2];          
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[3];  
			   E_empty[3]=Sci_VarRx2[3];            
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[4]; 
			   E_empty[4]=Sci_VarRx2[4];           
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[5];  
			   E_empty[5]=Sci_VarRx2[5];          
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[6];  
			   E_empty[6]=Sci_VarRx2[6];         
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[7]; 
			   E_empty[7]=Sci_VarRx2[7];           
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[8]; 
			   E_empty[8]=Sci_VarRx2[8];           
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[9]; 
			   E_empty[9]=Sci_VarRx2[9];           
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[10];  
			   E_empty[10]=Sci_VarRx2[10];           
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[11]; 
			   E_empty[11]=Sci_VarRx2[11];           
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[12];    
			   E_empty[12]=Sci_VarRx2[12];          
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[13]; 
			   E_empty[13]=Sci_VarRx2[13];            
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[14];  
			   E_empty[14]=Sci_VarRx2[14];            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[15]; 
			   E_empty[15]=Sci_VarRx2[15];           
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[16]; 
			   E_empty[16]=Sci_VarRx2[16];            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[17]; 
			   E_empty[17]=Sci_VarRx2[17];           
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[18];  
			   E_empty[18]=Sci_VarRx2[18];           
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[19]; 
			   E_empty[19]=Sci_VarRx2[19];             
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[20]; 
			   E_empty[20]=Sci_VarRx2[20];             
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[21]; 
			   E_empty[21]=Sci_VarRx2[21];             
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[22];  
			   E_empty[22]=Sci_VarRx2[22];           
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[23];  
			   E_empty[23]=Sci_VarRx2[23];           
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[24];  
			   E_empty[24]=Sci_VarRx2[24];           
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[25];  
			   E_empty[25]=Sci_VarRx2[25];           
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[26];  
			   E_empty[26]=Sci_VarRx2[26];            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[27];   
			   E_empty[27]=Sci_VarRx2[27];           
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[28]; 
			   E_empty[28]=Sci_VarRx2[28];            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[29];  
			   E_empty[29]=Sci_VarRx2[29];           
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[30]; 
			   E_empty[30]=Sci_VarRx2[30];            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[31]; 
			   E_empty[31]=Sci_VarRx2[31];           
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[32];   
			   E_empty[32]=Sci_VarRx2[32];           
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[33];   
			   E_empty[33]=Sci_VarRx2[33];           
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[34];  
			   E_empty[34]=Sci_VarRx2[34];            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[35];   
			   E_empty[35]=Sci_VarRx2[35];           
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[36]; 
			   E_empty[36]=Sci_VarRx2[36];            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[37]; 
			   E_empty[37]=Sci_VarRx2[37];             
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[38]; 
			   E_empty[38]=Sci_VarRx2[38];            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[39]; 
			   E_empty[39]=Sci_VarRx2[39];             
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[40]; 
			   E_empty[40]=Sci_VarRx2[40];            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[41];  
			   E_empty[41]=Sci_VarRx2[41];           
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[42];  
			   E_empty[42]=Sci_VarRx2[42];            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[43];  
			   E_empty[43]=Sci_VarRx2[43];           
        	   delay(t);			  
               SciaRegs.SCITXBUF =Sci_VarRx2[44]; 
               E_empty[44]=Sci_VarRx2[44];            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[45];   
			   E_empty[45]=Sci_VarRx2[45];           
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[46];  
			   E_empty[46]=Sci_VarRx2[46];           
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[47]; 
			   E_empty[47]=Sci_VarRx2[47];            
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[48]; 
			   E_empty[48]=Sci_VarRx2[48];           
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[49]; 
			   E_empty[49]=Sci_VarRx2[49];             
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[50]; 
			   E_empty[50]=Sci_VarRx2[50];            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[51];  
			   E_empty[51]=Sci_VarRx2[51];           
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[52];   
			   E_empty[52]=Sci_VarRx2[52];           
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[53];   
			   E_empty[53]=Sci_VarRx2[53];           
        	   delay(t);			  
               SciaRegs.SCITXBUF =Sci_VarRx2[54];   
               E_empty[54]=Sci_VarRx2[54];           
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[55];  
			   E_empty[55]=Sci_VarRx2[55];           
        	   delay(t);			  
			   SciaRegs.SCITXBUF =0x05;           
        	   delay(t);
			   SciaRegs.SCITXBUF =0x20;            
        	   delay(t);
               GpioDataRegs.GPEDAT.bit.GPIOE2 = 0;
		       z=0;
			   }
			   else if(Sci_Bufdec[3]==0x03)
			   {
		  	   SciaRegs.SCITXBUF =0x65;            
        	   delay(t);
			   SciaRegs.SCITXBUF =0x56;            
        	   delay(t);
			   SciaRegs.SCITXBUF =0x01;            
        	   delay(t);
			   SciaRegs.SCITXBUF =0x03;            
        	   delay(t);
			   SciaRegs.SCITXBUF =0x1C;            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[0];   
			   E_full[0]= Sci_VarRx2[0];        
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[1];  
			   E_full[1]= Sci_VarRx2[1];            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[2];   
			   E_full[2]= Sci_VarRx2[2];            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[3];  
			   E_full[3]= Sci_VarRx2[3];             
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[4];   
			   E_full[4]= Sci_VarRx2[4];            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[5]; 
			   E_full[5]= Sci_VarRx2[5];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[6]; 
			   E_full[6]= Sci_VarRx2[6];              
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[7];  
			   E_full[7]= Sci_VarRx2[7];             
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[8];  
			   E_full[8]= Sci_VarRx2[8];             
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[9];  
			   E_full[9]= Sci_VarRx2[9];             
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[10]; 
			   E_full[10]= Sci_VarRx2[10];              
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[11]; 
			   E_full[11]= Sci_VarRx2[11];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[12];   
			   E_full[12]= Sci_VarRx2[12];            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[13];   
			   E_full[13]= Sci_VarRx2[13];            
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[14];  
			   E_full[14]= Sci_VarRx2[14];             
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[15];  
			   E_full[15]= Sci_VarRx2[15];             
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[16]; 
			   E_full[16]= Sci_VarRx2[16];              
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[17]; 
			   E_full[17]= Sci_VarRx2[17];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[18];  
			   E_full[18]= Sci_VarRx2[18];             
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[19];
			   E_full[19]= Sci_VarRx2[19];               
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[20];
			   E_full[20]= Sci_VarRx2[20];               
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[21];  
			   E_full[21]= Sci_VarRx2[21];             
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[22];    
			   E_full[22]= Sci_VarRx2[22];           
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[23]; 
			   E_full[23]= Sci_VarRx2[23];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[24]; 
			   E_full[24]= Sci_VarRx2[24];              
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[25]; 
			   E_full[25]= Sci_VarRx2[25];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[26];  
			   E_full[26]= Sci_VarRx2[26];             
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[27];  
			   E_full[27]= Sci_VarRx2[27];             
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[28];  
			   E_full[28]= Sci_VarRx2[28];             
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[29];   
			   E_full[29]= Sci_VarRx2[29];            
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[30]; 
			   E_full[30]= Sci_VarRx2[30];              
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[31]; 
			   E_full[31]= Sci_VarRx2[31];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[32];  
			   E_full[32]= Sci_VarRx2[32];             
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[33];    
			   E_full[33]= Sci_VarRx2[33];           
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[34]; 
			   E_full[34]= Sci_VarRx2[34];              
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[35]; 
			   E_full[35]= Sci_VarRx2[35];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[36]; 
			   E_full[36]= Sci_VarRx2[36];              
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[37];   
			   E_full[37]= Sci_VarRx2[37];            
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[38];   
			   E_full[38]= Sci_VarRx2[38];            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[39];   
			   E_full[39]= Sci_VarRx2[39];            
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[40];  
			   E_full[40]= Sci_VarRx2[40];             
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[41];   
			   E_full[41]= Sci_VarRx2[41];            
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[42];  
			   E_full[42]= Sci_VarRx2[42];             
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[43];   
			   E_full[43]= Sci_VarRx2[43];            
        	   delay(t);			  
               SciaRegs.SCITXBUF =Sci_VarRx2[44]; 
               E_full[44]= Sci_VarRx2[44];              
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[45];  
			   E_full[45]= Sci_VarRx2[45];             
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[46];  
			   E_full[46]= Sci_VarRx2[46];             
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[47]; 
			   E_full[47]= Sci_VarRx2[47];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[48];    
			   E_full[48]= Sci_VarRx2[48];           
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[49];   
			   E_full[49]= Sci_VarRx2[49];            
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[50];  
			   E_full[50]= Sci_VarRx2[50];             
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[51];  
			   E_full[51]= Sci_VarRx2[51];             
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[52];   
			   E_full[52]= Sci_VarRx2[52];            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[53]; 
			   E_full[53]= Sci_VarRx2[53];              
        	   delay(t);			  
               SciaRegs.SCITXBUF =Sci_VarRx2[54];    
               E_full[54]= Sci_VarRx2[54];           
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[55];  
			   E_full[55]= Sci_VarRx2[55];             
        	   delay(t);			  
			   SciaRegs.SCITXBUF =0x05;          
        	   delay(t);
			   SciaRegs.SCITXBUF =0x20;            
        	   delay(t);
               GpioDataRegs.GPEDAT.bit.GPIOE2 = 0;
		       z=0;
			   }
			   else if(Sci_Bufdec[3]==0x11)
			   {
		  	   SciaRegs.SCITXBUF =0x65;            
        	   delay(t);
			   SciaRegs.SCITXBUF =0x56;            
        	   delay(t);
			   SciaRegs.SCITXBUF =0x01;            
        	   delay(t);
			   SciaRegs.SCITXBUF =0x11;            
        	   delay(t);
			   SciaRegs.SCITXBUF =0x1C;            
        	   delay(t);

			   SciaRegs.SCITXBUF =Sci_VarRx2[0];           
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[1];            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[2];              
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[3];             
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[4];             
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[5];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[6];            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[7];             
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[8];           
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[9];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[10];             
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[11];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[12];              
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[13];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[14];             
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[15];             
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[16];              
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[17];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[18];              
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[19];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[20];             
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[21];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[22];              
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[23];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[24];             
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[25];             
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[26];              
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[27];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[28];              
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[29];             
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[30];               
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[31];               
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[32];             
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[33];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[34];               
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[35];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[36];               
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[37];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[38];              
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[39];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[40];               
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[41];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[42];               
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[43];               
        	   delay(t);			  
               SciaRegs.SCITXBUF =Sci_VarRx2[44];              
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[45];               
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[46];              
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[47];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[48];              
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[49];              
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[50];            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[51];               
        	   delay(t);			  
			   SciaRegs.SCITXBUF =Sci_VarRx2[52];             
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[53];            
        	   delay(t);			  
               SciaRegs.SCITXBUF =Sci_VarRx2[54];            
        	   delay(t);
			   SciaRegs.SCITXBUF =Sci_VarRx2[55];             
        	   delay(t);			  
			   SciaRegs.SCITXBUF =0x05;            
        	   delay(t);
			   SciaRegs.SCITXBUF =0x20;            
        	   delay(t);
               GpioDataRegs.GPEDAT.bit.GPIOE2 = 0;
		       z=0;
			   }


	    }
	else
	    {
	z=0;
	    }
		 
  PieCtrl.PIEACK.bit.ACK1 = 1;
  // ����;
}







interrupt void SCIRXINTA_ISR(void)     // SCI-A�����жϺ���
{
	
        PieCtrl.PIEACK.bit.ACK9 = 1;
		if(SciaRegs.SCIRXST.bit.RXRDY == 1)
		{
		    CpuTimer0Regs.TCR.bit.TSS=1;
			CpuTimer0Regs.TCR.bit.TRB=1;
		    CpuTimer0Regs.TCR.bit.TSS=0;  ///����CPU��ʱ��0
			Sci_Bufdec[z] = SciaRegs.SCIRXBUF.all;
		    z++;
			if(z==7)
		   {
	        for(z=0;z<6;z++)
	           {
	            Sci_Bufdec[z]=Sci_Bufdec[z+1];
		        }
			z=6;
		    }
		    
		}
  // ����;
}

interrupt void SCITXINTA_ISR(void)     // SCI-A�����жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP9;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}


interrupt void SCIRXINTB_ISR(void)     // SCI-B�����жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP9;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void SCITXINTB_ISR(void)     // SCI-B�����жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP9;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}


interrupt void ECAN0INTA_ISR(void)  // eCAN0�жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP9;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}

interrupt void ECAN1INTA_ISR(void)  // eCAN1�жϺ���
{
  // ����������жϺ����Ĵ���
  
  // ע���˳��жϺ���ʱ��Ҫ���ͷ�PIE��ʹ��PIE�ܹ���Ӧͬ�������ж� 
  // PieCtrl.PIEACK.all = PIEACK_GROUP9;
  
  // ��������ֻ��Ϊ�˱����д�ģ����������뽫��ɾ��
  
  // �жϺ�������
     asm ("      ESTOP0");
     for(;;);

  // ����;
}


interrupt void PIE_RESERVED(void)  // PIE�����Ŀռ䣬����TI����
{
  asm ("      ESTOP0");
  for(;;);
}

interrupt void rsvd_ISR(void)          // TI������
{
  asm ("      ESTOP0");
  for(;;);
}

//===========================================================================
// No more.
//===========================================================================

