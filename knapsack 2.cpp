/*
    Author  : <<grenade24>>
    Email   : << rakeshkusrivastav@gmail.com >>
    Date    : 2020-06-07 01:48:11
*/

//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <string>
#include <utility>
#include <iterator>
#include <fstream>
#include <sstream>
#include <numeric>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <ctime>
#include <cassert>


using namespace std;


/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef long long      ll;
typedef pair<int, int> ii;
typedef pair<ii, int>  iii;
typedef vector<int>    vi;
typedef vector<ii>     vii;
typedef vector<iii>    viii;
/* typedef ends */

/* macro starts */


#define mp             make_pair
#define pb             push_back
#define eb             emplace_back
#define fi             first
#define se             second
#define sz(x)          (int)((x).size())
#define fill(x, y)     memset(x, y, sizeof(x))
#define all(x)         (x).begin(), (x).end()
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define rep(i, x, y)   for (int i = x; i <= y; i ++)
#define repi(i, x, y)  for (int i = x; i >= y; i --)
#define fore(itr, x)   for (auto itr:x)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)

#define PI acos(-1.0)
#define EPS 1e-9
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sinD(degree) sin((degree * PI) / 180.0)
#define cosD(degree) cos((degree * PI) / 180.0)
#define tanD(degree) tan((degree * PI) / 180.0)
#define cotD(degree) (1.0 / tanD(degree))
#define secD(degree) (1.0 / cosD(degree))
#define cosecD(degree) (1.0 / sinD(degree))
#define asinD(value) (asin(value) * 180.0) / PI
#define acosD(value) (acos(value) * 180.0) / PI
#define atanD(value) (atan(value) * 180.0) / PI
#define value_at_index(x) find_by_order(x)
#define index_of(x) order_of_key(x)

/* macro ends */

/* function starts */

/// calculates n-th (0-based) Gray Code
template<typename dataType>
dataType nthGrayCode(dataType n)
{
	return (n ^ (n >> 1));
}

/// generates all possible subsets for the given set
template<typename dataType>
void generateAllSubset(vector<dataType> &data)
{
	int i, j, n;
	n = data.size();

	for (i = 0; i < (1 << n); i++) {
		for (j = 0; j < n; j++) {
			if (i & (1 << j)) {
				cout << data[j] << " ";
			}
		}
		cout << "\n";
	}
}

/* function ends */

vi v(100), w(100);
int S, n;
int memo[100][100];
int topdown(int rem, int i)
{
	// cout << rem << " " << n << endl;
	if (rem == 0 || i >= n)
		return 0;

	if (memo[i][rem] != -1) {
		return memo[i][rem];
	}
	// cout << rem << " " << v[i] << endl;
	if (v[i] > rem) return memo[i][rem] = topdown(rem, i + 1);
	return memo[i][rem]  = max(topdown(rem, i + 1), w[i] + topdown(rem - v[i], i + 1));
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif



	cin >> n >> S;
	// cout << n << endl;
	v.resize(n);
	w.resize(n);
	fill(memo, -1);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> w[i];
	}
	// cout << n << " " << S << endl;
	cout << topdown(S, 0) << endl;

	int C[100][100];

	for (int i = 0; i <= n;  i++) C[i][0] = 0;
	for (int w = 0; w <= S; w++) C[0][w] = 0;

	for (int i = 1; i <= n; i++)
		for (int wi = 1; wi <= S ; wi++) {
			if (v[i - 1] > wi) C[i][wi] = C[i - 1][wi];
			else          C[i][wi] = max(C[i - 1][wi], w[i - 1] + C[i - 1][wi - v[i - 1]]);
		}


	for (int i = 0; i <= n; ++i)
	{
		for (int wi = 0; wi <= S; wi++) {
			cout << C[i][wi] << " ";
		}
		cout << endl;
	}



	return 0;
}