#include <string.h>
#include "PWM.h"

PWM::PWM(std::string p, std::string dc, std::string port, std::string ch):Period(p),Duty_Cycle(dc),Port(port),Channel(ch){
	
	std::string Export = "/sys/class/pwm/pwmchip"+Port+"/export"; 
	char * Export_dir = new char [Export.length()+1];
	std::strcpy (Export_dir, Port.c_str());
	char * CH = new char[Channel.length()+1];
	std::strcpy (CH, Channel.c_str());
	FILE * PWM_ = NULL;
	if((PWM_ = fopen(Export_dir, "w")) != NULL)
	{
		fwrite(CH, sizeof(char), 1, PWM_);
		fclose(PWM_);
	}
	delete[] Export_dir;
	delete[] CH;
}
void PWM::run(){
	
	std::string dir = "/sys/class/pwm/pwmchip"+Port+"/pwm-"+Port+":"+Channel+"/period"
	char * Period_dir = new char [dir.length()+1];
	std::strcpy (Period_dir, dir.c_str());	
	while((PWM_ = fopen(Period_dir, "r+")) == NULL)
	{
		usleep(1);
	}
	
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
	delete[] Period_dir;	
	delete[] P;
	
	dir = "/sys/class/pwm/pwmchip"+Port+"/pwm-"+Port+":"+Channel+"/enable";
	char * En_dir = new char [dir.length()+1];
	std::strcpy (En_dir, dir.c_str());
	if((PWM_ = fopen(En_dir, "w")) != NULL)
	{
		fwrite("1", sizeof(char), 1, PWM_);
		fclose(PWM_);
	}
	delete[] En_dir;
	
	dir = "/sys/class/pwm/pwmchip"+Port+"/pwm-"+Port+":"+Channel+"/duty_cycle";
	char * DC_dir = new char [dir.length()+1];
	std::strcpy (DC_dir, dir.c_str());
	if((PWM_ = fopen(DC_dir, "w")) != NULL)
	{
		fwrite(DC, sizeof(char), 7, PWM_);
		fclose(PWM_);
	}
	delete[] DC_dir;
	delete[] DC;
}
