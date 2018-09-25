#include <iostream>
#include <string.h>
#include "PWM.h"

 
int main(){
	// Program for brightness
	std::str Percent;
	cin>>Percent;
	Percent = Percent + "0000";
	cout<<Percent;
	PWM Brightness("1000000",Percent);
	Brightness.run();
	return(0);
}
