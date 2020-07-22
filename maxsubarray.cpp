#include <iostream>
using namespace std;


int findmaxarray(int a[],int n)
{
	int dp[100]={0};
	dp[0]=a[0]>0 ? a[0]:0;
	int max_so_far=dp[0];
	for (int i = 1; i < n; ++i)
	{
		dp[i]=dp[i-1]+a[i];
		if(dp[i]<0)
		{
			dp[i]=0;
		}
		max_so_far=max(dp[i],max_so_far);
	}
	return max_so_far;
}

int main()
{
	int n,a[100];
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<findmaxarray(a,n);
}