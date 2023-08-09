// UVa-900: Brick Wall Patterns.cpp
#include <iostream>
#include <cstdlib>
using namespace std;

int main(void)
{
	int pattern[51]={0, 1, 2};
	// Fibonacci series
	// pattern[i]=(pattern[i-1]+一塊垂直) + (pattern[i-2]+兩塊平行)
	for(int i=3; i<=50; i++)
		pattern[i]=pattern[i-1]+pattern[i-2];
	
	int l;
	cin >> l;
	while(l)
	{
		cout << pattern[l] << endl;
		cin >> l;
	}
		
	return 0;
}
