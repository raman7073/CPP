#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "Takahashi")
            ans++;
    }
    cout << ans;

    return 0;
}