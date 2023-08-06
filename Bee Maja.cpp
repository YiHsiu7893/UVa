// Bee Maja.cpp
#include <iostream>
#include <cstdlib>
using namespace std;

int main(void)
{
	int w;           	   		// w: Willi's honey comb number
  	while(cin>>w)
  	{
  		if(w==1)     	   		// w=1, center(0,0)
  		{
  			cout << "0 0" << endl;
  			continue;
		}
		
  		int l=0, last=1;   		// l: level, moving l steps on livel l
  		while(last<w)      		// last: the last number on this level
  		{
  			l++;
  			last+=6*l;
		}
		
		int s=(last-6*l)+1;  	// s: start point of this level
		int nowX=l-1, nowY=1;	// x and y of current point (start point here)
		int index=s;			// search this level starting from the start point
		
		// simulate on level l
		int i;
		for(i=0; i<l-1 && index<w; i++, index++)  // �����U����l-1�B 
		{
			nowX--;
			nowY++;
		}
		for(i=0; i<l && index<w; i++, index++)    // �����W����l�B 
		{
			nowX--;
		}
		for(i=0; i<l && index<w; i++, index++)    // ���W����l�B  
		{
			nowY--;
		}
		for(i=0; i<l && index<w; i++, index++)    // ���k�W����l�B  
		{
			nowX++;
			nowY--;
		}
		for(i=0; i<l && index<w; i++, index++)    // ���k�U����l�B  
		{
			nowX++;
		}
		for(i=0; i<l && index<w; i++, index++)    // ���U����l�B  
		{
			nowY++;
		}
		
		cout << nowX << " " << nowY << endl;
	}

	return 0;
}
