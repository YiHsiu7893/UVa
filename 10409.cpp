// UVa-10409: Die Game.cpp
#include <iostream>
#include <cstdlib>
using namespace std;

int face[6];         // face={up, down, north, east, south, west}

void reset(void)     // reset each face according to the specification
{
	face[0]=1;
	face[1]=6;
	face[2]=2;
	face[3]=4;
	face[4]=5;
	face[5]=3;
}

void toNorth(void)   // flip to north
{
	int tmp=face[0];
	face[0]=face[4];
	face[4]=face[1];
	face[1]=face[2];
	face[2]=tmp;
}

void toEast(void)    // flip to east
{
	int tmp=face[0];
	face[0]=face[5];
	face[5]=face[1];
	face[1]=face[3];
	face[3]=tmp;
}

void toSouth(void)   // flip to south
{
	int tmp=face[0];
	face[0]=face[2];
	face[2]=face[1];
	face[1]=face[4];
	face[4]=tmp;
}

void toWest(void)    // flip to west
{
	int tmp=face[0];
	face[0]=face[3];
	face[3]=face[1];
	face[1]=face[5];
	face[5]=tmp;
}

int main(void)
{
	int num;
	string d;
	
	cin >> num;                         // number of flips in this game
	while(num)                          // in each game
	{
		getchar();                  // skip '\n'
		
		reset();		    // reset face
		for(int i=0; i<num; i++)
		{
			getline(cin, d);    // get direction
			
			if(d=="north")      // call the corresponding function
				toNorth();
			else if(d=="east")
				toEast();
			else if(d=="south")
				toSouth();
			else
				toWest();		
		}
		cout << face[0] << endl;    // face[0] is the top face
		
		cin >> num;	            // next game
	}

	return 0;
}
