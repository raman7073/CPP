#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 998244353
const int MAXN = 1001;
const int MAXK = 1025;

int n, k;
string s;
int dp[MAXN][MAXK];

bool get(int mask)
{
    for (int i = 0; i < k / 2; ++i)
    {
        int p1 = (mask & (1 << i)) > 0;
        int p2 = (mask & (1 << (k - i - 1))) > 0;
        if (p1 != p2)
            return true;
    }
    return false;
}

int getMask(int mask, int i, int c)
{
    if (i < k)
        return mask + c * (1 << i);
    return (mask >> 1) + c * (1 << (k - 1));
}

int rec(int i, int mask)
{
    if (i >= k && !get(mask))
        return 0;
    if (i == n)
        return 1;
    if (dp[i][mask] != -1)
        return dp[i][mask];

    int ans = 0;
    if (s[i] != '?')
        ans = rec(i + 1, getMask(mask, i, (s[i] == 'A')));
    else
        ans = (rec(i + 1, getMask(mask, i, 0)) + rec(i + 1, getMask(mask, i, 1))) % mod;

    return dp[i][mask] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> k >> s;
        memset(dp, -1, sizeof(dp));
        cout << rec(0, 0) << "\n";
    }

    return 0;
}
