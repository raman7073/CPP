/*
https://atcoder.jp/contests/abc211/tasks/abc211_b
You are given four strings
S1,S2,S3, and S4.
Determine whether this sequence of strings has one of each of the following:
 H, 2B, 3B, and HR.
Here, it is guaranteed that every
Si is H, 2B, 3B, or HR.

Concept :
If it is guaranteed that every Si is H, 2B, 3B, or HR. So To determine
whether the sequence of strings has one of each,we can find if any of string
is repeating.If any of string is repeating , it means any of string is missing.

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> s(4);
    for (int i = 0; i < 4; i++)
        cin >> s[i];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i != j && s[i] == s[j])
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}