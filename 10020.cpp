// UVa-10020: Minimal coverage.cpp
#include <iostream>
#include <cstdlib>
#include <utility>       		  // for using "pair"
#include <vector>
#include <algorithm>     		  // for using "sort()"
using namespace std;

typedef pair<int, int> line;      	  // line <start, end>

bool compare(line l1, line l2)
{
	if(l1.first < l2.first) return 1;
	else return 0;
}

int main(void)
{
	int c;                            // c test cases
	cin >> c;
	
	for(int i=0; i<c; i++)            // for each test case
	{
		int t;                    // terminal point
		cin >> t;
		
		vector<line> lines, ans;  // lines: input lines ; ans: answer lines
		
		line input;
		cin >> input.first >> input.second;
		while(input.first || input.second)            // collect input lines
		{
			lines.push_back(input);
			cin >> input.first >> input.second;
		}
		
		sort(lines.begin(), lines.end(), compare);    // sorting
		
		int left=0;                                   // search those lines starting from the left of "left"
		int right=0;                                  // right: the end of the last chosen line
		int next;                                     // next: next chosen line
		for(int j=0; j<lines.size(); j++)             // search through each line
		{
			next=-1;
			while(lines[j].first<=left && j<lines.size())
			{
				if(lines[j].second>right)
				{
					next=j;
					right=lines[j].second;
				}
				j++;
			}
			
			if(next==-1) break;                   // no larger line segment
			
			ans.push_back(lines[next]);           // add next chosen line to ans
			
			if(right>=t) break;                   // answer has found
			
			left=right;                           // answer hasn't found, continue searching
			j--;
		}
		
		if(right<t) cout << "0" << endl;
		else 
		{
			cout << ans.size() << endl;
			for(int j=0; j<ans.size(); j++) 
				cout << ans[j].first << " " << ans[j].second << endl;
		}
		
		if(i<c-1) cout << endl;	
	}
	
	return 0;
}
