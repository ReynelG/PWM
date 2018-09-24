#ifndef _PWM_H_
#define _PWM_H_

#include <stdio.h>
#include <unistd.h>

#define Export_dir "/sys/class/pwm/pwmchip0/export"
#define Period_dir "/sys/class/pwm/pwmchip0/pwm-0:0/period"
#define En_dir "/sys/class/pwm/pwmchip0/pwm-0:0/enable"
#define DC_dir "/sys/class/pwm/pwmchip0/pwm-0:0/duty_cycle"



class PWM {
	std::string Period, Duty_Cycle;
	
	public:
	// Default values, 50% duty cycle
	PWM():Period("1000000"),Duty_Cycle("500000"){
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
		
	};
	// Change value, nanoseconds
	PWM(std::string p, std::string dc): Period(p),Duty_Cycle(dc){
		FILE * PWM_ = NULL;
		if((PWM_ = fopen(Export_dir, "w")) != NULL)
		{
		fwrite("0", sizeof(char), 1, PWM);
		fclose(PWM_);
		}
		while((PWM_ = fopen(Period_dir, "r+")) == NULL)
		{
			usleep(1);
		}
		
	}; 
	void run(){
		FILE * PWM_ = NULL;
		if((PWM_ = fopen(Period_dir, "w")) != NULL)
		{
			fwrite(Period, sizeof(std::string), 1, PWM_);
			fclose(PWM_);
		}
		if((PWM_ = fopen(En_dir, "w")) != NULL)
		{
			fwrite("1", sizeof(char), 1, PWM_);
			fclose(PWM_);
		}
		if((PWM_ = fopen(DC_dir, "w")) != NULL)
		{
			fwrite(Duty_Cycle, sizeof(std::string), 1, PWM_);
			fclose(PWM_);
		}
		
	};
#endif
