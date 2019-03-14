#include "DSP28_Device.h"
#include "common.h"
#include"math.h"

long AD_Data1=0;
long AC_Case[N]={0};


    unsigned int Sci_Bufdec[9];   //������λ�����͹���������
 //unsigned int Sci_Bufdec; 
    unsigned int z;
    unsigned int Send_Flag;      //���ͱ�־λ
	unsigned int Sci_VarRx[28],Sci_VarRx2[56],E_full[56],E_empty[56],BufH,BufL,BBufH,BBufL,BBuf,BBu,Gain,Error;  
    unsigned int crc=0,crcH=0,crcL=0;//���CRCУ������




///long AD_Data3[N]={0};
///long AD_Data4[N]={0};
///long AD_Data5[N]={0};
///long AD_Data6[N]={0};
///long AD_Data7[N]={0};
///long AD_Data8[N]={0};


volatile unsigned int * DA_CHA= (unsigned int *) 0x002000; //�˿�Aͨ���ĵ�ַ(8255)
volatile unsigned int * DA_CHB= (unsigned int *) 0x002001; //�˿�Bͨ���ĵ�ַ(8255)
volatile unsigned int * DA_CHC= (unsigned int *) 0x002003; //������ͨ���ĵ�ַ(8255)


volatile unsigned int * A0CH= (unsigned int *) 0x80000; //A0ͨ���ĵ�ַ
///volatile unsigned int * A1CH= (unsigned int *) 0x80001; //A1ͨ���ĵ�ַ
///volatile unsigned int * B0CH= (unsigned int *) 0x80002; //B0ͨ���ĵ�ַ
///volatile unsigned int * B1CH= (unsigned int *) 0x80003; //B1ͨ���ĵ�ַ
///volatile unsigned int * A0CH1= (unsigned int *) 0x90000; //A01ͨ���ĵ�ַ
///volatile unsigned int * A1CH1= (unsigned int *) 0x90001; //A11ͨ���ĵ�ַ
///volatile unsigned int * B0CH1= (unsigned int *) 0x90002; //B01ͨ���ĵ�ַ
///volatile unsigned int * B1CH1= (unsigned int *) 0x90003; //B11ͨ���ĵ�ַ
//volatile unsigned int * ExRamStart = (unsigned  int *)0x100000;///�ⲿRAM��ʼ��ַ

long i=0;
///long Correlation_Shift=0;//�����غ������ֵ��Ӧ�ĵ���λ��
///double Correlation_Coefficient=0;//������ϵ��
double Capacitance=0;//��ŵ���ֵ


//��������
void delay(unsigned int t);
void write_ad9833_d16(unsigned int x1,unsigned int x2);//��AD9833д16λ���ݲ���
void ad9833_data(double frequence1,double frequence2,double Phase1,double Phase2,unsigned int frequence_SFR,unsigned int WAVE_MODE);//��AD9833д��������ݣ����У���//Ƶ�ʵ�λΪMHz
//void ad5660_data(double voltage);//��AD5660д��������ݣ����У�����λV

void dac712_data(long voltage);//��dac712д��������ݣ����У�����λV

void data_acquire();//���ݲɼ�
void rms_calculation(long x[],long y[]);//�����źŵľ�����ֵ
///void correlation(long x[],long y[]);//��غ���
///void correlation_max(long x[]);//Ѱ����غ������ֵ������λ��
///void correlation_coefficient_calculation();//�������ϵ��
void capacitance_calculation(long x[]);

void scia_init(void);

void getcheckcode(unsigned int x[],int num);//����CRCУ�����ݲ������crc,num ��ʾ����x�����ݸ���



