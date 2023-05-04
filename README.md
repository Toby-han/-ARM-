# -ARM-

基于ARM的汽车触控式影音系统设计

一、实训目的

1.1 实训要求

1、使用C语言编制基于Linux系统触控式影音系统，能够在汽车驾驶舱内方便高效的实现触控式人机交互，操作界面显示版权人的基本信息；
2、影音系统能够上传、播放音视频内容，包括自动和手动切换、特效、播放、暂定、进度条等功率；
3、将程序写入GEC-ARM6818单片机系统，并在电容屏的触控式系统上验证。
4、完成400条以上的程序语句，并做必要的批准，完成实训报告，5000字，现场演示，答辩。
1.2 应用背景

国内车载移动多媒体市场的发展，已经走在“市场集中”的轨道上。市场集中这一概念包括：行业品牌企业的集中、产品质量的集中以及渠道的集中。“市场集中”这一特定的市场竞争格局，是每个产业历经原始自然竞争、混乱市场局面、行业自律整顿以及国家商业环境法制化进程共同培育出的结果。目前行业所处的时代背景，正在“市场集中”的当下。经历中国特殊国情和市场条件下所谓的“山寨化”运动，必将催生了一批国内车载移动多媒体优秀的企业和品牌。品牌企业不断集中的过程，是市场自然选择和企业主动推动的结果，大者恒大不但是商场的一个永恒定律，是消费者选择的结果。消费者最终会将信任的橄榄枝抛向能够长久经营的品牌企业，以保障电子产品够伴随自己消费成长的，为自己所购买的产品进行售后服务。品牌企业的集中，也将产品的质量进行了同步的集中。在汽车移动多媒体市场，大厂家的产品质量稳定是一个常态，而很多小企业或山寨厂的产品，因为资源体系、研发和生产的不足，常常导致产品品质不稳定。渠道销售通路的集中和顺畅，则是大品牌企业集资本、品牌运作、渠道资源和推广等不断优化的结果，建立和完善广泛的终端网点，让销售通路更加顺畅。
车载多媒体应用在我国即将形成一个产业满足国内外市场不断上扬的市场需求，目前行业仍处于淘汰弱小、推出新标准的阶段。未来几年，汽车多媒体影音电子市场，从企业发展、产品升级以及市场渠道的运作，都将迎来一场巨大的变革，行业“寡头”引导发展的市场格局将越来越清晰，这是一个大的方向。
 
二、实训器材

2.1 S5P6818 核心板

GEC6818 开发平台，核心板采用 8 层板工艺设计， 确保稳定可靠，可以批量用于平板电脑，车机，学习机，POS 机，游戏机，行业监控等多种领域。该平台搭载三星 Cortex-53系列高性能处理器 S5P6818，八核，最高主频高达 1.4GHz，可应用于嵌入式操作系统的高端应用开发。开发板留有丰富的外设，支持千兆以太网、板载 LVDS 接口、MIPI 接口、PCIE接口等。
GEC6818 开发平台支持三大操作系统，具备完整的教学资源和教学内容，包括：ARM微处理器系统驱动的实验、嵌入式实时操作系统 Linux 开发、嵌入式 Android 系统开发、嵌入式 Android 应用开发、嵌入式系统项目实战开发等内容。
 
图2.1  S5P6818 核心板

