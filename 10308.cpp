// UVa-10308: Roads in the North.cpp
#include <iostream>
#include <cstdlib>
#include <utility>                      // for using "pair"
#include <vector>                       // for using "vector"
#include <cstring>                      // for using "memset"
#include <sstream>                      // for using "stringstream"
using namespace std;
#define N 10001

// make sure to initialize these values each iteration
typedef pair<int, int> adj;             // adj(connected village, distance)
vector<adj> data[N];                    // data[N]: data of connected villages of N
bool visited[N];                        // whether the village N has been visited
int dp[N][2];                           // dp[N][0]: second deepest distance; dp[N][1]: deepest distance
int ans=0;                              // ans: answer (the longest road)

void collect(int v1, int v2, int d)     // collecting data
{
	adj tmp;
	
	tmp.first=v2;                   // collect (v2, d) to v1
	tmp.second=d;
	data[v1].push_back(tmp);
	
	tmp.first=v1;                   // collect (v1, d) to v2
	tmp.second=d;
	data[v2].push_back(tmp);
}

void dfs(int r)                         	    // depth-first search
{
	visited[r]=1;
	int size=data[r].size();            
	int v, d;
	
	dp[r][0]=dp[r][1]=0;                	    // initialize dp
	for(int i=0; i<size; i++)              	    // search through each connected villages
	{
		adj tmp=data[r][i];
		v=tmp.first;
		d=tmp.second;
		
		if(!visited[v])                     // only when the village hasn't been visited that the data need to be update
		{
			dfs(v);
			if(dp[v][1]+d > dp[r][1])   // update the deepest distance
			{
				dp[r][0]=dp[r][1];
				dp[r][1]=dp[v][1]+d;
			}
			else if(dp[v][1]+d > dp[r][0])
				dp[r][0]=dp[v][1]+d;
		}
	}
	
	if(dp[r][0]+dp[r][1] > ans) ans=dp[r][0]+dp[r][1];    // update the answer
}

int main(void)
{
	string input;
	int v1, v2, d;
	memset(visited, 0, sizeof(visited));                  // initialize
	
	getline(cin, input);
	while(!input.empty())                                 // second time of a blanck line -> eof
	{
		while(!input.empty())                         // first time of a blanck line -> end of a case
		{
			stringstream ss;
			ss << input;
			ss >> v1 >> v2 >> d;
			collect(v1, v2, d);                   // a piece of data
			getline(cin, input);
		}
		dfs(1);
		cout << ans << endl;
		
		// finish this case, initialize these values for next case
		for(int i=1; i<N; i++) data[i].clear();
		memset(visited, 0, sizeof(visited));
		ans=0;
		
		// next case
		getline(cin, input);
	}
	
	return 0;
}
