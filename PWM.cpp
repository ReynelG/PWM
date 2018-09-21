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
 // Habilita el uso de pwm0 - A
 if((PWM = fopen(Export, "r+")) != NULL)
 {
  fwrite("0", sizeof(char), 1, PWM);
 	fclose(PWM);
 }
// Espera a que se cree el directorio "/sys/class/pwm/pwmchip0/pwm-0:0/"
 while((PWM = fopen(Period, "r+")) == NULL)
	{
		usleep(1);
	}
	
// Cambia el periodo de 0 a 1 ms
 if((PWM = fopen(Period, "r+")) != NULL)
 {
 	fwrite("1000000", sizeof(char), 7, PWM);
  fclose(PWM);
 }
 // Enciende el puerto pwm
 if((PWM = fopen(Enable, "r+")) != NULL)
 {
 	fwrite("1", sizeof(char), 1, PWM);
 	fclose(PWM);
 }
// Cambia el ciclo de trabajo entre 10% y 99% con espera de 1 s entre ellos.
while(1)
{
 
 if((PWM = fopen(Duty_cycle, "r+")) != NULL)
 {
	fwrite("100000", sizeof(char), 6, PWM);
	fclose(PWM);
 }
usleep(1000000);
 if((PWM = fopen(Duty_cycle, "r+")) != NULL)
 {
	fwrite("990000", sizeof(char), 6, PWM);
	fclose(PWM);
 }
usleep(1000000);
}
   
return(0);
}
