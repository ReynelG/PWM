#include <iostream>
#include "PWM.h"

int main(){
	// Program for brightness
	std::string Percent;
	cin>>Percent;
	Percent = Percent + "0000";
	cout<<Percent;
	PWM Brightness("1000000",Percent,"0","0");
	Brightness.run();
	return(0);
}
