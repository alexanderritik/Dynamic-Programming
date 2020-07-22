#include <iostream>
using namespace std;


int sequence(string str1, string str2)
{

	int dp[100][100] = {0};

	for (int i = 1; i <= str1.length(); ++i)
	{
		for (int j = 1; j <= str2.length(); ++j)
		{
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}


	for (int i = 0; i < str1.length(); ++i)
	{
		for (int j = 0; j < str2.length(); ++j)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	return dp[str1.length() - 1][str2.length() - 1];
}



int main()
{
	string str1, str2;
	cin >> str1;
	cin >> str2;
	cout << sequence(str1, str2);
}