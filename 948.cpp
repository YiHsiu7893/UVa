// UVa-948: Fibonaccimal Base.cpp
#include <iostream>
#include <cstdlib>
using namespace std;

int main(void)
{
	int Fibonacci[40]={0, 1};   			// at most 40 digits is enough for numbers<=100,000,000
	for(int i=2; i<40; i++)				// fill in Fibonacci series
		Fibonacci[i]=Fibonacci[i-1]+Fibonacci[i-2];
		
	int N;
	cin >> N;
	for(int i=0; i<N; i++)				// for each case
	{
		bool flag=0;				// flag stands for the start of printing
		
		int input;
		cin >> input;
		cout << input << " = ";
		
		for(int j=39; j>=2; j--)		// from the largest Fibonacci number
		{
			if(input>=Fibonacci[j])
			{
				flag=1;			// start printing
				cout << "1";
				input-=Fibonacci[j];
			}
			else if(flag) cout << "0";
		}
		
		cout << " (fib)\n";
	}
		
	return 0;
}
