#include <iostream>
#include <vector>

using namespace std;

int N,K;
vector<int> v;
bool workout(int x)
{
	int read=0;
	for (int i = 1; i < N; i++)
	{
		int dif=v[i]-v[i-1];
		read +=(dif-1)/x;
		if(read > K)
			return 0;
	}
	return 1;
}



int binarysearch(int low,int high)
{
	while(low<high)
	{
		int mid=(low+high)/2;
		if(workout(mid))
		{
			high=mid;
		}

		else
		{
			low=mid+1;
		}
	}
	return low;
}




int main()
{
	int t;
	cin>>t;
int q=1;
	while(t--)
	{
		cin>>N>>K;
		for (int i = 0; i < N; ++i)
		{
			int temp;
			cin>>temp;
			v.push_back(temp);
		}

		// binary seacrh ka function
		cout<<"Case #"<<q<<": "<<binarysearch(1,1000000000)<<endl;
		q++;
		
		v.clear();
	}
}