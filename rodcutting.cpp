#include <iostream>
using namespace std;


int maxprofit(int profitoflenght[],int length,int rodlength,int dp[])
{
	if(rodlength==0)
		return 0;

	//look u case
	if(dp[rodlength]!=-1)
		return dp[rodlength];

	int ans=0,profit=0;

	for (int i = 1; i <=length; ++i)
	{
		if(rodlength -i>=0){
			
			 profit =profitoflenght[i]+maxprofit(profitoflenght,length,rodlength-i,dp);
			
			ans=max(profit,ans);

		}
		
	}
// cout<<rodlength<<" "<<ans<<endl;
	return dp[rodlength]=ans;
}


int bottomup(int profitoflenght[],int length,int rodlength)
{
	int dp[100],ans;
	dp[0]=0;
	for (int i = 1; i <=rodlength; ++i)
	{
		dp[i]=0;
		for (int j = 1; j <=length; ++j)
		{
			if(i-j>=0){
				ans=profitoflenght[j]+dp[i-j];
				dp[i]=max(ans,dp[i]);
				// cout<<i<<" "<<dp[i]<<" -> ";
				
			}
		}
		// cout<<endl;
	}
	return dp[rodlength];
}


int main()
{
	int rodlength,length,profitoflenght[100],dp[100];
	memset(dp,-1,sizeof(dp));
	cin>>rodlength;
	cin>>length;

	for (int i = 1; i <=length; ++i)
	{
		cin>>profitoflenght[i];
	}

// cout<<maxprofit(profitoflenght,length,rodlength,dp);
cout<<bottomup(profitoflenght,length,rodlength);
}