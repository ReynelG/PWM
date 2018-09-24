#include <iostream>
#include <string>
#include "PWM.h"
 
using namespace std;
 
int main()
{
	// Program for brightness
	std::string Percent;
	cin>>Percent;
	Percent.append("0000");
	PWM Brightness("1000000",Percent);
	Brightness.run();	
}
