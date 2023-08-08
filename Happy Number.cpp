// UVa-10591: Happy Number.cpp
#include <iostream>
#include <cstdlib>
#include <set>
using namespace std;

// calculate the square sum
int squareSum(int n)
{
	int tmp, sum=0;
	while(n)
	{
		tmp=n%10;
		sum+=tmp*tmp;
		n/=10;
	}
	return sum;
}

int main(void)
{
	int c;
	cin >> c;
	
	for(int p=1; p<=c; p++)  // for each case
	{
		int num;
		bool isHappy;
		set<int> exist;
		
		cin >> num;
		exist.insert(num);
		cout << "Case #" << p << ": " << num;
		
		while(1)
		{
			num=squareSum(num);
			
			if(num==1)  // a happy number
			{
				isHappy=true;
				break;
			}
		
			if(exist.count(num))  // an unhappy number
			{
				isHappy=false;
				break;
			}
			else exist.insert(num);
		}
		
		if(isHappy) cout << " is a Happy number.\n";
		else cout << " is an Unhappy number.\n";
	}

	return 0;
}
