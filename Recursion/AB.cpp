#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
string s;
int k, n;
int dp[1001][1025];
bool isPalindrome(const string &str, int start, int end)
{
    // cout << start << " " << end << endl;
    while (start < end)
    {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}
int f(string &s, int i, string ans)
{
    if (i >= k && isPalindrome(ans, i - k, i - 1))
    {

        return 0;
    }

    if (i == n)
    {
        return 1;
    }

    if (s[i] != '?')
        return f(s, i + 1, ans + s[i]);
    else
    {
        return f(s, i + 1, ans + 'A') + f(s, i + 1, ans + 'B');
    }
}
int masking(int mask, int i, int c)
{
    if (i < k)
        return mask + c * (1 << i);
    return (mask >> 1) + c * (1 << (k - 1));
}
bool unmasking(int mask)
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
int f2(string &s, int i, int mask)
{
    if (i >= k && !unmasking(mask))
    {

        return 0;
    }

    if (i == n)
    {
        return 1;
    }
    if (dp[i][mask] != -1)
        return dp[i][mask];
    if (s[i] != '?')
        return dp[i][mask] = f2(s, i + 1, masking(mask, i, s[i] == 'A' ? 1 : 0));
    else
    {
        return dp[i][mask] = f2(s, i + 1, masking(mask, i, 1)) + f2(s, i + 1, masking(mask, i, 0));
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // string ans = "";

    cin >> n;
    cin >> k;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    cout << f2(s, 0, 0);

    return 0;
}