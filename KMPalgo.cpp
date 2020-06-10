//Pattern searching algo 
//Knuth-Morris-algo 
// LSP - longest suffix prefix
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void computelps(string pattern, int m, int* lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while(i < m)
    {
        if(pattern[i] == pattern[len])
        {
            lps[i] = len+1;
            len++;
            i++;
        }
        else
        {
            if(len != 0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
            
        }
        
    }
}

void kmp(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();

    int lps[1000];
    computelps(pattern, m, lps);

    int i = 0;
    int j = 0;
    while(i < n)
    {
        if(pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if(j == m)
        {
            cout << i << endl;
            j = lps[j-1];
        }

        else if(pattern[j] != text[i] && i < n)
        {
            if(j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j-1];
            }
        }
    }
}

int main()
{
    string text, pattern;
    cin >> text >> pattern;
    kmp(text, pattern);
    return 0;
}