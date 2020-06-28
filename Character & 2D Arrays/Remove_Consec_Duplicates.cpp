// Given a string, remove all the consecutive duplicates that are present in the given string. That means, if 'aaa' is present in the string then it should become 'a' in the output string.

#include <iostream>
using namespace std;

#include<cstring>

// input - given string
// You need to update in the input string itself. No need to return or print anything

void removeConsecutiveDuplicates(char input[]) {
    int i = 0;
    for(int j = 0; j < strlen(input); j++)
    {
        if(input[j] == input[i]) continue;
        else 
        {
            i++;
            input[i] = input[j];
        }
    }
    input[++i] = '\0';
}


int main() {
    char input[1000];
    cin.getline(input, 1000);
    removeConsecutiveDuplicates(input);
    cout << input << endl;
}
