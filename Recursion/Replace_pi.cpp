// Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".


#include <iostream>
using namespace std;

#include <cstring>
void replacePi(char input[])
{
    if (input[0] == '\0' || input[1] == '\0')
        return;

    if (strlen(input) == 0)
        return;

    replacePi(input + 1);

    if (input[0] == 'p' && input[1] == 'i')
    {
        for (int i = strlen(input) - 1; i >= 0; i--)
        {
            input[i + 2] = input[i];
        }
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
    }
}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