void main()
{	 


	InitSysCtrl();/*��ʼ��ϵͳ*/
	DINT;//��ֹȫ���ж�
	IER = 0x0000;//��ֹCPU�ж�
	IFR = 0x0000;//�������CPU�жϱ�־
	InitPieCtrl();/*��ʼ��PIE�ж�*/
	InitPieVectTable();	/*��ʼ��PIE�ж�ʸ����*/
    InitSci(); /*��ʼ��SCIA�Ĵ���*/
	InitGpio();

//	EINT;   // Enable Global interrupt INTM
//	ERTM;	// Enable Global realtime interrupt DBGM

	GpioDataRegs.GPBDAT.all=0xFFFF;
    GpioDataRegs.GPEDAT.bit.GPIOE1=0;

	ad9833_data(500000,500000,0,45,0,2);//ad9833��ʼ��

	///////��ʼ485���Թ������//////
	for(i = 0; i < 8; i++)
    {
  	Sci_Bufdec[i] = 0;
    }
    

    z = 0;
    Send_Flag = 0;

	#if SCIA_INT
	/*�����жϷ��������ڵ�ַ*/
	EALLOW;	
	PieVectTable.RXAINT = & SCIRXINTA_ISR;  //�ص�
	EDIS;   

	/*���ж�*/
	IER |= M_INT9;
	#endif


	EALLOW;	
	PieVectTable.TINT0 = & ISRTimer0;  //ָ��ʱ��0�ĵ�ַ
	EDIS; 
    InitCpuTimers();
	ConfigCpuTimer(&CpuTimer0, 150, 1750); //����CPU������������Ϊʱ��Ƶ�ʣ�MHz�����ж�ʱ�䣨us,��Ҫ����30us�������������ж�ʱ�䲻�õ���2.5us
    IER |= M_INT1;//�߼����ж�ʹ��
	PieCtrl.PIEIER1.bit.INTx7=1;

	EINT;   // Enable Global interrupt INTM
	ERTM;	// Enable Global realtime interrupt DBGM

//������д0
	for(i = 0; i < 55; i++)
    {
  	E_full[i] = 0;
	E_empty[i]= 0;
    }
    
///	ad5660_data(0.15);//ad5660��ʼ��
	
//	for	(i=0;i<0x4000;i++)		*(ExRamStart + i) = i;
///	ReceivedChar=0x11;

   BBuf=0x0080;
   BBufL=BBuf & 0x00FF;
   * DA_CHC=BBufL;              //8255���������


	while(1)
	{



//	dac712_data(10);
//	dac712_data(5);
//	dac712_data(0);
//	dac712_data(11);
//	dac712_data(15);
//	dac712_data(18);
//	dac712_data(19);


		Error=0x66;

		dac712_data(9905);//dac712��ʼ��0.09*16384/5
		GpioDataRegs.GPADAT.all=0x10;                    //case1
		delay(400);
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);

	    AD_Data1=* A0CH-32768;                
		AC_Case[0]=AD_Data1;                         //��ֵ��case1����


		AD_Data1=0;
		

		dac712_data(5144);//ad5660��ʼ��1.76*16384/5
		GpioDataRegs.GPADAT.all=0x20;                    //case2
		delay(400);
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[1]=AD_Data1;                         //��ֵ��case2����
		
	    AD_Data1=0;
		


		dac712_data(5341);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x30;                    //case3
		delay(400);
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[2]=AD_Data1;                         //��ֵ��case3����
		

	   	AD_Data1=0;
		

		dac712_data(4358);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x40;                    //case4
		delay(400);		
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[3]=AD_Data1;                         //��ֵ��case4������
		


	    
		AD_Data1=0;
		

		dac712_data(4368);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x50;                    //case5
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[4]=AD_Data1;                         //��ֵ��case5������
		


	    
		AD_Data1=0;
		

		dac712_data(4554);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x60;                    //case6
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[5]=AD_Data1;                         //��ֵ��case6������
		


	    
		AD_Data1=0;
		

		dac712_data(9263);//ad5660��ʼ��3.43*16384/5
		GpioDataRegs.GPADAT.all=0x70;                    //case7
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[6]=AD_Data1;                         //��ֵ��case7������
		


	    
		AD_Data1=0;
		

		dac712_data(10557);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x21;                    //case8
		delay(400);
	
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[7]=AD_Data1;                         //��ֵ��case8������
		


	   
		AD_Data1=0;
		

		dac712_data(5635);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x31;                    //case9
		delay(400);
	
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[8]=AD_Data1;                         //��ֵ��case9������
		


		AD_Data1=0;
		

		dac712_data(4455);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x41;                    //case10
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[9]=AD_Data1;                         //��ֵ��case10������
		


	   
		AD_Data1=0;
		

		dac712_data(4423);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x51;                    //case11
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[10]=AD_Data1;                         //��ֵ��case11������
		


	    
		AD_Data1=0;
		


		dac712_data(4456);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x61;                    //case12
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[11]=AD_Data1;                         //��ֵ��case12������
		


	    
		AD_Data1=0;
		

		dac712_data(4588);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x71;                    //case13
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[12]=AD_Data1;                         //��ֵ��case13������
		


	    
		AD_Data1=0;
		

		dac712_data(9932);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x32;                    //case14
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[13]=AD_Data1;                         //��ֵ��case14������
		


	   
		AD_Data1=0;
		

		dac712_data(4654);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x42;                    //case15
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
     	AC_Case[14]=AD_Data1;                         //��ֵ��case15������
		


	    
		AD_Data1=0;
		


		dac712_data(4490);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x52;                    //case16
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[15]=AD_Data1;                         //��ֵ��case16������
		


	    
		AD_Data1=0;
		


		dac712_data(4490);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x62;                    //case17
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[16]=AD_Data1;                         //��ֵ��case17������
		


	    
		AD_Data1=0;
		

		dac712_data(4487);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x72;                    //case18
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[17]=AD_Data1;                         //��ֵ��case18������
		

	   
		AD_Data1=0;
		


		dac712_data(9105);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x43;                    //case19
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[18]=AD_Data1;                         //��ֵ��case19������
		


	    
		AD_Data1=0;
		


		dac712_data(4553);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x53;                    //case20
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[19]=AD_Data1;                         //��ֵ��case20������
		


	    
		AD_Data1=0;
		


		dac712_data(4381);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x63;                    //case21
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[20]=AD_Data1;                         //��ֵ��case21������
		


	    
		AD_Data1=0;
		

		dac712_data(4346);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x73;                    //case22
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[21]=AD_Data1;                         //��ֵ��case22������
		


	   
		AD_Data1=0;
		

		dac712_data(10504);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x54;                    //case23
		delay(400);
	
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[22]=AD_Data1;                         //��ֵ��case23������
		


	    
		AD_Data1=0;
		

		dac712_data(5175);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x64;                    //case24
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[23]=AD_Data1;                         //��ֵ��case24������
		


	    
		AD_Data1=0;
		

		dac712_data(5373);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x74;                    //case25
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[24]=AD_Data1;                         //��ֵ��case25������
		


	   
		AD_Data1=0;
		

		dac712_data(10755);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x65;                    //case26
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[25]=AD_Data1;                         //��ֵ��case26������
		


	    
		AD_Data1=0;
		

		dac712_data(5687);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x75;                    //case27
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[26]=AD_Data1;                         //��ֵ��case27������
		


	    AD_Data1=0;
		

		dac712_data(9882);//ad5660��ʼ��
		GpioDataRegs.GPADAT.all=0x76;                    //case28
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//����ADC����ת��
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[27]=AD_Data1;                         //��ֵ��case28������
		


	 for(i=0;i<N;i++)
		{
        if (AC_Case[i]>4096 || AC_Case[i]<0) Error=44;     //�ж��ź��Ƿ�����
		if (AC_Case[i]>2047) AC_Case[i]=AC_Case[i]-4096;
		}


	 for(i=0;i<28;i++)
		{
        Sci_VarRx[i]=AC_Case[i];
 		}


	 for(i=0;i<28;i++)
		{
        BufL=Sci_VarRx[i] & 0x00FF;
		BufH=Sci_VarRx[i]>>8;
		Sci_VarRx2[2*i]=BufH;
		Sci_VarRx2[2*i+1]=BufL;
 		}






      AD_Data1=0;
	
	GpioDataRegs.GPEDAT.bit.GPIOE2 = 0;
		 

		 
	}   
}



