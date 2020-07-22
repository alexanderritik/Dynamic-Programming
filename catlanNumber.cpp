#include <iostream>
using namespace std;

void bst(int n)
{
int dp[1000]={0};
dp[0]=1;
dp[1]=1;

for(int l=2;l<=n;l++)
{
	for(int i=1;i<=l;i++)
	{
		cout<<dp[i-1]<<" "<<dp[l-i]<<endl;
		dp[l]+=dp[i-1]*dp[l-i];
		cout<<dp[l]<<endl;
	}
	cout<<l<<" "<<dp[l]<<endl;
	cout<<endl;

}

}




int main()
{
	int n;

	cin>>n;

	bst(n);

}