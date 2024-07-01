#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int idxR = s[0] == 'R' ? 0 : s[1] == 'R' ? 1
                                             : 2;
    int idxM = s[0] == 'M' ? 0 : s[1] == 'M' ? 1
                                             : 2;

    if (idxR < idxM)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}