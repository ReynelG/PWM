#include <string.h>
#include <fcntl.h>
#include "PWM.h"

// Defines constructor, Sets directories.
// Ports available: 0,2,4. Channels available: 0,1. (6 total).
PWM::PWM(std::string p, std::string dc, std::string port, std::string ch):Period(p),Duty_Cycle(dc),Port(port),Channel(ch){
	
	// FILE * PWM_ = NULL;
	std::string dir = "/sys/class/pwm/pwmchip"+Port+"/pwm-"+Port+":"+Channel+"/period";
	char * Period_dir = new char [dir.length()+1];
	std::strcpy (Period_dir, dir.c_str());
	int PWM_ = open(Period_dir, O_RDONLY);
	if(PWM_ == -1)
	{
		// Export creates directories for chosen port and channel
		std::string Export = "/sys/class/pwm/pwmchip"+Port+"/export"; 
		char * Export_dir = new char [Export.length()+1];
		std::strcpy (Export_dir, Export.c_str());
		char * CH = new char[Channel.length()+1];
		std::strcpy (CH, Channel.c_str());
		
		int PWM_ = open(Export_dir,O_WRONLY);
		if((PWM_ != -1)
		{
			int n =write(PWM_, CH, sizeof(char));
			close(PWM_);
		}
		delete[] Export_dir;
		delete[] CH;
	}
	else
	{
		close(PWM_);
	}
	delete[] Period_dir;
}
void PWM::run(){
	
	// FILE * PWM_ = NULL;
	
	std::string dir = "/sys/class/pwm/pwmchip"+Port+"/pwm-"+Port+":"+Channel+"/period";
	char * Period_dir = new char [dir.length()+1];
	std::strcpy (Period_dir, dir.c_str());		
	int PWM_ = open(Period_dir,O_WRONLY);
	char * P = new char [Period.length()+1];
	std::strcpy (P, Period.c_str());
	if(PWM_ != -1)
	{
		write(PWM_, P, Period.length(),);
		close(PWM_);
	}
	delete[] Period_dir;	
	delete[] P;
	
	dir = "/sys/class/pwm/pwmchip"+Port+"/pwm-"+Port+":"+Channel+"/enable";
	char * En_dir = new char [dir.length()+1];
	std::strcpy (En_dir, dir.c_str());
	int PWM_ = open(En_dir,O_WRONLY);
	if((PWM_ != -1)
	{
		write(PWM_,"1", sizeof(char));
		close(PWM_);
	}
	delete[] En_dir;
	
		
	dir = "/sys/class/pwm/pwmchip"+Port+"/pwm-"+Port+":"+Channel+"/duty_cycle";
	char * DC_dir = new char [dir.length()+1];
	std::strcpy (DC_dir, dir.c_str());
	char * DC = new char [Duty_Cycle.length()+1];
	std::strcpy (DC, Duty_Cycle.c_str());
	int PWM_ = open(DC_dir,O_WRONLY);
	if((PWM_ != -1)
	{
		write(PWM_, DC, Duty_Cycle.length());
		close(PWM_);
	}
	delete[] DC_dir;
	delete[] DC;
}
