// Given a String s, check it its palindrome. Return true if string is palindrome, else return false.
// Palindrome strings are those, where string s and its reverse is exactly same.

#include<iostream>
using namespace std;

bool checkPalindrome(char str[]){
    int i = 0;
    int j = 0;
    while(str[j])
    {
        j++;
    }
    j--;
    int end = j;
    for(int k = 0; k <= end/2; k++)
    {
        if(str[k] != str[j - k]) return false;
    }
    return true;
}


int main(){

  char str[10000];
  cin.getline(str,10000);

  if(checkPalindrome(str)){
  	cout << "true" << endl; 	
  }else{
  cout << "false" << endl;
  }
}

