#ifndef _PWM_H_
#define _PWM_H_

#include <stdio.h>
#include <unistd.h>

#define Export_dir "/sys/class/pwm/pwmchip0/export"
#define Period_dir "/sys/class/pwm/pwmchip0/pwm-0:0/period"
#define En_dir "/sys/class/pwm/pwmchip0/pwm-0:0/enable"
#define DC_dir "/sys/class/pwm/pwmchip0/pwm-0:0/duty_cycle"

using namespace std;


class PWM {
	char* Period = new char [8];
	char* Duty_Cycle = new char[8];
	
	public:
	// Default values, 50% duty cycle
	PWM(){
		strcpy(Period,"1000000");
		strcpy(Duty_Cycle,"500000");
		FILE * PWM_ = NULL;
		if((PWM_ = fopen(Export_dir, "w")) != NULL)
		{
		fwrite("0", sizeof(char), 1, PWM_);
		fclose(PWM_);
		}
		while((PWM_ = fopen(Period_dir, "w")) == NULL)
		{
			usleep(1);
		}
		
	}
	// Change value, nanoseconds
	PWM(std::string p, std::string dc){
		strcpy(Period,p);
		strcpy(Duty_Cycle,dc);
		FILE * PWM_ = NULL;
		if((PWM_ = fopen(Export_dir, "w")) != NULL)
		{
		fwrite("0", sizeof(char), 1, PWM_);
		fclose(PWM_);
		}
		while((PWM_ = fopen(Period_dir, "r+")) == NULL)
		{
			usleep(1);
		}
		
	} 
	void run(){
		FILE * PWM_ = NULL;
		if((PWM_ = fopen(Period_dir, "w")) != NULL)
		{
			fwrite(Period, sizeof(char), 7, PWM_);
			fclose(PWM_);
		}
		if((PWM_ = fopen(En_dir, "w")) != NULL)
		{
			fwrite("1", sizeof(char), 1, PWM_);
			fclose(PWM_);
		}
		if((PWM_ = fopen(DC_dir, "w")) != NULL)
		{
			fwrite(Duty_Cycle, sizeof(char), 7, PWM_);
			fclose(PWM_);
		}
		
	}
	delete[] Period;
	delete[] Duty_Cycle;
};
#endif
