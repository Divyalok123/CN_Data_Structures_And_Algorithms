/*
Write a program to count and print the total number of characters (lowercase english alphabets only), digits (0 to 9) and white spaces (single space, tab i.e. '\t' and newline i.e. '\n') entered till '$'.
That is, input will be a stream of characters and you need to consider all the characters which are entered till '$'.
Print count of characters, count of digits and count of white spaces respectively (separated by space).
*/

#include<iostream>
using namespace std;

int main(){
    int count1 = 0, count2 = 0, count3 = 0;
    char s;
    
    while(s != '$')
    {
        s = cin.get();
        
        if(s >= 'a' && s <= 'z'){
            count1++;
        }
        else if(s >= '0' && s <= '9'){
            count2++;
        }
        else if(s == ' ' || s == '\n' || s=='\t') {
            count3++;
        }
       
        continue;
    }
    cout << count1 << " " << count2 << " " << count3;
    return 0;  
}


