#include <iostream>

int main(){
	// Default Value
	PWM init("1000000","500000");
	init.run();
	
	// Program for brightness
	std::string Percent;
	cin>>Percent;
	Percent = Percent + "0000";
	cout<<Percent;
	PWM Brightness("1000000",Percent);
	Brightness.run();
	return(0);
}
