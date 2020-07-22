#include <iostream>
#include <vector>

using namespace std;


int N,K,P,arr[15][50];

int beauty(int i,int Pcur)
{
	//base case when the stack of the plaes is over
	//when pcur 
	if(i>N || Pcur<1){	
	    return 0;
	} 
	//cout<<i<<endl;

	int ans=0;
	for (int j = 0; j <=K ; j++)
	{
		if(Pcur<j)
		break;
		
		ans=max(ans,arr[i][j]+beauty(i+1,Pcur-j));		
		cout<<arr[i][j]<<" "<<ans<<" "<<i<<" "<<Pcur<<" "<<j<<endl;
	}
cout<<endl;
return ans;

}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		
		vector< vector<int> > v;
		v.resize(1000);
		cin>>N>>K>>P;

		for (int i = 1; i <=N; i++)
		{
			for (int j = 1; j <=K; j++)
			{
				int x;
				cin>>x;
		//		cout<<arr[i][j-1]<<" ";
				arr[i][j]=x+arr[i][j-1];
				//cout<<arr[i][j]<<endl;
			}
		}

		cout<<beauty(1,P)<<endl;

	}
}