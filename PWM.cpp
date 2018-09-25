#include <iostream>
#include <string.h>
#include "PWM.h"

 

PWM::PWM(std::string p, std::string dc):Period(p),Duty_Cycle(dc){
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
void PWM::run(){
	char * P = new char [Period.length()+1];
	std::strcpy (P, Period.c_str());
	char * DC = new char [Duty_Cycle.length()+1];
	std::strcpy (DC, Duty_Cycle.c_str());
	
	FILE * PWM_ = NULL;
		
	if((PWM_ = fopen(Period_dir, "w")) != NULL)
	{
		fwrite(P, sizeof(char), Period.length(), PWM_);
		fclose(PWM_);
	}
	if((PWM_ = fopen(En_dir, "w")) != NULL)
	{
		fwrite("1", sizeof(char), 1, PWM_);
		fclose(PWM_);
	}
	if((PWM_ = fopen(DC_dir, "w")) != NULL)
	{
		fwrite(DC, sizeof(char), 7, PWM_);
		fclose(PWM_);
	}
	delete[] P;
	delete[] DC;
}
// Default Value
PWM init("1000000","500000");
init.run();
