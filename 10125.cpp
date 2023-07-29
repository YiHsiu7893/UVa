// UVa-10125: Sumsets.cpp
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;        // n elements
	
	cin >> n;
	while(n)
	{
		// collecting elements
		int element[n];
		for(int i=0; i<n; i++)
			cin >> element[i];
		
		// sort the elements
		std::sort(element, element+n);
		
		// brutal force
		int a, b, c, d;
		bool found=0;
		for(int i=n-1; i>=0 && !found; i--)                // determine d
		{
			d=element[i];                 
			
			for(int j=0; j<n && !found; j++)        	   // determine a
			{
				a=element[j];             
				if(a==d) continue;
				
				for(int k=j+1; k<n && !found; k++)  	   // determine b
				{
					b=element[k];         
					if(b==d) continue;
					
					for(int l=k+1; l<n && !found; l++)     // determine c
					{
						c=element[l];
						if(c==d) continue;
						
						if(a+b+c==d) found=1;
					}	
				}
			}	
		}	
		
		if(found) cout << d << endl;
		else cout << "no solution" << endl;
		
		cin >> n;
	}

    return 0;
}
