#include <iostream>
#include<vector>
using namespace std;

int n;
vector<int> v;
// int coinway(int coin,int dp[])
// {
// 	//base case
// 	if(coin==0)
// 	{
// 		return 0;
// 	}

// 	//look up case
// 	if(dp[coin]!=0)
// 		return dp[coin];

// 	//recusive case
// 	int ans=INT_MAX;
// 	for (int i = 0; i < n; ++i)
// 	{
// 		if(coin>=v[i])
// 		{
			
// 			int subans=coinway(coin-v[i],dp);
// 			ans=min(ans,subans+1);
			
// 		}
// 	}
// dp[coin]=ans;
// 	return dp[coin];
// }


int bottomup(int coin,int dp[])
{
dp[0]=0;
	for (int j = 1; j <=coin; ++j)
	{
		dp[j]=INT_MAX;
		cout<<j<<" = ";
		for (int i = 0; i < n; ++i)
		{

			if(j>=v[i])
			{
				int subans1=dp[j-v[i] ];
				dp[j]=min(dp[j],subans1+1);
				cout<<dp[j]<<" ";
			}
			
		}		
cout<<dp[j]<<endl;
	}
return dp[coin];
}



int main()
{
	int coin,dp[10000]={0};
	cin>>n>>coin;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin>>temp;
		v.push_back(temp);
	}

	// cout<<coinway(coin,dp);
	cout<<bottomup(coin,dp);

}