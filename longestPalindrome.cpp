#include <iostream>
using namespace std;
int dp[100][100];

int lps(int i,int j,string s)
{
	// cout<<i<<" "<<j<<endl;
	//base acse
	if(i>j)
		return 0;


	if(dp[i][j]!=0)
	{
		return dp[i][j];
	}

// when character matches eg- B AGFHGHJ B. since last anf first match then legth from 
	// both side
	if(s[i]==s[j])
	{
		cout<<s[i]<<" "<<s[j]<<" "<<i<<" "<<j<<endl;
		dp[i][j]=lps(i+1,j-1,s);
		if(i==j)
		{
			dp[i][j]+=1;
		}
		else
		{
			dp[i][j]+=2;
		}

		
	}
	else
	 dp[i][j]=max(lps(i+1,j,s),lps(i,j-1,s));

	return dp[i][j];
}



int main()
{
	string str;
	cin>>str;
// largest palindrome string 
	// cout<<str.length()-1;
	memset(dp,0,sizeof(dp));
	cout<<lps(0,str.length()-1,str)<<endl;
	for (int i = 0; i < str.length(); ++i)
	{
		for (int j = 0; j < str.length(); ++j)
		{
			cout<<dp[i][j]<<"  ";
		}
		cout<<endl;
	}
// for (int i = 0; i <dp[str.length()-1][str.length()-1]; ++i)
// {
// 	cout<<str[i];
// }

}