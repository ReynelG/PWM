#ifndef _PWM_H_
#define _PWM_H_

#define Export_dir "/sys/class/pwm/pwmchip0/export"
#define Period_dir "/sys/class/pwm/pwmchip0/pwm-0:0/period"
#define En_dir "/sys/class/pwm/pwmchip0/pwm-0:0/enable"
#define DC_dir "/sys/class/pwm/pwmchip0/pwm-0:0/duty_cycle"

class PWM {
	std::string Period, Duty_Cycle;
	
	public:
	PWM(std::string p, std::string dc): Period(p),Duty_Cycle(dc){};
	};
class Backlight{
	std::string Percent;
	public: 
	Backlight(std::string p): Percent(p){};
	PWM Brightness;	
};
#endif
