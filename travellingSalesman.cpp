#include <iostream>
#include <math.h>

using namespace std;

int n=4;
int dist[10][10]={
	{0,20,42,25},
	{20,0,30,34},
	{42,30,0,10},
	{25,34,10,0}
};

//we use dp to optimize by memeory memonzi

int dp[16][4]={0};

int visited_all=pow(2,n)-1;


int salesman(int mask,int pos)
{

	
	//base case 
	if(mask==visited_all){
		return dist[pos][0];
	}

	//look up acse means in dp we earlier we calucated is value or not
	if(dp[mask][pos]!=-1)
	{
		return dp[mask][pos];
	}



	int ans=INT_MAX;
	for (int city = 0; city < n; ++city)
	{
		if((mask&(1<<city))==0)
		{
			//means you want to go city 1 to 2
			//suppose mask of first city is 0001
			// suppose going to next city is 1<<city means 0100 
			// and or of this give 0101 
			int newans=dist[pos][city]+salesman(mask|(1<<city),city);
			ans=min(ans,newans);
		}	
	}


	return dp[mask][pos]=ans;
}





int main()
{
	cout<<"the sales man solution is"<<endl;
	for (int i = 0; i < (1<<n); ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			dp[i][j]=-1;
		}
	}
	cout<<salesman(1,0)<<endl;
}