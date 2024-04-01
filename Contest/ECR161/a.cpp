#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define int long long
int n, m;
// int c[N];
void solve()
{
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != c[i] && b[i] != c[i])
        {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}
signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}