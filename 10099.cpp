// UVa-10099: The Tourist Guide.cpp
#include <iostream>
#include <cstdlib>
#include <cstring>  				// memset()
using namespace std;

int main(void)
{
	int scenario=0;
	
	int N, R;
	cin >> N >> R;
	while(N || R)  				// for each case
	{
		scenario++;
		
		int capacity[N+1][N+1];  	// the maximal capacity between two cities
		memset(capacity, 0, sizeof(capacity));
		
		int C1, C2, P;
		for(int i=0; i<R; i++)
		{
			cin >> C1 >> C2 >> P;
			capacity[C1][C2]=capacity[C2][C1]=P;
			
		}
		
		// apply Floyd-Warshall algorithm to find the maximal capacity between two cities
		for(int k=1; k<=N; k++)
			for(int i=1; i<=N; i++)
				for(int j=1; j<=N; j++)
					capacity[i][j]=max(capacity[i][j], min(capacity[i][k], capacity[k][j]));
				
		int S, D, T;	
		cin >> S >> D >> T;
		cout << "Scenario #" << scenario << endl; 
		// compute the number of trips, "-1" takes the tourist guide into account
		cout << "Minimum Number of Trips = " << T/(capacity[S][D]-1)+((T%(capacity[S][D]-1)>0)?1:0) << endl << endl;
		
		cin >> N >> R;
	}
	
	return 0;
}
