#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i < n; i++)
    {
        v[i] ^= v[i - 1];
    }
    int l, r;
    cin >> l >> r;
    cout << (v[r] ^ v[l - 1]);
    return 0;
}