void delay(unsigned int t)
{
 	while(t>0)
    	t--;
}




//��AD9833д16λ���ݣ��ϸ������ʱ�򣬲��������޸ķ���س���
//GpioDataRegs.GPBDAT.bit.GPIOB3�������������DATA
//GpioDataRegs.GPBDAT.bit.GPIOB4��һ������ʱ�������SLCK1
//GpioDataRegs.GPBDAT.bit.GPIOB5�ڶ�������ʱ�������SLCK2
//GpioDataRegs.GPBDAT.bit.GPIOB6�͵�ƽ��Ч���������FSYNC
void write_ad9833_d16(unsigned int x1,unsigned int x2)
{
	int i,w;
	delay(5);
	GpioDataRegs.GPBDAT.bit.GPIOB4=1;
	delay(5);
	GpioDataRegs.GPBDAT.bit.GPIOB5=1;
	delay(5);
	GpioDataRegs.GPBDAT.bit.GPIOB6=1;
	delay(5);
	GpioDataRegs.GPBDAT.bit.GPIOB6=0;
	delay(5);
	w=x1;
	for(i=15;i>=0;i--)
	{	
		
		delay(5);
		GpioDataRegs.GPBDAT.bit.GPIOB3=(w>>i)&0x0001;
		delay(5);
		GpioDataRegs.GPBDAT.bit.GPIOB4=0;
		delay(5);
		GpioDataRegs.GPBDAT.bit.GPIOB4=1;
		delay(5);
	
	}
	w=x2;
	for(i=15;i>=0;i--)
	{
		delay(5);
		GpioDataRegs.GPBDAT.bit.GPIOB3=(w>>i)&0x0001;
		delay(5);
		GpioDataRegs.GPBDAT.bit.GPIOB5=0;
		delay(5);
		GpioDataRegs.GPBDAT.bit.GPIOB5=1;
		delay(5);
		
	}
	GpioDataRegs.GPBDAT.bit.GPIOB6=1;
	delay(5);
}