S5P6818 核心板采用邮票孔的核心板方式设计，核心板可扩展性强，多达 180PIN 管脚，运行速度高达 1.4GHz。PCB 采用 8 层沉金工艺设计，具有最佳的电气特性和抗干扰特性，工作稳定可靠。核心板板载了足以胜任 S5P6818 的 PMU AXP228，带库仑计的充电管理，同时支持 S5P4418 和 S5P6818 正常工作，并集成千兆以太网，可以广泛应用于 MID，POS，PDA，PND，智能家居，手机，车机，学习机，游戏机以及其他各种工控领域。
S5P6818 采用 28nm 制作工艺，内置高性能八核 ARM Cortex-A53 处理器架构，在多媒体性能上， 它几乎支持全格式视频解码，在 LCD 控制器上，芯片板载 LVDS、RGB、MIPI三路显示控制接口，显示分辨率可以高达 2048*1280@60Hz。同时，内部集成千兆以太网控制器，令很多对网络有更高要求的客户垂涎三尺。
GEC6818 的嵌入式开发平台出色的性能，能够完美展现芯片的绝大多数功能，可以大大缩短用户的开发周期。GEC6818 嵌入式开发在设计之初，就充分考虑了 S5P6818 的芯片特性，同时考虑到了很多实际应用场景。从软硬件整体考虑，即大大节约了用料成本，又很完美的将芯片本身的性能发挥到极致，教学、科研以及企业用户的学习与借鉴具有非常大的意义。
  
图2.2  特性参数

GEC-S5P6818 核心板具有以下特性：
1、	最佳尺寸，即保证精悍的体积又保证足够的 GPIO 口，仅 68mm*48mm；
2、	使用 AXP228 PMU 电源管理设计，在保证工作稳定可靠的同时，成本足够低廉；
3、	支持多种品牌，多种容量的emmc，默认使用东芝 8GB emmc(19nm MLC 工艺)；
4、	使用单通道 DDR3 设计，默认支持 1GB 容量，可定制 2GB 容量；
5、	支持电源休眠唤醒；
6、	支持 Linux、android5.1、Ubuntu 嵌入式操作系统；
7、	板载千兆有线以太网；
 
2.2 GEC6818开发板底板

GEC6818 开发平台，主要包含核心板、开发板底板。
 
图2.3  GEC6818开发板底板
常用接口说明
1、电源接口
 
为开发平台总电源接口为 CN1，如上图所示，我们提供的电源适配器的输出电压为DC5V。
2、调试串口
 
开发平台预留 RS232 串口，分别为 UART0。默认使用 UART0 作为调试串口，UART0为标准 DB9 接口。你可以通过附带的交叉串口线和 PC 进行通讯。
3、USB OTG 接口
 
该接口用于程序烧写，同步等。它还能通过 OTG 线实现 HOST 的功能。
4、以太网接口
 
开发平台支持千兆有线以太网接口，板载 RTL8211E，用户可以通过有线以太网上网，体验极速网络。
5、TF 卡槽
 
开发平台引出两个外置 TF 卡，对应 S5P6818 的通道 0 和通道 1，默认可以通过 SD0 进行 TF 卡升级，或是存放一些多媒体文件。
6、HDMI 接口
 
开发平台采用 HDMI 接口，配合 HDMI 的延长线，可以将音视频信号完美的呈现在支持 HDMI1.4 协议的监控终端，如电视机，显示器等。
7、camera 接口（并口）
 
该接口为通用的 24PIN 并口摄相头接口，支持 OV 全系列摄相头，省去 camera 转接板。针对不同型号的摄相头，只需按照摄相头的规格，调整一下输出电压就行了。同时，该接口可兼容配套的 TVP5150，TVP5146 等 AVIN 模块。
8、camera 接口（MIPI CSI 接口）
 
该接口为通过的 26PIN MIPI 摄相头接口，用于驱动高分辨率的 MIPI 摄相头。
9、音频接口
 
一个 3.5mm 音频输入接口（红色）,一个 3.5mm 输出接口（绿色），可直接接耳机，用于音频的播放和录制。
10、USB HOST 接口
 
S5P6818 自带有 USB HOST 接口，开发平台通过该 HOST 接口扩展出了 3 路 USBHOST2.0 接口，其中 2 路通过标准的 TypeA 接口引出，可用于连接 USB WIFI，USB 蓝牙，USB 鼠标键盘等，1 个用于总线扩展。
11、LCD 接口（RGB 接口）
 
开发平台底板默认留有一个 40PIN 的 LCD 接口，通过软排线将 RGB 相关信号连接到LCD 控制板上，进而控制 LCD 和显示。
LCD 电容触摸屏：7寸 800x480 分辨率，LCD 型号为 AT070TN92。
 
