
class PWM {
	const char *Export = "/sys/class/pwm/pwmchip0/export";
	const char *Period = "/sys/class/pwm/pwmchip0/pwm-0:0/period";
	const char *Enable = "/sys/class/pwm/pwmchip0/pwm-0:0/enable";
	const char *Duty_cycle = "/sys/class/pwm/pwmchip0/pwm-0:0/duty_cycle";public:
	PWM(){
		
	};
};
