#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int wines(int x,int j,int y,int dp[][100])
{
	//base case
	if(x==j)
		return dp[x][j]=v[x]*y;
	//look up case
	if(dp[x][j]!=0)
		return dp[x][j];

	// recursive acse
		int ans1=v[x]*y + wines(x+1,j,y+1,dp);
		int ans2=v[j]*y + wines(x,j-1,y+1,dp);
		 dp[x][j]=max(ans2,ans1);
		return dp[x][j];
}

int main()
{
	int n,temp,dp[100][100]={0};
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		v.push_back(temp);
	}

	cout<<wines(0,n-1,1,dp)<<endl;
}