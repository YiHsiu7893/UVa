// UVa-793: Network Connections.cpp
#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

int main(void)
{
	int d;        			 // d: the number of dataset
	cin >> d;
	
	int c;               	 // c: the number of computers
	for(int i=0; i<d; i++)   // for each dataset
	{
		cin >> c;
		getchar();			 // skip '\n'
		
		int set[c+1];                         	 // seperate computers into different sets
		for(int k=1; k<=c; k++) set[k]=k;     	 // initialize set, computer k is in set k
		
		// update the log
		char type;
		int cpI, cpJ;	
		int N1=0, N2=0;                       	 // N1: successfully answered; N2: unsuccessfully answered
		
		string input;
		getline(cin, input);
		while(input!="")                   
		{
			stringstream ss;
			ss << input;
			ss >> type >> cpI >> cpJ;
			
			if(type=='c')                     	 // type=='c'
			{
				if(set[cpI]!=set[cpJ])
				{
					// union two sets into one set
					int setI=set[cpI], setJ=set[cpJ];
					int newset=min(setI, setJ);  // choose the smaller number as the new set
					
					for(int i=1; i<=c; i++)
						if(set[i]==setI || set[i]==setJ) set[i]=newset;
				}
          	
			}
			else                             	 // type=='q'
			{
				if(set[cpI]==set[cpJ]) N1++;
				else N2++;
			}
			
			getline(cin, input);
		}
		
		cout << N1 << "," << N2 << endl;
		if(i<d-1) cout << endl;	
	}
	
	return 0;
}
