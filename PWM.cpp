#include <iostream>
#include <string.h>
#include "PWM.h"

 
int main(){
	// Program for brightness
	char* Percent;
	cin>>Percent;
	strcat(Percent,"0000")
	cout<<Percent;
	PWM Brightness("1000000",Percent);
	Brightness.run();
	return(0);
}
