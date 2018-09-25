#ifndef _PWM_H_
#define _PWM_H_

#include <stdio.h>
#include <unistd.h>
#include <string>
#include <cstring>

// PWM driver directories
#define Export_dir "/sys/class/pwm/pwmchip0/export"
#define Period_dir "/sys/class/pwm/pwmchip0/pwm-0:0/period"
#define En_dir "/sys/class/pwm/pwmchip0/pwm-0:0/enable"
#define DC_dir "/sys/class/pwm/pwmchip0/pwm-0:0/duty_cycle"

using namespace std;


class PWM {
	private:
	std::string Period;		//PWM period, nanoseconds
	std::string Duty_Cycle;		//PWM Duty cycle, nanoseconds
	
	public:
	PWM(std::string, std::string);	//Constructor, creates the directories.
	void run();			//Starts
	};
#endif
