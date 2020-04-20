// Take input a stream of n integer elements, find the second largest element present.
// The given elements can contain duplicate elements as well. If only 0 or 1 element is given, the second largest should be INT_MIN ( - 2^31 ).

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
int n;
cin>>n;


int arr[n];
for(int i=0; i<n; i++)
cin>>arr[i];
if( n==1)
cout<< INT_MIN;
else
{
int lar= INT_MIN;
int slar= INT_MIN;
for(int i=0; i<n; i++)
{
if(arr[i]> lar)
{ 
slar=lar;
lar= arr[i];
}
else if( arr[i]<lar && arr[i]>slar)
{
slar= arr[i];
}
}
cout<< slar;
}
    
}