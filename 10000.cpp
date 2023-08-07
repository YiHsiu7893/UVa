// UVa-10000: Longest Paths.cpp
#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

int main(void)
{
	int count=0;       		      // count: the number of test case
	
	int n;             		      // n: the number of nodes
	cin >> n;
	while(n!=0)        		      // for each case
	{
		count++;
		
		int s;         		      // s: starting point
		cin >> s;     
		
		bool line[n+1][n+1]={0};      // collect lines
		int p, q;                     // line (p, q)
		cin >> p >> q;
		while(p || q)
		{
			line[p][q]=1;
			cin >> p >> q;
		}
		
		queue<int> update;            // store nodes that have been updated
		bool inQueue[n+1]={0};        // whether the node is in update queue
		int length[n+1]={0};          // the longest length to that node
		
		// start from s
		update.push(s);               
		inQueue[s]=1;
		
		int current;
		while(!update.empty())
		{
			current=update.front();
			update.pop();
			inQueue[current]=0;
			
			for(int i=1; i<=n; i++)   	 // update nodes that are connected to the current one
			{
				if(line[current][i] && length[current]+1>length[i])  
				{
					length[i]=length[current]+1;
					
					if(!inQueue[i])  // the node is updated, so it must be push into the update queue
					{
						update.push(i);
						inQueue[i]=1;
					}
				}
			}
		}
		
		int ans=1;                   		 // find the destination (node with the longest length)
		for(int i=2; i<=n; i++)
			if(length[i] > length[ans]) ans=i;
		
		cout << "Case " << count << ": The longest path from " << s << " has length " << length[ans] << ", finishing at " << ans << ".\n\n";
		
		cin >> n;                    		 // next test case
	}
	
	return 0;
}
