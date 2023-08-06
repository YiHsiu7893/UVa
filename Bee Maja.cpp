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
		for(i=0; i<l-1 && index<w; i++, index++)  // 往左下移動l-1步 
		{
			nowX--;
			nowY++;
		}
		for(i=0; i<l && index<w; i++, index++)    // 往左上移動l步 
		{
			nowX--;
		}
		for(i=0; i<l && index<w; i++, index++)    // 往上移動l步  
		{
			nowY--;
		}
		for(i=0; i<l && index<w; i++, index++)    // 往右上移動l步  
		{
			nowX++;
			nowY--;
		}
		for(i=0; i<l && index<w; i++, index++)    // 往右下移動l步  
		{
			nowX++;
		}
		for(i=0; i<l && index<w; i++, index++)    // 往下移動l步  
		{
			nowY++;
		}
		
		cout << nowX << " " << nowY << endl;
	}

	return 0;
}
