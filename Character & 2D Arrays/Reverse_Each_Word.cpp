// Given a string S, reverse each word of a string individually. For eg. if a string is "abc def", reversed string should be "cba fed".

#include <iostream>
using namespace std;

void swap(char*a, char*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char arr[], int start, int end)
{
    while(start < end)
    {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
            
    }
}


void reverseEachWord(char input[]) 
{
    int begin = 0;
    int temp = 0;
    while(input[temp] != '\0')
    {
        temp++;
        if(input[temp] == '\0') 
        {
            reverse(input, begin, temp-1);
        }
        else if(input[temp] == ' ')
        {
            reverse(input, begin, temp-1);
            begin = temp + 1;
        }
    }        

}


int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseEachWord(input);
    cout << input << endl;
}
