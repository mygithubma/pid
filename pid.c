#include<stdio.h>
struct _pid
{
	float error;    //记录差值
	float error_last;   //上一次差值
	float integral;     //差值的和
};	


float Kp=0.01;     //比例系数   用于控制提升的速度
float Ki=0.16;     //积分系数  用于稳定最终的数值
float Kd=0.01;     //微分系数   减少震荡

float cur_speed=0;  //表示当前的速度
float level=0;
float set_speed=50;  //设定的速度

struct _pid pid;
void pid_init()
{
	pid.error=0;
	pid.error_last=0;
	pid.integral=0;
}

void pid_control()
{
	pid.error=set_speed-cur_speed;
	pid.integral+=pid.error;

  level=Kp*pid.error+Ki*pid.integral+Kd*(pid.error-pid.error_last);
	pid.error_last=pid.error;
	cur_speed=level*5;		
}

int main()
{
	int i;
	pid_init();
	for(i=0;i<10;i++)
	{	
		pid_control();
		printf("当前速度 %f--等级是 %f\n",cur_speed,level);
	}
	return 0;
}