#include <iostream>

using namespace std;


int increasing(int a[], int n)
{
	int dp[100] = {0};

	for (int i = 0; i < n; ++i)
	{
		dp[i] = 1;
	}

	int best = 0;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (a[i] >= a[j]) {
				int curr = 1 + dp[j];
				dp[i] = max(curr, dp[i]);
			}
		}
		best = max(best, dp[i]);
	}
	return best;
}

int main()
{
	int n, arr[100];
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	cout << increasing(arr, n);
}