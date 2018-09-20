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
 if((PWM = fopen(Period, "r+")) != NULL)
 {
 	fwrite("10000", sizeof(char), 1, PWM);
  fclose(PWM);
 }
 if((PWM = fopen(Enable, "r+")) != NULL)
 {
 	fwrite("1", sizeof(char), 1, PWM);
 	fclose(PWM);
 }
 while(1)
 {
  for(int i = 0; i < 10000; i++)
  {
      if((PWM = fopen(Duty_cycle, "r+")) != NULL)
      {
        fwrite(std::to_string(i), sizeof(char), 1, PWM);
 		    fclose(PWM);
 	    }
  }
  usleep(100);
   for(int i = 10000; i > 0; i--)
  {
      if((PWM = fopen(Duty_cycle, "r+")) != NULL)
      {
        fwrite(std::to_string(i), sizeof(char), 1, PWM);
 		    fclose(PWM);
 	    }
  }
  usleep(100);
 }   
return(0);
}
