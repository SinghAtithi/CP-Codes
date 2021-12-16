#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>
#include <set>
#define ll long long int
using namespace std;
bool recursion (vector<vector<char> > &matrix, vector<vector<bool> > &checker, int n, int m, int row, int leftCol, int rightCol, int l)
{
	if (row>=n || leftCol<0 || rightCol>=m)
	{
		return false;
	}
	if (leftCol==rightCol && matrix[row][leftCol]=='*')
	{
		checker[row][leftCol] = true;
		return true;
	}
	if (matrix[row][leftCol]=='*' && matrix[row][rightCol]=='*')
	{
		bool flag = false;
		flag = recursion(matrix, checker, n, m, row+1, leftCol+1, rightCol-1, l-1);
		if (flag==true)
		{
			checker[row][leftCol] = true;
			checker[row][rightCol] = true;
			return true;
		}
		return false;
	}
	return false;
}
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		int n, m, l;
		cin>>n>>m>>l;
		vector<vector<char> > matrix(n, vector<char> (m));
		vector<vector<bool> > checker(n, vector<bool> (m));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin>>matrix[i][j];
				if (matrix[i][j]=='.')
				{
					checker[i][j] = true;
				}
				else
				{
					checker[i][j] = false;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (matrix[i][j]=='*')
				{
					for (int k = j + 2*l; k < m; k+=2)
					{
						if (matrix[i][k]=='*')
						{
							bool flag = false;
							flag = recursion(matrix, checker, n, m, i+1, j+1, k-1, l-1);
							if (flag==true)
							{
								checker[i][j] = true;
								checker[i][k] = true;
							}
						}
						
					}
					
				}
				
			}
			
		}
		bool res = true;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (checker[i][j]==false)
				{
					res = false;
					break;
				}
				
			}
			cout<<endl;
		}
		if (res==true)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
		
	}
	return 0;
}