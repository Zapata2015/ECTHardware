#include "DSP28_Device.h"
#include "common.h"
#include"math.h"

long AD_Data1=0;
long AC_Case[N]={0};


    unsigned int Sci_Bufdec[9];   //放置上位机传送过来的数据
 //unsigned int Sci_Bufdec; 
    unsigned int z;
    unsigned int Send_Flag;      //发送标志位
	unsigned int Sci_VarRx[28],Sci_VarRx2[56],E_full[56],E_empty[56],BufH,BufL,BBufH,BBufL,BBuf,BBu,Gain,Error;  
    unsigned int crc=0,crcH=0,crcL=0;//存放CRC校验数据




///long AD_Data3[N]={0};
///long AD_Data4[N]={0};
///long AD_Data5[N]={0};
///long AD_Data6[N]={0};
///long AD_Data7[N]={0};
///long AD_Data8[N]={0};


volatile unsigned int * DA_CHA= (unsigned int *) 0x002000; //端口A通道的地址(8255)
volatile unsigned int * DA_CHB= (unsigned int *) 0x002001; //端口B通道的地址(8255)
volatile unsigned int * DA_CHC= (unsigned int *) 0x002003; //控制字通道的地址(8255)


volatile unsigned int * A0CH= (unsigned int *) 0x80000; //A0通道的地址
///volatile unsigned int * A1CH= (unsigned int *) 0x80001; //A1通道的地址
///volatile unsigned int * B0CH= (unsigned int *) 0x80002; //B0通道的地址
///volatile unsigned int * B1CH= (unsigned int *) 0x80003; //B1通道的地址
///volatile unsigned int * A0CH1= (unsigned int *) 0x90000; //A01通道的地址
///volatile unsigned int * A1CH1= (unsigned int *) 0x90001; //A11通道的地址
///volatile unsigned int * B0CH1= (unsigned int *) 0x90002; //B01通道的地址
///volatile unsigned int * B1CH1= (unsigned int *) 0x90003; //B11通道的地址
//volatile unsigned int * ExRamStart = (unsigned  int *)0x100000;///外部RAM起始地址

long i=0;
///long Correlation_Shift=0;//存放相关函数最大值对应的点数位移
///double Correlation_Coefficient=0;//存放相关系数
double Capacitance=0;//存放电容值


//函数申明
void delay(unsigned int t);
void write_ad9833_d16(unsigned int x1,unsigned int x2);//向AD9833写16位数据操作
void ad9833_data(double frequence1,double frequence2,double Phase1,double Phase2,unsigned int frequence_SFR,unsigned int WAVE_MODE);//向AD9833写命令和数据（串行），//频率单位为MHz
//void ad5660_data(double voltage);//向AD5660写命令和数据（串行），单位V

void dac712_data(long voltage);//向dac712写命令和数据（串行），单位V

void data_acquire();//数据采集
void rms_calculation(long x[],long y[]);//计算信号的均方根值
///void correlation(long x[],long y[]);//相关函数
///void correlation_max(long x[]);//寻找相关函数最大值及点数位移
///void correlation_coefficient_calculation();//计算相关系数
void capacitance_calculation(long x[]);

void scia_init(void);

void getcheckcode(unsigned int x[],int num);//计算CRC校验数据并存放于crc,num 表示数组x的数据个数



