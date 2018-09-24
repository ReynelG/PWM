#include <iostream>
#include "PWM.h"
 
int main(){
	// Program for brightness
	char Percent[7];
	cin>>Percent;
	Percent[3] = "0";
	Percent[4] = "0";
	Percent[5] = "0";
	Percent[6] = "0";
	cout<<Percent;
	PWM Brightness("1000000",Percent);
	Brightness.run();
	return(0);
}
