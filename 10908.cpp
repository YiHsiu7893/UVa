// UVa-10908: Largest Square.cpp
#include <iostream>
#include <cstdlib>
using namespace std;

int main(void)
{
	int T;
	cin >> T;
	
	int M, N, Q;
	for(int i=0; i<T; i++)   		 		 // for each case
	{
		cin >> M >> N >> Q;
		printf("%d %d %d\n", M, N, Q);
		
		// build the grid
		char grid[M][N];
		for(int j=0; j<M; j++)
			for(int k=0; k<N; k++)
				cin >> grid[j][k];
			
		int r, c;	
		for(int j=0; j<Q; j++)  	 		 // for each center
		{
			cin >> r >> c;
			int nowX=r, nowY=c;
			bool flag=1;
			
			int l;					 // l: level, with side length=2*l+1
			for(l=1; flag; l++)  
			{
				nowX=r-l; nowY=c-l;  // start from the upper left corner
				
				// check the top side 
				for(int k=0; k<2*l; k++)
				{
					if(nowX<0 || nowX>M-1 || nowY<0 || nowY>N-1 || grid[nowX][nowY]!=grid[r][c])
					{
						flag=0;
						l--;   		 // this level fails
						break;
					}
					nowY++;
				}
				
				// check the right side 
				for(int k=0; k<2*l && flag; k++)
				{
					if(nowX<0 || nowX>M-1 || nowY<0 || nowY>N-1 || grid[nowX][nowY]!=grid[r][c])
					{
						flag=0;
						l--;
						break;
					}
					nowX++;
				}
				
				// check the down side 
				for(int k=0; k<2*l && flag; k++)
				{
					if(nowX<0 || nowX>M-1 || nowY<0 || nowY>N-1 || grid[nowX][nowY]!=grid[r][c])
					{
						flag=0;
						l--;
						break;
					}
					nowY--;
				}
				
				// check the left side 
				for(int k=0; k<2*l && flag; k++)
				{
					if(nowX<0 || nowX>M-1 || nowY<0 || nowY>N-1 || grid[nowX][nowY]!=grid[r][c])
					{
						flag=0;
						l--;
						break;
					}
					nowX--;
				}
			}
			l--; 					// 減掉每層for迴圈的l++ 
			
			cout << 2*l+1 << endl;   		// the side length of l level is 2l+1		
		}
	}
	
	return 0;
}
