#include <iostream>
using namespace std;



int minimumTop(int n,int dp[])
{
	int n1=INT_MAX,n2=INT_MAX,n3=0;	
	if(n==1)
		return 0;

	if(dp[n]!=0)
		return dp[n];

	if(n%3==0){
	
		n1 =minimumTop(n/3,dp)+1;
		// dp[n]=n1;
	}
	if(n%2==0){

		n2 =minimumTop(n/2,dp)+1;
		// dp[n]=n2;
		//cout<<n2<<endl;
	}
	
	n3 =minimumTop(n-1,dp)+1;
	// dp[n]=n3;
	//cout<<n3<<endl;
	
	
	int ans =min(min(n1,n2),n3);
	//cout<<n<<" "<<ans<<endl;
	return dp[n]=ans;

}


int minimumBot(int n,int dp[])
{
	
	
	dp[1]=0;

	for (int i = 2; i <=n; ++i)
	{
		int opt1,opt2,opt3;
		opt3=opt2=opt1=INT_MAX;
		if(i%3==0)
			opt1=dp[i/3];
		
		if(i%2==0){
			int l=n%2;
			// cout<<l<<endl;
			opt2=dp[i/2];
		}

		opt3=dp[i-1]; 
		// cout<<i<<" "<<opt1<<" "<<opt2<<" "<<opt3<<endl;
	    dp[i]=min(min(opt1,opt2),opt3)+1;
	    
	}

	// for (int i = 1; i <=n; ++i)
	// {
	// 	cout<<dp[i]<<" ";
	// }
	// cout<<endl;
	return dp[n];

}

int main()
{
	int n,dp[100]={0};
	cin>>n;
	// cout<<minimumTop(n,dp)<<" "<<dp[n];
	cout<<minimumBot(n,dp)<<endl;


}