三、实训内容
3.1 程序流程图
 
图3.1  主界面流程图
 
图3.2  相册界面流程图
 
图3.3  音视频界面流程图

 
3.2 设计程序
#include <stdio.h>

//open函数的头文件
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//read、write、close函数的头文件
#include <unistd.h>

//mmap munmap 的头文件
#include <sys/mman.h>

#include <string.h>

//输入子系统的头文件
#include <linux/input.h>

//pthrad线程的头函数
#include <pthread.h>

//system函数的头文件
#include <stdlib.h>

//定义全局变量 来获取X轴Y轴的值
int tx = 0;
int ty = 0;


//相册的存
//数组的下标是从0开始的    buf_lcd[0] = 1.bmp   buf_lcd[1] = 2.bmp  ..... 
char buf_lcd[5][10]={
	"1.bmp",
	"2.bmp",
	"3.bmp",
	"4.bmp",
	"5.bmp"
};

/*
将刷写图片的代码封装一下
1.打开LCD屏的驱动
2.打开一个BMP格式的图片（800*480）
3.偏移图片（BMP格式的图片前54个字节是图片的信息）
4.申请一个内存映射
5.读取图片的信息
6.更改色深    BMP图片一个像素点有3个色素RGB    LCD屏一个像素点有四个色素ARGB
7.关闭相关的文件
*/
//最终的目的是在任意的地方、刷任意大小的图片
//图片的名字、图片的长与宽、在lCD屏刷写位置X、Y轴、特效
int showbmp_wh_xy(char *pathname,int w,int h,int x0,int y0,int flag)
{
	//1.打开LCD屏的驱动
	int fd = open("/dev/fb0",O_RDWR);
	if(fd <= -1)
	{
		printf("LCD屏打开失败\n");
		return -1;
	}
	
	//2.打开BMP格式的图片
	int fd_bmp = open(pathname,O_RDWR);
	if(fd_bmp <= -1)
	{
		printf("图片打开失败\n");
		return -1;
	}
	
	//3.偏移图片  前54个字节
	lseek(fd_bmp,54,SEEK_SET);
	
	//4.申请内存的映射
	char *lcd_bmp = mmap(
						NULL,
						800*480*4,
						PROT_READ|PROT_WRITE,
						MAP_SHARED,
						fd,
						0
						);
						
	//5.读取图片的相关信息
	char buf[w*h*3];
	//清空数组
	bzero(buf,w*h*3);
	
	read(fd_bmp,buf,w*h*3);
	
	//6.更改BMP格式图片的色深并写入我们的内存映射
	int x,y;
	
	if(flag == 0)
	{
		for(x = x0; x < x0+w; x++)
		{
			for(y = y0;y < y0+h; y++)
			{
				lcd_bmp[0+4*x+800*4*y] = buf[0+3*(x-x0)+w*3*((h-1)-(y-y0))] ;  //B蓝色
				lcd_bmp[1+4*x+800*4*y] = buf[1+3*(x-x0)+w*3*((h-1)-(y-y0))] ;  //G绿色
				lcd_bmp[2+4*x+800*4*y] = buf[2+3*(x-x0)+w*3*((h-1)-(y-y0))] ;  //R红色
				lcd_bmp[3+4*x+800*4*y] = 0 ;  //A透明度
			}
		}
	
	}
	else if(flag == 1)
	{
		for(x = x0; x < x0+w; x++)
		{
			for(y = y0;y < y0+h; y++)
			{
				lcd_bmp[0+4*x+800*4*y] = buf[0+3*(x-x0)+w*3*((h-1)-(y-y0))] ;  //B蓝色
				lcd_bmp[1+4*x+800*4*y] = buf[1+3*(x-x0)+w*3*((h-1)-(y-y0))] ;  //G绿色
				lcd_bmp[2+4*x+800*4*y] = buf[2+3*(x-x0)+w*3*((h-1)-(y-y0))] ;  //R红色
				lcd_bmp[3+4*x+800*4*y] = 0 ;  //A透明度
			}
			usleep(3000);
		}
	}
	
	//7.关闭相关的文件
	munmap(lcd_bmp,800*480*4);
	
	close(fd_bmp);
	close(fd);	
}