//����AD9833��28λ���ݲ���ʼ��

//����frequence����Ƶ��ֵ����λHz����������100Hz���� frequenceΪ100����Ҫ�ر�ע����ǲ��ܳ���12MHz��
//����frequence_SFR������Ƶ�ʼĴ���ѡ��0ΪƵ�ʼĴ���0,1ΪƵ�ʼĴ���1��
//����WAVE_MODE�������������ѡ��0Ϊ���ǲ���1Ϊ����,2Ϊ���Ҳ���
//����Phase�����ò�����λֵ,��λ�Ƕ�;
 
void ad9833_data(double frequence1,double frequence2,double phase1,double phase2,unsigned int frequence_SFR,unsigned int WAVE_MODE)
{
	unsigned int frequence_LSB1,frequence_MSB1,Phs_data1,frequence_LSB2,frequence_MSB2,Phs_data2,phase_hex;
	double  frequence_DATA,phase_DATA;
	long int frequence_hex;
 
	
	//����A9833_1Ƶ�ʵ�16����ֵ
	frequence_DATA=frequence1*268435456/25000000;	//���ʱ��Ƶ�ʲ�Ϊ25MHZ���޸ĸô���Ƶ��ֵ����λMHz ��AD9833���֧��25MHz
	frequence_hex=frequence_DATA;  //���frequence_hex��ֵ��32λ��һ��ܴ�����֣���Ҫ��ֳ�����14λ���д���
	frequence_LSB1=frequence_hex; //frequence_hex��16λ�͸�frequence_LSB
	frequence_LSB1=frequence_LSB1&0x3fff;//ȥ�������λ��16λ����ȥ����λ������14λ
	frequence_MSB1=frequence_hex>>14; //frequence_hex��16λ�͸�frequence_HSB
	frequence_MSB1=frequence_MSB1&0x3fff;//ȥ�������λ��16λ����ȥ����λ������14λ
	//����A9833_1��λ��16���Ƶ
	phase_DATA=phase1*4096/360;
	phase_hex=phase_DATA;
	Phs_data1=phase_hex|0xC000;


	//����A9833_2Ƶ�ʵ�16����
	frequence_DATA=frequence2*268435456/25000000;
	frequence_hex=frequence_DATA;  //���frequence_hex��ֵ��32λ��һ��ܴ�����֣���Ҫ��ֳ�����14λ���д���
	frequence_LSB2=frequence_hex; //frequence_hex��16λ�͸�frequence_LSB
	frequence_LSB2=frequence_LSB2&0x3fff;//ȥ�������λ��16λ����ȥ����λ������14λ
	frequence_MSB2=frequence_hex>>14; //frequence_hex�16λ�͸�frequence_HSB
	frequence_MSB2=frequence_MSB2&0x3fff;//ȥ�������λ��16λ����ȥ����λ������14λ
	//����A9833_2��λ��16����ֵ	
	phase_DATA=phase2*4096/360;
	phase_hex=phase_DATA;
	Phs_data2=phase_hex|0xC000;

	



	if(frequence_SFR==0)				  //���������õ�����Ƶ�ʼĴ���0
	{
		frequence_LSB1=frequence_LSB1|0x4000;
 		frequence_MSB1=frequence_MSB1|0x4000;
 
 		frequence_LSB2=frequence_LSB2|0x4000;
		frequence_MSB2=frequence_MSB2|0x4000;

	//ʹ��Ƶ�ʼĴ���0�������
	write_ad9833_d16(0x0100,0x0100); //��λAD9833,��RESETλΪ1
	write_ad9833_d16(0x2100,0x2100); //ѡ������һ��д�룬B28λ��RESETλΪ1
	write_ad9833_d16(frequence_LSB1,frequence_LSB2); //L14��ѡ��Ƶ�ʼĴ���0�ĵ�14λ��������
	write_ad9833_d16(frequence_MSB1,frequence_MSB2); //H14 Ƶ�ʼĴ����ĸ�14λ��������
	write_ad9833_d16(Phs_data1,Phs_data2);//������λ
	//write_ad9833_d16(0x2000); //����FSELECTλΪ0��оƬ���빤��״̬,Ƶ�ʼĴ���0�������
	}


	if(frequence_SFR==1)				//���������õ�����Ƶ�ʼĴ���1
	{
		frequence_LSB1=frequence_LSB1|0x8000;
 		frequence_MSB1=frequence_MSB1|0x8000;
 
 		frequence_LSB2=frequence_LSB2|0x8000;
		frequence_MSB2=frequence_MSB2|0x8000;

 		//ʹ��Ƶ�ʼĴ���1�������
		write_ad9833_d16(0x0100,0x0100); //��λAD9833,��RESETλΪ1
		write_ad9833_d16(0x2100,0x2100); //�������һ��д�룬B28λ��RESETλΪ1
		write_ad9833_d16(frequence_LSB1,frequence_LSB2); //L14��ѡ��Ƶ�ʼĴ���1�ĵ�14λ��������
		write_ad9833_d16(frequence_MSB1,frequence_MSB2); //H14 Ƶ�ʼĴ����ĸ�14λ��������
		write_ad9833_d16(Phs_data1,Phs_data2);//������λ
		//write_ad9833_d16(0x2800); ����FSELECTλΪ1����ʹ�õ�ʼĴ���1��ֵ��оƬ��빤��״�,Ƶ�ʼĴ���1�������
	}



	
	if(WAVE_MODE==0)
	{
	//Ƶ�ʼĴ���������ǲ�����
	delay(100);
	write_ad9833_d16(0x2002,0x2002); //���MODEλΪ1��������ǲ�ģʽ
	}



	if(WAVE_MODE==1)
	{
	//Ƶ�ʼĴ��������������
	delay(100);
	write_ad9833_d16(0x2028,0x2028); //����OPBITENλΪ1���������ģʽ
	}


	if(WAVE_MODE==2)
	{
	//Ƶ�ʼĴ���������Ҳ�����
	delay(100);
	write_ad9833_d16(0x2000,0x2000); //����MODEλΪ0��������Ҳ�ģʽ
	}

}


