#ifndef COMMON_H
#define COMMON_H
// fft.c

#define N   28

//extern double Correlation_Result[400];
 extern unsigned int Sci_Bufdec[9];
 extern unsigned int Send_Flag;
 extern unsigned int z;
 extern unsigned int Sci_VarRx[28],Sci_VarRx2[56],E_full[56],E_empty[56],BufH,BufL,BBufH,BBufL,BBuf,BBu,Gain,Error; 
 extern unsigned int crc,crcH,crcL;//���CRCУ������




//extern double Correlation_Result[400];


//ADS8505
extern long AD_Data1;
extern long AC_Case[N];
extern long fL,fH,pcon;
extern long fcon1,pcon1,fcon2,pcon2,w,y;
extern long i;


extern long Correlation_Shift;//�����غ������ֵ��Ӧ�ĵ���λ��
extern double Correlation_Coefficient;//������ϵ��
extern double Capacitance;//��ŵ���ֵ
//extern unsigned int Sci_Data[6],BufH,BufL,Buf;
//extern unsigned int BBufH,BBufL,BBuf,BBu;
//extern int Error;
//extern Uint16 ReceivedChar;//��ȡ��λ�������Ŀ�ʼ�ź�

/*
extern void delay(unsigned int t);
extern void write_ad9833_d16(unsigned int x1,unsigned int x2);//��AD9833д16λ���ݲ���
extern void ad9833_data(double frequence1,double frequence2,double Phase1,double Phase2,unsigned int frequence_SFR,unsigned int WAVE_MODE);//��AD9833д��������ݣ����У���//Ƶ�ʵ�λΪMHz
extern void ad5660_data(double voltage);//��AD5660д��������ݣ����У�����λV
extern void data_acquire();//���ݲɼ�
extern void rms_calculation(long x[],long y[]);//�����źŵľ�����ֵ
extern void correlation(long x[],long y[]);//��غ���
extern void correlation_max(long x[]);//Ѱ����غ������ֵ������λ��
extern void correlation_coefficient_calculation();//�������ϵ��
extern void capacitance_calculation(long x[]);
*/


#endif