//获取开发板X轴Y轴的值
int get_xy()
{
	//1.打开输入子系统的驱动 /dev/input/event0
	int fd_cm = open("/dev/input/event0",O_RDWR);
	if(fd_cm <= -1)
	{
		printf("输入子系统打开失败\n");
		return -1;
	}
	
	//2.等待输入子系统反应  定义一个结构体
	struct input_event tt;
	while(1)
	{
		read(fd_cm,&tt,sizeof(tt));
	
		//3.判断一下事件 绝对位移获取X轴Y轴的坐标
		if(tt.type == EV_ABS)
		{
			//X轴坐标
			if(tt.code == ABS_X)
			{
				//将LCD屏的X轴坐标赋值给X
				tx = tt.value*800/1024;
				//  黑色底板的开发板需要改一下
				//  x = tt.value*800/1024;（黑色底板）
				//printf("X轴的坐标：%d\n",tx);
			}
			//Y轴的坐标
			if(tt.code == ABS_Y)
			{
				//将LCD屏的Y轴的坐标赋值给Y
				ty = tt.value*480/600;
				// y = tt.value*480/600;(黑色底板)
				//printf("Y轴的坐标:%d\n",ty);
			}
		}
		
		//4.按压事件    按下 value的值为1   拿起value的值为0
		if(tt.type == EV_KEY)
		{
			if(tt.code == BTN_TOUCH)
			{
				if(tt.value == 0)
				{
					printf("x:%d  y:%d\n",tx,ty);
					break;
				}
			}
		}	
	}
	
	
	//5.关闭相关的文件
	close(fd_cm);
	
}

//开始界面图、进度条等准备工作
int stat_bmp()
{
	//刷一张开始的图   (背景图)
	showbmp_wh_xy("1.bmp",800,480,0,0,0);
	//刷一张开始图片
	showbmp_wh_xy("kaishitu.bmp",200,100,350,200,0);
	//触摸开始图片进入主界面
	printf("点击开始图片可以进入主界面\n");
	//判断坐标
	while(1)
	{
		//获取坐标
		//get_xy();
		//判断开始图片的范围，若是没有选中开始图片的范围则不会退出循环
		if(tx > 350 && ty > 200 && tx < 550 && ty < 300)
		{
			tx = 0;
			ty = 0;
			//打印进度条
			showbmp_wh_xy("jindutiao.bmp",700,70,50,400,1);
			sleep(2);
			break;
		}
	
	}
	
	//打印一个主界面
	showbmp_wh_xy("zhujiemian.bmp",800,480,0,0,0);
}

//相册功能的手动
int shoudong()
{
	int i = 0; //定义一个标志位来查看图片
	//打印我们存储图片的第一张
	showbmp_wh_xy(buf_lcd[i],800,480,0,0,0);
	while(1)
	{
		//获取坐标
		//get_xy();
		//判断是上一张还是下一张
		//上一张
		if(tx > 0 && ty > 0 && tx < 100 && ty < 100)
		{
			tx = 0;
			ty = 0;
			i++;
			if(i > 4)
			{
				i = 0;
			}
			showbmp_wh_xy(buf_lcd[i],800,480,0,0,0);
		}
		//下一张
		if(tx > 0 && ty > 380 && tx < 100 && ty < 480 )
		{
			tx = 0;
			ty = 0;
			i--;
			if(i < 0)
			{
				i = 4;
			}
			showbmp_wh_xy(buf_lcd[i],800,480,0,0,0);
		}
		//退出
		if(tx > 700 && ty > 0 && tx < 800 && ty < 100)
		{
			//X轴Y轴置为0的原因
			tx = 0;
			ty = 0;
			break;
		}	
	}
	
}