//��ģת��оƬDAC712�������
void dac712_data(long voltage)
{

    BBufL=voltage & 0x00FF;
	* DA_CHA =BBufL;
	BBufH=voltage>>8;
    * DA_CHB =BBufH;	
}



//��ģת��оƬAD5660�������
/*  void ad5660_data(double voltage)
{
	unsigned int  voltage_DATA;
	int i,w;
	voltage_DATA=voltage*65536/5;
	delay(5);
	GpioDataRegs.GPBDAT.bit.GPIOB7=1;
	delay(5);
	GpioDataRegs.GPBDAT.bit.GPIOB6=1;
	delay(5);
	GpioDataRegs.GPBDAT.bit.GPIOB6=0;
	delay(5);
	w=voltage_DATA;
	for(i=23;i>=16;i--)
	{	
		delay(5);
		GpioDataRegs.GPBDAT.bit.GPIOB3=0;
		delay(5);
		GpioDataRegs.GPBDAT.bit.GPIOB7=0;
		delay(5);
		GpioDataRegs.GPBDAT.bit.GPIOB7=1;
		delay(5);
	}
	for(i=15;i>=0;i--)
	{	
		
		delay(5);
		GpioDataRegs.GPBDAT.bit.GPIOB3=(w>>i)&0x0001;
		delay(5);
		GpioDataRegs.GPBDAT.bit.GPIOB7=0;
		delay(5);
		GpioDataRegs.GPBDAT.bit.GPIOB7=1;
		delay(5);
	}
	GpioDataRegs.GPBDAT.bit.GPIOB6=1;
	delay(5);
}

*/

