//count no. of substring that either start with a vowel and end with a consonant or start with a consonent and end with a vowel
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nt;
    cin >> nt;
    while (nt--)
    {
        string str;
        cin >> str;
        
        

    }
    return 0;
}

//using regex
        //Note: This code doesn't work
        // smatch match;
        // regex r1("^[aeiou].*[^aeiou]$");
        // regex r2("^[^aeiou].*[aeiou]$");
        // int count1 = 0;
        // while (regex_search(str, match, r1))
        // {
        //     count1++;
        //     str = match.suffix().str();
        // }
        // int count2 = 0;
        // while (regex_search(str, match, r2))
        // {
        //     count2++;
        //     str = match.suffix().str();
        // }
        // cout << count1 + count2 << "\n";