//相册功能的自动
int zidong()
{
	//循环
	for(int i = 0; i < 5;i++)
	{
		//打印图片
		showbmp_wh_xy(buf_lcd[i],800,480,0,0,0);
		sleep(3);
	}
}


//相册的功能
int photo()
{
	//打印相册的界面
	showbmp_wh_xy("xiangcejiemian.bmp",800,480,0,0,0);
	//获取坐标
	while(1)
	{
		//get_xy();
		//获取坐标的 ------ 手动
		if(tx > 70 && ty > 80 && tx < 410 && ty < 400)
		{
			//提示手动功能
			printf("进入相册的手动功能\n");
			tx = 0;
			ty = 0;
			//手动功能
			shoudong();
			//打印相册的主界面
			showbmp_wh_xy("xiangcejiemian.bmp",800,480,0,0,0);
		}
		//获取坐标的  ------- 自动
		if(tx > 430 && ty > 80 && tx < 750 && ty <400)
		{
			//提示 自动功能
			printf("进入相册的自动功能\n");
			tx = 0;
			ty = 0;
			//自动功能
			zidong();
			//打印相册的主界面
			showbmp_wh_xy("xiangcejiemian.bmp",800,480,0,0,0);
		}
		//退出相册的界面
		if(tx > 700 && ty > 0 && tx < 800 && ty < 100)
		{
			tx = 0;
			ty = 0;
			break;
		}
	}
	
	
}

	
void music()
{
	//创建一个管道
	system("rm pipo");
	system("mkfifo pipo");
	//system("chmod 777 /pipo");
	
	//打印一个控制界面
	showbmp_wh_xy("yy.bmp",800,480,0,0,0);
	
	
	
	//
	while(1)
	{
		//获取X轴Y轴的值
		get_xy();
		//判断一下范围
		if(tx > 340 && ty > 380 && tx < 450 && ty < 480)
		{
			tx = 0;
			ty = 0;
			//音频的暂停
			system("echo pause >> /pipo");
			//向管道里写命令  播放音频  补全  
	system("mplayer -slave -quiet -input  file=/pipo yy.mp3 &");
			
		}
		
		if(tx > 500 && ty > 380 && tx < 630 && ty < 480)
		{
			tx = 0;
			ty = 0;
			//音频的快进
			system("echo seek +5 >> /pipo");

		}
		if(tx > 160 && ty > 380 && tx < 300 && ty < 480)
		{
			tx = 0;
			ty = 0;
			//音频的快退
			system("echo seek -5 >> /pipo");    
		}
		if(tx > 680 && ty > 380 && tx < 800 && ty < 480)
		{
			tx = 0;
			ty = 0;
			//音频的增大
			system("echo volume +5 >> /pipo");
		}
		if(tx > 0 && ty > 380 && tx < 120 && ty < 480)
		{
			tx = 0;
			ty = 0;
			//音频的减小
			system("echo volume -5 >> /pipo");
		}
		if(tx > 700 && ty > 0 && tx < 800 && ty < 100)
		{
			tx = 0;
			ty = 0;
			//退出
			system("killall -kill mplayer");
			break;
		}
	}
}

