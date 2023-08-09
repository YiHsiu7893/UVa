// UVa-10104: Euclid Problem.cpp
#include <iostream>
#include <cstdlib>
using namespace std;

int gcd(int A, int B, int &X, int &Y)  	// modify X and Y directly, and return D
{
	if(A%B==0)  						// B is gcd, so A*0+B*1=B
	{
		X=0;
		Y=1;
		return B;
	}
	else if(B%A==0)						// A is gcd, so A*1+B*0=A
	{
		X=1;
		Y=0;
		return A;
	}
	else if(A>B)
	{
		int x, y;
		int d=gcd(A-B*(A/B), B, x, y);
		// Ax+By = gcd(A, B) = (A-B*(A/B))x'+By' = Ax'+B(y'-(A/B)x')
		X=x;
		Y=y-(A/B)*x;
		return d;
	}
	else
	{
		int x, y;
		int d=gcd(A, B-A*(B/A), x, y);
		// Ax+By = gcd(A, B) = Ax'+(B-A*(B/A))y' = A(x'-(B/A)y')+By'
		X=x-(B/A)*y;
		Y=y;
		return d;
		
	}
}

int main(void)
{
	int A, B;
	while(cin >> A >> B)
	{
		int X, Y;
		int D=gcd(A, B, X, Y);
		
		printf("%d %d %d\n", X, Y, D);
	}
	
	return 0;
}
