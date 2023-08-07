// UVa-1210: Sum of Consecutive Prime Numbers.cpp
#include <iostream>
#include <cstdlib>
#include <queue>
#include <cmath>    			  	  // sqrt()
#include <cstring>  			  	  // memset()
using namespace std;

int main(void)
{
	int i, j;
	
	// select primes
	bool is_prime[10001];
	memset(is_prime, 1, sizeof(is_prime));
	
	for(i=2; i<=sqrt(10000); i++)
		for(j=2; i*j<=10000; j++) is_prime[i*j]=0;
	
	// calculate presentations
	int count[10001];    		  	  // number of presentations
	memset(count, 0, sizeof(count));
	
	queue<int> pre;   			  // numbers that are made up of the previous consecutive prime
	for(i=2; i<=10000; i++)
	{
		if(is_prime[i])
		{
			int size=pre.size();  	  // there are "size" numbers made up of the previous consecutive prime
			
			count[i]++;  		  // prime itself contributes to one presentation
			pre.push(i);
		
			int num, newnum;
			for(j=0; j<size; j++)
			{
				num=pre.front();
				pre.pop();
				
				newnum=num+i;  	  // previous consecutive sequence + current number
				if(newnum>10000) continue;
				count[newnum]++;
				pre.push(newnum);
			}
		}
	}
	
	// for each case
	int input;
	cin >> input;
	while(input)
	{
		cout << count[input] << endl;
		cin >> input;
	}
		
  return 0;
}
