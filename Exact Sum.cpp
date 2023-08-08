// UVa-11057: Exact Sum.cpp
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;
	while(cin >> N)   		 // for each case
	{
		int cost[N];  		 // cost: store the cost of each book
		for(int i=0; i<N; i++)
			cin >> cost[i];	
		sort(cost, cost+N);  // reorder the books by their costs
		
		int M;
		cin >> M;
		
		int i, j;
		int p=0, q=N-1;		// p: search from the cheapest ; q: search from the most expensive
		for(; p<q; p++)		// when p and q meet, the search is finished
		{
			// for each p, try to find whether M-cost[p] exists
			while(cost[q] > M-cost[p]) q--;
			
			// M-cost[p] exists
			if(cost[q]==M-cost[p])
			{
				i=cost[p];
				j=cost[q];
				q--;
			}
		}
		
		// the last (i, j) pair is the one with the most minimum difference
		cout << "Peter should buy books whose prices are " << i << " and " << j << ".\n\n";
	}
	return 0;
}
