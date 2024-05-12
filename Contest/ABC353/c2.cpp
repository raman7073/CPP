#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define ll long long
typedef unsigned int ui;
using namespace std;
ll m = 100000000;
const ll mod = 1000000007;
void solve()
{
    ll n, sum = 0;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i] * (n - 1);
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        auto j = lower_bound(a, a + n, m - a[i]) - a;
        j = (j > i + 1 ? j : i + 1);
        sum -= (n - j) * m;
    }
    cout << sum << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt = 1; // cin>>tt;
    while (tt--)
    {
        solve();
    }
}