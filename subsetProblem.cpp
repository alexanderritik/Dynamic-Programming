/*
    Author  : <<grenade24>>
    Email   : << rakeshkusrivastav@gmail.com >>
    Date    : 2020-06-07 01:48:11
*/

#include <bits/stdc++.h>
using namespace std;
int n, sum;
bool dp[1000][1000];
vector<int > a;

bool issolver(int i, int total, map<int, bool>visited)
{

	if (total == 0)
	{
		cout << "answer" << endl;
		for (auto k : visited)
		{
			if (k.second == true ) {
				cout << k.first << " ";
			}
		}
		cout << endl;
		return true;
	}

	if (i <= 0)
		return false;


	if (dp[a[i]][total]) {
		cout << total << " ";
		for (int j = 0; j < n; ++j)
		{
			if (!visited[a[j]]) {
				visited[a[j]] = true;
				if (issolver(i - 1, total - a[j], visited))return false;
				visited[a[j]] = false;
			}
		}
	}
	return false;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	cin >> n >> sum;
	a.resize(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	memset(dp, false, sizeof(dp));


	for (int i = 0; i < n; ++i)
	{
		dp[a[i]][0] = true;
	}
	// cout << "num  ";
	// for (int i = 0; i <= sum; ++i)
	// {
	// 	cout << i << " ";
	// }
	// cout << endl;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j <= sum; ++j)
		{
			if (j == a[i])
				dp[a[i]][j] = true;
			else if (i > 0) {
				if (a[i] > j)
				{
					dp[a[i]][j] = dp[a[i - 1]][j];
				}
				else if (a[i] < j)
				{
					dp[a[i]][j] = max(dp[a[i - 1]][j - a[i]], dp[a[i - 1]][j]);
				}
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " -> ";
		for (int j = 0; j <= sum; ++j)
		{
			cout << dp[a[i]][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << "new" << " -> ";
		map<int, bool> v;
		issolver(i, sum, v);
		cout << endl;
	}







}