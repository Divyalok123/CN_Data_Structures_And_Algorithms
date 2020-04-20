// Given an array of length N, swap every pair of alternate elements in the array.
// You don't need to print or return anything, just change in the input array itself.

#include<iostream>
using namespace std;

void swap(int*a, int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    
}

void swapAlternate(int arr[],int size){
    int i = 0;
    while(i+1 < size)
    {
        swap(&arr[i], &arr[i+1]);
        i+=2;
    }
}


int main(){
  int size;  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  } 
  swapAlternate(arr, size);
 for(int i = 0; i < size; i++){
    cout << arr[i] << " ";
  }
  delete arr;
}


