class PWM {
	const char *Export_dir = "/sys/class/pwm/pwmchip0/export";
	const char *Period_dir = "/sys/class/pwm/pwmchip0/pwm-0:0/period";
	const char *Enable_dir = "/sys/class/pwm/pwmchip0/pwm-0:0/enable";
	const char *Duty_cycle_dir = "/sys/class/pwm/pwmchip0/pwm-0:0/duty_cycle";
	char Period[10];
	char Duty_Cycle[10]
	public:
	PWM(char P[10], char DC[10])
	{
		FILE PWM = NULL;
		if((PWM = fopen(Export_dir, "r+")) != NULL)
		{
			fwrite("0", sizeof(char), 1, PWM);
			fclose(PWM);
		}
		if((PWM = fopen(Enable_dir, "r+")) != NULL)
		{
			fwrite("1", sizeof(char), 1, PWM);
			fclose(PWM);
		}
		Period = P;
		Duty_Cycle = DC;
	};
	void Change()
	{
		FILE PWM = NULL;
		if((PWM = fopen(Period_dir, "r+")) != NULL)
		{
			fwrite(Period, sizeof(char), 7, PWM);
			fclose(PWM);
		}
		if((PWM = fopen(Duty_cycle_dir, "r+")) != NULL)
		{
			fwrite(Duty_Cycle, sizeof(char), 7, PWM);
			fclose(PWM);
		}
	};
};
class Backlight{
	char Duty[7];
	public: 
	Backlight(char Percent[3]){
  		strcpy (Duty,Percent);
  		strcat (Duty,"0000");
	}
	PWM Brightness;
	Brightness.PWM("1000000",Duty);
	
};
