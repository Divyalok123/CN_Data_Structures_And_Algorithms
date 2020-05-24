// Given a string, compute recursively a new string where all 'x' chars have been removed.

#include <iostream>
using namespace std;

#include <cstring>

void removeX(char input[]) {
    if(strlen(input) == 0) return;
    
    if(input[0] == 'x')
    {
        
        for(int i = 0; i < strlen(input)-1; i++)
        {
            input[i] = input[i+1];     
        }
        input[strlen(input) - 1] = '\0';
        removeX(input);
    }
    
    removeX(input+1);
}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
