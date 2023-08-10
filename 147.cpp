// UVa-147: Dollars.cpp
#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 30001

long long dp[MAX]={0};    						      // dp[n]: number of ways that n dollars can be made up
int currency[11]={5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};     // 11 types of currency

int main(void)
{
	// fill in dp
	dp[0]=1;
	for(int i=0; i<11; i++)
		for(int j=currency[i]; j<MAX; j+=5)     		      // money greater than currency[i] is affected by currency[i]
			dp[j]+=dp[j-currency[i]];

	
	int i, d; 							      // i:integer ; d: decimal
	scanf("%d.%d", &i, &d);
	while(!(i==0 && d==0))
	{
		printf("%3d.%02d%17lld\n", i, d, dp[i*100+d]);  	      // formatted output
		scanf("%d.%d", &i, &d);
	}
	
	return 0;
}
