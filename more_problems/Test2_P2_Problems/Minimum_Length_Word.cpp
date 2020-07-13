// Given a string S (that can contain multiple words), you need to find the word which has minimum length.

#include<iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

void minLengthWord(char input[], char output[])
{
    int len = strlen(input);
    int s = 0;
    int e = 0;
    int min_length = len;
    int min_idx = 0;

    while (e <= len)
    {
        if (e < len && input[e] != ' ')
        {
            e++;
        }

        else
        {
            int curr = e - s;
            if (curr < min_length)
            {
                min_length = curr;
                min_idx = s;
            }
            e++;
            s = e;
        }
    }
    
    int k = 0;
    for (int i = min_idx; i < min_idx + min_length; i++)
    {
        output[k] = input[i];
        k++;
    }
    output[k] = '\0';
}

int main(){
  char ch[10000], output[10000];
  cin.getline(ch, 10000);
  minLengthWord(ch, output);
  cout << output << endl;
}
