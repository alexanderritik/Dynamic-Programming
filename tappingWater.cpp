#include <iostream>
using namespace std;


void savewater(int n,int a[])
{
    int b[100000],ans=0,c[100000];
   
for(int i=0;i<n;i++){
b[i]=a[i];
c[i]=a[i];
// cout<<c[i]<<" ";
}
// cout<<endl

    for(int i=1;i<n;i++)
    {
        if(b[i-1]>b[i])
        {
            // cout<<a[i];
            b[i]=b[i-1];
        }
        else
        {
            b[i]=b[i];
        }
    }

        for(int i=n-1;i>0;i--)
    {
        // cout<<c[i]<<endl;
        if(c[i]>c[i-1])
        {
            
            c[i-1]=c[i];
        }
        else
        {
            c[i-1]=c[i-1];
        }
    }

    for(int i=1;i<n-1;i++)
    {
        int temp=min(b[i],c[i]);
       ans +=temp-a[i];
     
    }
     cout<<ans<<endl;
    
// cout<<ans;
    //  cout<<ans<<endl; 
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,a[100000];
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        
        savewater(n,a);
    }
	//code
	return 0;
}