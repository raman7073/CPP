// Accepted Solution
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll n)
{
    string s = to_string(n);
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i * i * i <= n; i++)
        if (check(i * i * i))
            ans = i * i * i;
    cout << ans << '\n';
}
