#include <bits/stdc++.h>
using namespace std;
template <typename T>
using vc = vector<T>;
template <typename T>
using vv = vc<vc<T>>;
typedef long long ll;
#define yes              \
    {                    \
        cout << "Yes\n"; \
        return 0;        \
    }
#define no              \
    {                   \
        cout << "No\n"; \
        return 0;       \
    }
#define all(x) x.begin(), x.end()
#define rep(i, n) for (ll i = 0; i < n; i++)
const ll mod = 1000000007;

int main()
{
    string s;
    cin >> s;
    map<char, ll> m;
    for (char c : s)
        m[c]++;
    ll size = s.size();
    ll ans = size * (size - 1) / 2;
    bool b = 0;
    for (auto [k, v] : m)
    {
        ans -= v * (v - 1) / 2;
        if (!b && v > 1)
        {
            ans++;
            b = 1;
        }
    }
    cout << ans << '\n';
}