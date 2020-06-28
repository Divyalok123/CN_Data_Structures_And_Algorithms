// Given a string and a character x. Write a function to remove all occurrences of x character from the given string.
// Leave the string as it is, if the given character is not present in the string.

#include <iostream>
using namespace std;

#include <cstring>

// input - given string
// You need to remove all occurrences of character c that are present in string input.
// Change in the input itself. So no need to return or print anything.

void removeAllOccurrencesOfChar(char input[], char c) {
    int count = 0;
    for(int i = 0; i < strlen(input); i++)
    {
        if(input[i] != c)
        {
            input[count] = input[i];
            count++;
        }
    }
    
    input[count] = '\0';
}


int main() {
    char input[1000];
    cin.getline(input, 1000);
    char c;
    cin >> c;
    removeAllOccurrencesOfChar(input, c);
    cout << input << endl;
}