void video()
{		
	//创建一个管道
	system("rm pipo");
	system("mkfifo pipo");
	//system("chmod 777 /pipo");	

	
	
	//
		//打印一个控制界面
	showbmp_wh_xy("kongzhi.bmp",800,100,0,380,0);
	while(1)
	{
		//获取X轴Y轴的值
		get_xy();
		//判断一下范围
		if(tx > 340 && ty > 380 && tx < 450 && ty < 480)
		{
			tx = 0;
			ty = 0;
			//视频的暂停
			system("echo pause >> /pipo");

	//向管道里写命令
	system("mplayer -slave -quiet -input file=/pipo -geometry 0:0 -zoom -x 800 -y 380 666.avi &");			
		}
		
		if(tx > 500 && ty > 380 && tx < 630 && ty < 480)
		{
			tx = 0;
			ty = 0;
			//视频的快进
			system("echo seek +5 >> /pipo");
		}
		if(tx > 160 && ty > 380 && tx < 300 && ty < 480)
		{
			tx = 0;
			ty = 0;
			//视频的快退
			system("echo seek -5 >> /pipo");
		}
		if(tx > 680 && ty > 380 && tx < 800 && ty < 480)
		{
			tx = 0;
			ty = 0;
			//音量的增大
			system("echo volume +5 >> /pipo");
		}
		if(tx > 0 && ty > 380 && tx < 120 && ty < 480)
		{
			tx = 0;
			ty = 0;
			//音量的减小
			system("echo volume -5 >> /pipo");
		}
		if(tx > 700 && ty > 0 && tx < 800 && ty < 100)
		{
			tx = 0;
			ty = 0;
			//退出
			system("killall -kill mplayer");
			break;
		}
	}	
}

//线程函数      获取触摸屏X轴Y轴的值
void *fun(void *arg)
{
	while(1)
	{
		get_xy();
	}
}

int main()
{
	//提示以用线程获取X轴Y轴的值：
	printf("以用线程获取X轴Y轴的值\n");
	//创建线程优化代码
	pthread_t pit;
	pthread_create(&pit,NULL,fun,NULL);
	//前奏   背景图、开始、进度条、主界面
	stat_bmp();
	while(1)
	{
		//获取坐标
		//get_xy();
		//判断一下  相册 、音频还是视频
		//相册
		if(tx > 170 && ty > 180 && tx < 250 && ty < 280)
		{
			//提示进入相册功能
			printf("欢迎进入相册\n");
			tx = 0;
			ty = 0;
			//相册的函数
			photo();
			//打印主界面
			showbmp_wh_xy("zhujiemian.bmp",800,480,0,0,0);
			
		}
		//音频
		if(tx > 360 && ty > 180 && tx < 430 && ty < 280)
		{
			tx = 0;
			ty = 0;
			//音频功能
			music();
			//打印主界面
			showbmp_wh_xy("zhujiemian.bmp",800,480,0,0,0);
		}
		//视频
		if(tx > 540 && ty > 180 && tx < 630 && ty < 280)
		{
			printf("进入视频功能\n");
			tx = 0;
			ty = 0;
			//视频的播放
			video();
			//打印主界面
			showbmp_wh_xy("zhujiemian.bmp",800,480,0,0,0);
		}
		//退出0
		if(tx > 670 && ty > 0 && tx < 800 && ty < 50)
		{
			tx = 0;
			ty = 0;
			//退出时可以刷一个退出图片
			showbmp_wh_xy("end.bmp",800,480,0,0,0);
			break;
		}
	
	}
	
	return 0;
}
3.3 设计结果
 
图3.1  开始界面
 
3.2  主界面

 
图3.3  相册功能选择界面

 
图3.4  相册播放界面
 
图3.5  音乐播放界面

 
图3.6  视频播放界面
 
图3.7  结束界面
 
四、实训心得与体会
本课题是做一个基于GEC-6818开发平台的娱乐影音模块，利用定制的Linux系统，通过C语言的编程，经过交叉编译环境，让编译的文件能够直接适用于ARM开发板。用7寸LCD电容式触摸屏作为人机互交的方式，可以切换相册、音乐、视频的功能，显示相应的界面。
但是本系统依然存在一些不足，如：
1、图片模块中展示的图片只能为bmp格式，其他格式无法显示；并且图片不能放大缩小。 
2、视频模块未设置进度条，只能通过快进/快退按键调节观看速度。 

五、参考文献
[1] 岳浩 《Linux操作系统教程》[J].机械工业出版社,2005.4 
[2] 刘志国 《练就Linux系统高手教程》[J].延边出版社,2006.1 
[3] 毛德操 胡希明《Linux内核源代码情景分析》[D].2016.3
