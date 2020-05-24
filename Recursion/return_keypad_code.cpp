// Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
// Return empty string for numbers 0 and 1.
// Note : 1. The order of strings are not important.
// 2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.

#include <iostream>
#include <string>
using namespace std;

#include <string>

using namespace std;

string stock[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
int keypad(int num, string output[]){
    if(num == 0 || num == 1) {
        output[num] = stock[num];
        return 1;
    }
    
    string temp[1000];
    int number = keypad(num/10, temp);
    int k=0;
    int deal = num%10;
    string copy = stock[deal];
    int i;
    for(i = 0; i <copy.size(); i++)
    {
        for(int j=0;j<number;j++){
            output[k]=temp[j]+copy[i];
            k++;
        }
    }    
    return k;
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
