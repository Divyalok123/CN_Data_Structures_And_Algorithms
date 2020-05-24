// You are given with an array of integers that contain numbers in random order. Write a program to find the longest possible sequence of consecutive numbers using the numbers from given array.
// You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
// Best solution takes O(n) time.
// If two sequences are of equal length then return the sequence starting with the number whose occurrence is earlier in the array.

#include<iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//Can be done very easily using sorting but it will be O(nlogn)
//We have a better solution using hashmaps
//O(n) solution
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    unordered_map<int, bool> mymap;
    vector<int> output;

    for (int i = 0; i < n; i++)
    {
        mymap[arr[i]] = true;
    }

    int start = arr[n - 1];
    int maxSize = 0;
    for (int k = 0; k < n; k++)
    {
        int newStart = arr[k];
        int newSize = 1;

        if (mymap[arr[k]])
        {
            int i = arr[k];
            while (mymap[++i])
            {
                newSize++;
                mymap[i] = false;
            }
            
            i = arr[k];
            while (mymap[--i])
            {
                newSize++;
                mymap[i] = false;
                newStart = i;
            }

            if (newSize > maxSize)
            {
                maxSize = newSize;
                start = newStart; 
            }
            
            if(newSize==maxSize){
                if(find(arr,arr+n,newStart)<find(arr,arr+n,start))
                    start=newStart;
            } 
        }
    }
    for (int j = 0; j < maxSize; j++)
    {
        output.push_back(start + j);
    }

    return output;
}



int main(){
  int size;
  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  vector<int> ans = longestConsecutiveIncreasingSequence(arr,size);
  
  for (auto it = ans.cbegin(); it != ans.cend(); it++) {
	cout << *it <<endl;
  }

  delete arr;
}