// UVa-10209: Is This Integration?.cpp
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
#define pi (2.0*acos(0.0))

int main(void)
{
	double a;              					// a: side length 
	while(cin >> a)
	{
		// pre-calculate some regions(as tools in the next step)
		double a1, a2, a3;					
		a1=(a*a)-(a*a*pi/4.0);  			// a1=y+2z
		a2=(a*a*pi/6.0)-(a*a*sqrt(3.0)/4.0); 		// a2=w
		a3=(a*a*pi*1/4.0)-(a*a*pi*1/6.0); 		// a3=y+z+w

		// calculate the area of the three regions
		double x, y, z;    				
		z=a1-a3+a2;  					// z=(y+2z)-(y+z+w)+w
		y=a1-2.0*z;  					// y=(y+2z)-2z
		y*=4.0; z*=4.0;  				// total region of y and z
		x=a*a-y-z;       				// x=square-y-z
		
		printf("%.3lf %.3lf %.3lf\n", x, y, z);
	}
	
	return 0;
}