void main()
{	 


	InitSysCtrl();/*初始化系统*/
	DINT;//禁止全局中断
	IER = 0x0000;//禁止CPU中断
	IFR = 0x0000;//清除所有CPU中断标志
	InitPieCtrl();/*初始化PIE中断*/
	InitPieVectTable();	/*初始化PIE中断矢量表*/
    InitSci(); /*初始化SCIA寄存器*/
	InitGpio();

//	EINT;   // Enable Global interrupt INTM
//	ERTM;	// Enable Global realtime interrupt DBGM

	GpioDataRegs.GPBDAT.all=0xFFFF;
    GpioDataRegs.GPEDAT.bit.GPIOE1=0;

	ad9833_data(500000,500000,0,45,0,2);//ad9833初始化

	///////开始485测试工作编程//////
	for(i = 0; i < 8; i++)
    {
  	Sci_Bufdec[i] = 0;
    }
    

    z = 0;
    Send_Flag = 0;

	#if SCIA_INT
	/*设置中断服务程序入口地址*/
	EALLOW;	
	PieVectTable.RXAINT = & SCIRXINTA_ISR;  //重点
	EDIS;   

	/*开中断*/
	IER |= M_INT9;
	#endif


	EALLOW;	
	PieVectTable.TINT0 = & ISRTimer0;  //指向定时器0的地址
	EDIS; 
    InitCpuTimers();
	ConfigCpuTimer(&CpuTimer0, 150, 1750); //设置CPU，后两个参数为时钟频率（MHz）和中断时间（us,需要大于30us），本程序中中断时间不得低于2.5us
    IER |= M_INT1;//逻辑或，中断使能
	PieCtrl.PIEIER1.bit.INTx7=1;

	EINT;   // Enable Global interrupt INTM
	ERTM;	// Enable Global realtime interrupt DBGM

//空满管写0
	for(i = 0; i < 55; i++)
    {
  	E_full[i] = 0;
	E_empty[i]= 0;
    }
    
///	ad5660_data(0.15);//ad5660初始化
	
//	for	(i=0;i<0x4000;i++)		*(ExRamStart + i) = i;
///	ReceivedChar=0x11;

   BBuf=0x0080;
   BBufL=BBuf & 0x00FF;
   * DA_CHC=BBufL;              //8255输入控制字


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

		dac712_data(9905);//dac712初始化0.09*16384/5
		GpioDataRegs.GPADAT.all=0x10;                    //case1
		delay(400);
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);

	    AD_Data1=* A0CH-32768;                
		AC_Case[0]=AD_Data1;                         //赋值到case1数中


		AD_Data1=0;
		

		dac712_data(5144);//ad5660初始化1.76*16384/5
		GpioDataRegs.GPADAT.all=0x20;                    //case2
		delay(400);
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[1]=AD_Data1;                         //赋值到case2数中
		
	    AD_Data1=0;
		


		dac712_data(5341);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x30;                    //case3
		delay(400);
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[2]=AD_Data1;                         //赋值到case3数中
		

	   	AD_Data1=0;
		

		dac712_data(4358);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x40;                    //case4
		delay(400);		
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[3]=AD_Data1;                         //赋值到case4数组中
		


	    
		AD_Data1=0;
		

		dac712_data(4368);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x50;                    //case5
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[4]=AD_Data1;                         //赋值到case5数组中
		


	    
		AD_Data1=0;
		

		dac712_data(4554);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x60;                    //case6
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[5]=AD_Data1;                         //赋值到case6数组中
		


	    
		AD_Data1=0;
		

		dac712_data(9263);//ad5660初始化3.43*16384/5
		GpioDataRegs.GPADAT.all=0x70;                    //case7
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[6]=AD_Data1;                         //赋值到case7数组中
		


	    
		AD_Data1=0;
		

		dac712_data(10557);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x21;                    //case8
		delay(400);
	
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[7]=AD_Data1;                         //赋值到case8数组中
		


	   
		AD_Data1=0;
		

		dac712_data(5635);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x31;                    //case9
		delay(400);
	
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[8]=AD_Data1;                         //赋值到case9数组中
		


		AD_Data1=0;
		

		dac712_data(4455);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x41;                    //case10
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[9]=AD_Data1;                         //赋值到case10数组中
		


	   
		AD_Data1=0;
		

		dac712_data(4423);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x51;                    //case11
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[10]=AD_Data1;                         //赋值到case11数组中
		


	    
		AD_Data1=0;
		


		dac712_data(4456);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x61;                    //case12
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[11]=AD_Data1;                         //赋值到case12数组中
		


	    
		AD_Data1=0;
		

		dac712_data(4588);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x71;                    //case13
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[12]=AD_Data1;                         //赋值到case13数组中
		


	    
		AD_Data1=0;
		

		dac712_data(9932);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x32;                    //case14
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[13]=AD_Data1;                         //赋值到case14数组中
		


	   
		AD_Data1=0;
		

		dac712_data(4654);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x42;                    //case15
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
     	AC_Case[14]=AD_Data1;                         //赋值到case15数组中
		


	    
		AD_Data1=0;
		


		dac712_data(4490);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x52;                    //case16
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[15]=AD_Data1;                         //赋值到case16数组中
		


	    
		AD_Data1=0;
		


		dac712_data(4490);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x62;                    //case17
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[16]=AD_Data1;                         //赋值到case17数组中
		


	    
		AD_Data1=0;
		

		dac712_data(4487);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x72;                    //case18
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[17]=AD_Data1;                         //赋值到case18数组中
		

	   
		AD_Data1=0;
		


		dac712_data(9105);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x43;                    //case19
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[18]=AD_Data1;                         //赋值到case19数组中
		


	    
		AD_Data1=0;
		


		dac712_data(4553);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x53;                    //case20
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[19]=AD_Data1;                         //赋值到case20数组中
		


	    
		AD_Data1=0;
		


		dac712_data(4381);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x63;                    //case21
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[20]=AD_Data1;                         //赋值到case21数组中
		


	    
		AD_Data1=0;
		

		dac712_data(4346);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x73;                    //case22
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[21]=AD_Data1;                         //赋值到case22数组中
		


	   
		AD_Data1=0;
		

		dac712_data(10504);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x54;                    //case23
		delay(400);
	
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[22]=AD_Data1;                         //赋值到case23数组中
		


	    
		AD_Data1=0;
		

		dac712_data(5175);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x64;                    //case24
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[23]=AD_Data1;                         //赋值到case24数组中
		


	    
		AD_Data1=0;
		

		dac712_data(5373);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x74;                    //case25
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[24]=AD_Data1;                         //赋值到case25数组中
		


	   
		AD_Data1=0;
		

		dac712_data(10755);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x65;                    //case26
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[25]=AD_Data1;                         //赋值到case26数组中
		


	    
		AD_Data1=0;
		

		dac712_data(5687);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x75;                    //case27
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[26]=AD_Data1;                         //赋值到case27数组中
		


	    AD_Data1=0;
		

		dac712_data(9882);//ad5660初始化
		GpioDataRegs.GPADAT.all=0x76;                    //case28
		delay(400);
		
		GpioDataRegs.GPBDAT.all=0x0000;//启动ADC数据转换
		delay(10);
		GpioDataRegs.GPBDAT.all=0xFFFF;
		delay(80);
	    AD_Data1=* A0CH-32768;                
		AC_Case[27]=AD_Data1;                         //赋值到case28数组中
		


	 for(i=0;i<N;i++)
		{
        if (AC_Case[i]>4096 || AC_Case[i]<0) Error=44;     //判断信号是否正常
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




//向AD9833写16位数据，严格按照这个时序，不能随意修改否则必出错
//GpioDataRegs.GPBDAT.bit.GPIOB3公用数据输入端DATA
//GpioDataRegs.GPBDAT.bit.GPIOB4第一个串行时钟输入端SLCK1
//GpioDataRegs.GPBDAT.bit.GPIOB5第二个串行时钟输入端SLCK2
//GpioDataRegs.GPBDAT.bit.GPIOB6低电平有效控制输入端FSYNC
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




//计算AD9833的28位数据并初始化

//变量frequence就是频率值，单位Hz，比如输入100Hz，则 frequence为100，需要特别注意的是不能超过12MHz；
//变量frequence_SFR是设置频率寄存器选择0为频率寄存器0,1为频率寄存器1；
//变量WAVE_MODE是设置输出波形选择0为三角波，1为方波,2为正弦波；
//变量Phase是设置波形相位值,单位是度;
 
void ad9833_data(double frequence1,double frequence2,double phase1,double phase2,unsigned int frequence_SFR,unsigned int WAVE_MODE)
{
	unsigned int frequence_LSB1,frequence_MSB1,Phs_data1,frequence_LSB2,frequence_MSB2,Phs_data2,phase_hex;
	double  frequence_DATA,phase_DATA;
	long int frequence_hex;
 
	
	//计算A9833_1频率的16进制值
	frequence_DATA=frequence1*268435456/25000000;	//如果时钟频率不为25MHZ，修改该处的频率值，单位MHz ，AD9833最大支持25MHz
	frequence_hex=frequence_DATA;  //这个frequence_hex的值是32位的一龊艽蟮氖郑枰鸱殖闪礁�14位进行处理；
	frequence_LSB1=frequence_hex; //frequence_hex低16位送给frequence_LSB
	frequence_LSB1=frequence_LSB1&0x3fff;//去除最高两位，16位数换去掉高位后变成了14位
	frequence_MSB1=frequence_hex>>14; //frequence_hex高16位送给frequence_HSB
	frequence_MSB1=frequence_MSB1&0x3fff;//去除最高两位，16位数换去掉高位后变成了14位
	//计算A9833_1相位的16进制�
	phase_DATA=phase1*4096/360;
	phase_hex=phase_DATA;
	Phs_data1=phase_hex|0xC000;


	//计算A9833_2频率的16进制
	frequence_DATA=frequence2*268435456/25000000;
	frequence_hex=frequence_DATA;  //这个frequence_hex的值是32位的一龊艽蟮氖郑枰鸱殖闪礁�14位进行处理；
	frequence_LSB2=frequence_hex; //frequence_hex低16位送给frequence_LSB
	frequence_LSB2=frequence_LSB2&0x3fff;//去除最高两位，16位数换去掉高位后变成了14位
	frequence_MSB2=frequence_hex>>14; //frequence_hex�16位送给frequence_HSB
	frequence_MSB2=frequence_MSB2&0x3fff;//去除最高两位，16位数换去掉高位后变成了14位
	//计算A9833_2相位的16进制值	
	phase_DATA=phase2*4096/360;
	phase_hex=phase_DATA;
	Phs_data2=phase_hex|0xC000;

	



	if(frequence_SFR==0)				  //把数据设置到设置频率寄存器0
	{
		frequence_LSB1=frequence_LSB1|0x4000;
 		frequence_MSB1=frequence_MSB1|0x4000;
 
 		frequence_LSB2=frequence_LSB2|0x4000;
		frequence_MSB2=frequence_MSB2|0x4000;

	//使用频率寄存器0输出波形
	write_ad9833_d16(0x0100,0x0100); //复位AD9833,即RESET位为1
	write_ad9833_d16(0x2100,0x2100); //选择数据一次写入，B28位和RESET位为1
	write_ad9833_d16(frequence_LSB1,frequence_LSB2); //L14，选择频率寄存器0的低14位数据输入
	write_ad9833_d16(frequence_MSB1,frequence_MSB2); //H14 频率寄存器的高14位数据输入
	write_ad9833_d16(Phs_data1,Phs_data2);//设置相位
	//write_ad9833_d16(0x2000); //设置FSELECT位为0，芯片进入工作状态,频率寄存器0输出波形
	}


	if(frequence_SFR==1)				//把数据设置到设置频率寄存器1
	{
		frequence_LSB1=frequence_LSB1|0x8000;
 		frequence_MSB1=frequence_MSB1|0x8000;
 
 		frequence_LSB2=frequence_LSB2|0x8000;
		frequence_MSB2=frequence_MSB2|0x8000;

 		//使用频率寄存器1输出波形
		write_ad9833_d16(0x0100,0x0100); //复位AD9833,即RESET位为1
		write_ad9833_d16(0x2100,0x2100); //≡袷菀淮涡慈耄珺28位和RESET位为1
		write_ad9833_d16(frequence_LSB1,frequence_LSB2); //L14，选择频率寄存器1的低14位数据输入
		write_ad9833_d16(frequence_MSB1,frequence_MSB2); //H14 频率寄存器的高14位数据输入
		write_ad9833_d16(Phs_data1,Phs_data2);//设置相位
		//write_ad9833_d16(0x2800); 设置FSELECT位为1，即使用德始拇嫫�1的值，芯片进牍ぷ髯船,频率寄存器1输出波形
	}



	
	if(WAVE_MODE==0)
	{
	//频率寄存器输出三角波波形
	delay(100);
	write_ad9833_d16(0x2002,0x2002); //设肕ODE位为1，输出三角波模式
	}



	if(WAVE_MODE==1)
	{
	//频率寄存器输出方波波形
	delay(100);
	write_ad9833_d16(0x2028,0x2028); //设置OPBITEN位为1，方波输出模式
	}


	if(WAVE_MODE==2)
	{
	//频率寄存器输出正弦波波形
	delay(100);
	write_ad9833_d16(0x2000,0x2000); //设置MODE位为0，输出正弦波模式
	}

}


//数模转换芯片DAC712输出配置
void dac712_data(long voltage)
{

    BBufL=voltage & 0x00FF;
	* DA_CHA =BBufL;
	BBufH=voltage>>8;
    * DA_CHB =BBufH;	
}



//数模转换芯片AD5660输出配置
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
		GpioDataRegs.GPBDAT.bit.GPIOB0=0;//启动ADC数据转换
		GpioDataRegs.GPBDAT.bit.GPIOB1=0;
		GpioDataRegs.GPBDAT.bit.GPIOB2=0;
		delay(10); //while(GpioDataRegs.GPFDAT.bit.GPIOF13==0);//等待ADC数据转换的完成
		
		GpioDataRegs.GPBDAT.bit.GPIOB0=1;//启动ADC数据保持
		GpioDataRegs.GPBDAT.bit.GPIOB1=1;
		GpioDataRegs.GPBDAT.bit.GPIOB2=1;
		delay(80);
		
		AD_Data1[i]=* A0CH-32768;
		if (AD_Data1[i]>4096 || AD_Data1[i]<0)//判断采集的信号是否正常
			Error=1;
		if (AD_Data1[i]>2047) 
			AD_Data1[i]=AD_Data1[i]-4096;

		AD_Data2[i]=* A1CH-36864;
		if (AD_Data2[i]>4096 || AD_Data2[i]<0)//判断采集的信号是否正常 
			Error=1;
		if (AD_Data2[i]>2047) 
			AD_Data2[i]=AD_Data2[i]-4096;

		AD_Data3[i]=* B0CH-40960;
		if (AD_Data3[i]>4096 || AD_Data3[i]<0)//判断采集的信号是否正常 
			Error=1;
		if (AD_Data3[i]>2047) 
			AD_Data3[i]=AD_Data3[i]-4096;

		AD_Data4[i]=* B1CH-45056;
		if (AD_Data4[i]>4096 || AD_Data4[i]<0)//判断采集的信号是否正常 
			Error=44;
		if (AD_Data4[i]>2047) 
			AD_Data4[i]=AD_Data4[i]-4096;

	    AD_Data5[i]=* A0CH1-32768;
		if (AD_Data5[i]>4096 || AD_Data5[i]<0)//判断采集的信号是否正常 
			Error=44;
		if (AD_Data5[i]>2047) 
			AD_Data5[i]=AD_Data5[i]-4096;

		AD_Data6[i]=* A1CH1-36864;
		if (AD_Data6[i]>4096 || AD_Data6[i]<0)//判断采集的信号是否正常 
			Error=44;
		if (AD_Data6[i]>2047) 
			AD_Data6[i]=AD_Data6[i]-4096;

		AD_Data7[i]=* B0CH1-40960;
		if (AD_Data7[i]>4096 || AD_Data7[i]<0)//判断采集的信号是否正常 
			Error=44;
		if (AD_Data7[i]>2047) 
			AD_Data7[i]=AD_Data7[i]-4096;

		AD_Data8[i]=* B1CH1-45056;
		if (AD_Data8[i]>4096 || AD_Data8[i]<0)//判断采集的信号是否正常 
			Error=44;
		if (AD_Data8[i]>2047) 
			AD_Data8[i]=AD_Data8[i]-4096;
	  
	
	}
	

}

*/
/*
void correlation(long x[],long y[])//x上游传感器信号，y下游传感器信号
{
	long i,j;
	double Correlation_Max=0;//存放相关函数最大值
	double Correlation_Result[400]={0};//存放相关函数值
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
	for(i=0;i<400;i++)    //寻找最大值
	{
		if(x[i]>Correlation_Max)
		{
			Correlation_Shift = i;
			Correlation_Max = x[i];
		}
	}	
	
		
    for(i=0;i<N;i++)//计算信号的均方根值	
	{
        tp1+=x[i]*x[i];
	    tp2+=y[i]*y[i];
	}
	rms=sqrt(tp1*tp2)/N;
	Correlation_Coefficient=Correlation_Max/(N-Correlation_Shift)/rms;
}



	

void capacitance_calculation(long x[])//计电容值
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