/*  void data_acquire()
{
	long i;
	
	for(i=0;i<N;i++)
	{
		GpioDataRegs.GPBDAT.bit.GPIOB0=0;//����ADC����ת��
		GpioDataRegs.GPBDAT.bit.GPIOB1=0;
		GpioDataRegs.GPBDAT.bit.GPIOB2=0;
		delay(10); //while(GpioDataRegs.GPFDAT.bit.GPIOF13==0);//�ȴ�ADC����ת�������
		
		GpioDataRegs.GPBDAT.bit.GPIOB0=1;//����ADC���ݱ���
		GpioDataRegs.GPBDAT.bit.GPIOB1=1;
		GpioDataRegs.GPBDAT.bit.GPIOB2=1;
		delay(80);
		
		AD_Data1[i]=* A0CH-32768;
		if (AD_Data1[i]>4096 || AD_Data1[i]<0)//�жϲɼ����ź��Ƿ�����
			Error=1;
		if (AD_Data1[i]>2047) 
			AD_Data1[i]=AD_Data1[i]-4096;

		AD_Data2[i]=* A1CH-36864;
		if (AD_Data2[i]>4096 || AD_Data2[i]<0)//�жϲɼ����ź��Ƿ����� 
			Error=1;
		if (AD_Data2[i]>2047) 
			AD_Data2[i]=AD_Data2[i]-4096;

		AD_Data3[i]=* B0CH-40960;
		if (AD_Data3[i]>4096 || AD_Data3[i]<0)//�жϲɼ����ź��Ƿ����� 
			Error=1;
		if (AD_Data3[i]>2047) 
			AD_Data3[i]=AD_Data3[i]-4096;

		AD_Data4[i]=* B1CH-45056;
		if (AD_Data4[i]>4096 || AD_Data4[i]<0)//�жϲɼ����ź��Ƿ����� 
			Error=44;
		if (AD_Data4[i]>2047) 
			AD_Data4[i]=AD_Data4[i]-4096;

	    AD_Data5[i]=* A0CH1-32768;
		if (AD_Data5[i]>4096 || AD_Data5[i]<0)//�жϲɼ����ź��Ƿ����� 
			Error=44;
		if (AD_Data5[i]>2047) 
			AD_Data5[i]=AD_Data5[i]-4096;

		AD_Data6[i]=* A1CH1-36864;
		if (AD_Data6[i]>4096 || AD_Data6[i]<0)//�жϲɼ����ź��Ƿ����� 
			Error=44;
		if (AD_Data6[i]>2047) 
			AD_Data6[i]=AD_Data6[i]-4096;

		AD_Data7[i]=* B0CH1-40960;
		if (AD_Data7[i]>4096 || AD_Data7[i]<0)//�жϲɼ����ź��Ƿ����� 
			Error=44;
		if (AD_Data7[i]>2047) 
			AD_Data7[i]=AD_Data7[i]-4096;

		AD_Data8[i]=* B1CH1-45056;
		if (AD_Data8[i]>4096 || AD_Data8[i]<0)//�жϲɼ����ź��Ƿ����� 
			Error=44;
		if (AD_Data8[i]>2047) 
			AD_Data8[i]=AD_Data8[i]-4096;
	  
	
	}
	

}

*/
/*
void correlation(long x[],long y[])//x���δ������źţ�y���δ������ź�
{
	long i,j;
	double Correlation_Max=0;//�����غ������ֵ
	double Correlation_Result[400]={0};//�����غ���ֵ
	double tp1=0;
	double tp2=0;
	double rms=0;
	
	for(i=0;i<400;i++)
  	{
  		Correlation_Result[i]=0;
  		for(j=0;j<N-i;j++)
  		{ 
  			Correlation_Result[i]+=x[j]*y[j+i];
  		}
  	}

  	Correlation_Max=x[0];
	for(i=0;i<400;i++)    //Ѱ�����ֵ
	{
		if(x[i]>Correlation_Max)
		{
			Correlation_Shift = i;
			Correlation_Max = x[i];
		}
	}	
	
		
    for(i=0;i<N;i++)//�����źŵľ�����ֵ	
	{
        tp1+=x[i]*x[i];
	    tp2+=y[i]*y[i];
	}
	rms=sqrt(tp1*tp2)/N;
	Correlation_Coefficient=Correlation_Max/(N-Correlation_Shift)/rms;
}



	

void capacitance_calculation(long x[])//�Ƶ���ֵ
{
	long i,m;
	m=0;
	for(i=0;i<N;i++)
	{
		m+=x[i];
	}
	Capacitance=m/N;
}

*/


void getcheckcode(unsigned int x[],int num)
{
	
	int i=0,j=0;
	crc=0xFFFF;
	
	for(i=0;i<num-2;i++)
	{
		crc^=x[i];
		for(j=0;j<8;j++)
		{
			if(crc&1)
			{
				crc>>=1;
				crc^=0xA001;
			}
			else
			{
				crc>>=1;
			}

		}
		
	}

}



