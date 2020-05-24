// Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.

#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

string stock[10] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void helper(int num, string output)
{
    if (num == 0 || num == 1)
    {
        cout << output << '\n';
        return;
    }
    int deal = num % 10;
    string copy = stock[deal - 2];
    int size = copy.size();
    while (size != 0)
    {
        helper(num / 10, copy[size - 1] + output);
        size--;
    }
}

void printKeypad(int num)
{
    string output = "";
    helper(num, output);
}

int main()
{
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
