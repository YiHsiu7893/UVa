// UVa-10664: Luggage.cpp
#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>        // stringstream
#include <cstring>        // memset()
using namespace std;

bool boot[201];              // whether boot[i] is a possible load weight for one boot

int main(void)
{
	int m;
	cin >> m;             // m test cases
	getchar();            // skip '\n'
	
	for(int i=0; i<m; i++)        // for each test case
	{
		int w, sum=0;
		vector<int> weights;      // store weights
		
		string input;
		stringstream ss;
		getline(cin, input);
		ss << input;
		
		while(ss >> w)            // collect weights and compute sum
		{
			weights.push_back(w);
			sum+=w;	
		}
		
		if(sum%2)                 // if sum is odd
		{
			cout << "NO\n";
			continue;
		}
		
		memset(boot, 0, sizeof(boot));  // initialize boot
		boot[0]=1;
		
		for(int j=0; j<weights.size(); j++)    // dp fill in boot
			for(int k=sum; k>=weights[j]; k--)
				if(boot[k-weights[j]]) boot[k]=1;
				
		if(boot[sum/2]) cout << "YES\n";
		else cout << "NO\n";			
	}

	return 0;
}
