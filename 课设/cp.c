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