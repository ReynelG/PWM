#include <iostream>
#include <stdio.h>
#include <unistd.h>
 
using namespace std;
 
int main()
{
	FILE *PWM = NULL;
	const char *Export = "/sys/class/pwm/pwmchip0/export";
	const char *Period = "/sys/class/pwm/pwmchip0/pwm-0:0/period";
	const char *Enable = "/sys/class/pwm/pwmchip0/pwm-0:0/enable";
	const char *Duty_cycle = "/sys/class/pwm/pwmchip0/pwm-0:0/duty_cycle";
 
	if((PWM = fopen(Export, "r+")) != NULL)
	{
		fwrite("0", sizeof(char), 1, PWM);
		fclose(PWM);
	}
	while((PWM = fopen(Period, "r+")) == NULL)
	{
		usleep(1);
	}
	if((PWM = fopen(Period, "r+")) != NULL)
	{
		fwrite("1000000", sizeof(char), 7, PWM);
		fclose(PWM);
	}
	if((PWM = fopen(Enable, "r+")) != NULL)
	{
		fwrite("1", sizeof(char), 1, PWM);
		fclose(PWM);
	}
	char *test = new char[7];
	cin>> test;
	if((PWM = fopen(Duty_cycle, "r+")) != NULL)
	{
		fwrite(test, sizeof(char), 7, PWM);
		fclose(PWM);
	}
	return(0);
}
