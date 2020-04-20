// Given two strings, check if they are permutations of each other. Return true or false.
// Permutation means - length of both the strings should same and should contain same set of characters. Order of characters doesn't matter.
// Note : Input strings contain only lowercase english alphabets.

#include <iostream>
using namespace std;

#include <cstring>

bool isPermutation(char input1[], char input2[]) {
    int counter1[26] = {0};
    int counter2[26] = {0};
    
    if(strlen(input1) != strlen(input2)) return false;
    
    for(int i = 0, j=0; i < strlen(input1), j < strlen(input2); i++, j++)
    {
        counter1[input1[i] - 'a']++;
        counter2[input2[j] - 'a']++;
    }
    
    for(int i = 0; i < 26; i++)
    {
        if(counter1[i] != counter2[i]) return false;
    }
    
    return true;
}


int main() {
    char input1[1000], input2[1000];
    cin.getline(input1, 1000);
    cin.getline(input2, 1000);
    if(isPermutation(input1, input2) == 1) {
        cout << "true";
    }
    else {
        cout << "false";
    }
}
