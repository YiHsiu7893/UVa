// UVa-532: Dungeon Master.cpp
#include <iostream>
#include <cstdlib>
#include <queue> 
using namespace std;

class cube
{
  public:
  	int x, y, z;          			   // coordinate
  	int t;                			   // time
  	
  	void set(int a, int b, int c, int d)       // set coordinate and time
  	{
  		x=a;
  		y=b;
  		z=c;
  		t=d;
	}
};

char dungeon[31][31][31];                          // dungeon: store the symbols
// 6 valid movement direction
int dx[6]={1, -1, 0, 0, 0, 0};
int dy[6]={0, 0, 1, -1, 0, 0};
int dz[6]={0, 0, 0, 0, 1, -1};

int BFS(int l, int r, int c, cube s)           	   // BFS search
{
	bool visited[31][31][31]={0};              // whether the cube has visited
	visited[s.x][s.y][s.z]=1;
	
	queue<cube> q;                             // use queue to implement BFS serach
	q.push(s);
	
	cube current;
	int nextX, nextY, nextZ;
	while(!q.empty())
	{
		current=q.front();
		q.pop();
		if(dungeon[current.x][current.y][current.z]=='E') return current.t;
		
		for(int i=0; i<6; i++)             // search through each direction
		{
			nextX=current.x+dx[i];
			nextY=current.y+dy[i];
			nextZ=current.z+dz[i];
			
			// if that coordinate is valid and hasn't visited, visit it (push into the queue)
			if( nextX>0 && nextX<=c && nextY>0 && nextY<=r && nextZ>0 && nextZ<=l &&
				dungeon[nextX][nextY][nextZ]!='#' && !visited[nextX][nextY][nextZ] )
			{
				cube next;
				next.set(nextX, nextY, nextZ, current.t+1);
				q.push(next);
				visited[nextX][nextY][nextZ]=1;
			}
		}
	}
	return -1;                                 // cannot reach E
}

int main(void)
{
	int L, R, C;
	cube S;
	
	cin >> L >> R >> C;
	while(L || R || C)                   	   // (L, R, C) != (0, 0, 0)
	{
		// build the dungeon
		for(int i=1; i<=L; i++)           		
		{
			for(int j=1; j<=R; j++)
				for(int k=1; k<=C; k++)
				{
					cin >> dungeon[k][j][i];
					if(dungeon[k][j][i]=='S') S.set(k, j, i, 0);    // S: starting position
				}
		}
		
		int x=BFS(L, R, C, S);             // do BFS search
		if(x==-1) cout << "Trapped!" << endl;
		else cout << "Escaped in " << x << " minute(s)." << endl;
		
		cin >> L >> R >> C;                // next dungeon
	}

	return 0;
}
