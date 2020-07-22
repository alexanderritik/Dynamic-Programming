#include <iostream>
using namespace std;
int n1=0;
int tiling(int n)
{
	if(n==1 || n==0 || n==2 || n==3)
		return n;
 if(n<0)
 	return n1=0;

   return tiling(n-1)+tiling(n-4);
//    return n1;

}

int main()
{
	cout<<tiling(9);
//cout<<<<" "<<n1;

//	cout<<"value "<<;
    
}