#include <iostream>
#include<vector>
using namespace std;

vector<int> v;
int dp[1000][1000];



int sum(int i,int j)
{
	int ans=0;
	for(int k=i;k<=j;k++)
	{
		ans+=v[k];
		ans%=100;
	}
	return ans;
}


int mixture(int i,int j)
{
	// this is like top down dp

	//base acse
	if(i>=j)
	{
		return 0;
	}

	// look up case
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}

	dp[i][j]=INT_MAX;
	for(int k=i;k<=j;k++)
	{
		dp[i][j]=min(dp[i][j],mixture(i,k)+mixture(k+1,j)+sum(i,k)*sum(k+1,j));
	}
	return dp[i][j];
}




int main()
{
	int n,temp;
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		v.push_back(temp);
	}

	cout<<mixture(0,n-1);
}