#include <iostream>

using namespace std;

int solver(int N,int x,int y,int z)
{
	int dp[100000];
	dp[0]=0;
	dp[1]=0;

	for (int i = 2; i <=N; ++i)
	{

		//odd case
		if(i&1)
		{
			dp[i]=min(dp[i-1]+x,dp[(i+1)/2]+x+z);
		}
		// even case
		else
		{
			dp[i]=min(dp[i-1]+x,dp[(i/2)]+y);
		}

	}

	return dp[N];
}

int main()
{
	int N,x,y,z;

	cin>>N;
	cin>>x>>y>>z;

	cout<<solver(N,x,y,z);

	return 0;
}