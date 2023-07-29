// UVa-151: Power Crisis.cpp
#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

int main(void)
{
	int N, m;
	queue<int> ans;
	
	cin >> N;         		 		 // N cities
	while(N)			   	 	 // valid case
	{
		for(m=1; m<N; m++)   			 // try unit m
		{
			int current=0;			 // start from the last step, that is, the last remaining city is numbered zero
			for(int i=1; i<N; i++)       	 // 2~N -> 1~(N-1)
				current=(current+m)%i;   // Josephus Problem Equation 
			
			if(current==13-2)            	 // the last city has to be No.13-1(translate left one place)-1(array number)
			{
				ans.push(m);
				break;
			}
		}
		
		cin >> N;           		 	 // next case
	}
	
	while(!ans.empty())
	{
		cout << ans.front() << endl;     	 // print out all the answers
		ans.pop();
	}
	
	return 0;
}
