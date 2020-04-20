// Given an input string S that contains multiple words, you need to remove all the spaces present in the input string.
// There can be multiple spaces present after any word.

#include <iostream>
using namespace std;


void trimSpaces(char input[]) {
    int count = 0;
    for(int j =0; input[j]; j++)
    {
        if(input[j] != ' ')
        {
            input[count] = input[j];
            count++;
        }
    }
    input[count] = '\0';
}


int main() {
    char input[1000000];
    cin.getline(input, 1000000);
    trimSpaces(input);
    cout << input << endl;
}


