// Given a String S of length n, print all its substrings.
// Substring of a String S is a part of S (of any length from 1 to n), which contains all consecutive characters from S.

#include<iostream>
using namespace std;

#include <cstring>


void printSubstrings(char str[]){
    int length = strlen(str);
    for(int i = 0; i < length; i++)
    {
        for(int j = i; j < length; j++)
        {
            for(int k = i; k <= j; k++)
            {
                cout << str[k];
            }
            cout << "\n";
        }
    }
}


int main(){

  char str[10000];
  cin.getline(str,10000);

  printSubstrings(str);
}

