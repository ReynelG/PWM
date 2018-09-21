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
 
 if((PWM = fopen(Export, "w")) != NULL)
 {
  fwrite("0", sizeof(char), 1, PWM);
 	fclose(PWM);
 }
 if((PWM = fopen(Period, "w")) != NULL)
 {
 	fwrite("1000000", sizeof(char), 1, PWM);
  fclose(PWM);
 }
 if((PWM = fopen(Enable, "w")) != NULL)
 {
 	fwrite("1", sizeof(char), 1, PWM);
 	fclose(PWM);
 }
int a = 1;
 while(a > 0)
 {
    if((PWM = fopen(Duty_cycle, "w")) != NULL)
	{
        fwrite("500", sizeof(char), 1, PWM);
	fclose(PWM);
	}
  	usleep(1000000);
    if((PWM = fopen(Duty_cycle, "w")) != NULL)
      	{
        fwrite("1000000", sizeof(char), 1, PWM);
        fclose(PWM);
      	}
	usleep(1000000);
 }   
return(0);
}
