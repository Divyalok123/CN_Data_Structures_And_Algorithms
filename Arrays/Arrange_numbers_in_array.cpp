// Given a number n, put all elements from 1 to n in an array in order - 1,3,.......4,2.

#include<iostream>
using namespace std;

void arrange(int arr[],int n){
    int i = 1;
    int j = 0;
    while(i <= n)
    {
        if(i%2 == 1)
        {
            arr[j] = i;
            j++;
        }
        i++;
        
    }
    i--;
    while(i > 1)
    {
        if(i%2 == 0)
        {
            arr[j] = i;
            j++;
        }
        i--;
        
    }
    
}

int main(){
  int n;  
  cin >> n;
  
  int* arr = new int[n];
  arrange(arr,n);
  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
  delete arr;
}


