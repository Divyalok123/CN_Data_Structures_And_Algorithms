// Two random integer arrays are given A1 and A2, in which numbers from 0 to 9 are present at every index (i.e. single digit integer is present at every index of both given arrays).
// You need to find sum of both the input arrays (like we add two integers) and put the result in another array i.e. output array (output arrays should also contain only single digits at every index).
// The size A1 & A2 can be different.
// Note : Output array size should be 1 more than the size of bigger array and place 0 at the 0th index if there is no carry. No need to print the elements of output array.

#include <iostream>
using namespace std;

void sumOfTwoArrays(int input1[], int size1, int input2[], int size2, int output[]){
    int maxSize=0;
    if(size1>=size2){
        maxSize=size1;
    }
    else{
        maxSize=size2;
    }
    int carry=0;
    int i=size1-1;
    int j=size2-1;
    while(i>=0 || j>=0){
        int sum=0;
        if(i<0){
            sum=input2[j]+carry;
            j--;
        }
        else if(j<0){
            sum=input1[i]+carry;
            i--;
        }
        else{
            sum=input1[i]+input2[j]+carry;
            i--;
            j--;
        }
        if(sum>=10){
            output[maxSize]=sum%10;
            carry=sum/10;
        }
        else{
            output[maxSize]=sum;
            carry=0;
        }
        maxSize--;
    }
    if(carry){
        output[maxSize]=carry;
        carry=0;
        maxSize--;
    }
}


int main(){
	int size1,size2;
	cin>>size1;
	int * input1=new int[1+size1];
	
	for(int i=0;i<size1;i++)
		cin>>input1[i];

   	 cin>>size2;
	 int * input2=new int[1+size2];
	
	for(int i=0;i<size2;i++)
		cin>>input2[i];
	
	int *output=new int[1+max(size1,size2)];
	int outsize = 1+max(size1,size2);
	sumOfTwoArrays(input1,size1,input2,size2,output);	
	
	for(int i=0;i<outsize;i++)
		cout<<output[i]<<" ";
        
}
