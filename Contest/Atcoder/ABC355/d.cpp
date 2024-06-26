#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define int long long
#define endl '\n'
// #define LOCAL

inline void solve()
{
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    // sorting will help us to find the number of pairs that are not intersecting
    // if the rectangles are intersecting then the left of one rectangle will be less than the right of the other
    // sorting will only change the dimensions of the rectangles
    sort(l.begin(), l.end()), sort(r.begin(), r.end());
    // total possible pairs
    int ans = n * (n - 1) / 2;
    // cout << ans << endl;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (r[j] < l[i])
            j += 1;
        ans -= j;
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
