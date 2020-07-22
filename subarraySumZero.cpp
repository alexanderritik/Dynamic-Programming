#include <iostream>
#include<set>
using namespace std;

int main()
{
	int n,a[1000];
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	int pref=0;
	set<int>s;
	for (int i = 0; i < n; ++i)
	{
		pref+=a[i];
		// cout<<"pref"<<pref<<endl;
		if(pref==0 || s.find(pref)!=s.end())
		{
			set<int>::iterator it;
			it=s.find(pref);
			cout<<"find "<<*it<<" "<<pref<<" "<<i<<endl;
		}
		s.insert(pref);

	}
}