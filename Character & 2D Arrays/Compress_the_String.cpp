// Write a program to do basic string compression. For a character which is consecutively repeated more than once, replace consecutive duplicate occurrences with the count of repetitions.
// For e.g. if a String has 'x' repeated 5 times, replace this "xxxxx" with "x5".
// Note : Consecutive count of every character in input string is less than equal to 9.

#include <iostream>
#include <cstring>
using namespace std;

void stringCompression(char input[]) {
    int len = strlen(input);
    
    for (int i = 0; i < len; i++) { 

        int count = 1; 
        while (i < len - 1 && input[i] == input[i + 1]) { 
            count++; 
            i++; 
        } 
  
        if(count!=1)
        cout << input[i] << count; 
        else
        cout<<input[i];
    } 
    input[0] = '\0';
}


int main() {
    char input[1000];
    cin.getline(input, 1000);
    stringCompression(input);
    cout << input << endl;
}
