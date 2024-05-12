#include <bits/stdc++.h>
#define int long long
#define g(a, b) __gcd(a, b)
#define l(a, b) (a * b) / __gcd(a, b)
const int M = 1e8;
using namespace std;
int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b & 1 == 1)
    {
        return a * power(a * a, b / 2);
    }
    return power(a * a, b / 2);
}
int32_t main()
{
    int t = 1;
    // cin>>t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += (v[i] * (n - 1));
        }

        // cout << sum << "\n";
        sort(v.begin(), v.end());
        // for (int x : v)
        // {
        //     cout << x << " ";
        // }
        // cout << sum << "\n";
        int count = 0;
        // count -> number of pairs st their sum is greater than or equal to M
        int idx = 0;
        for (int i = 1; i < n; i++)
        {
            if (v[i] >= (M - v[i - 1]))
            {
                idx = i - 1;
                break;
            }
        }
        count = (n - idx - 1) * (n - idx) / 2;
        for (int i = 0; i < idx; i++)
        {
            int j = lower_bound(v.begin() + idx, v.end(), M - v[i]) - v.begin();
            if (j == n)
            {
                continue;
            }
            j = (j > i + 1 ? j : i + 1);
            count += (n - j);
        }
        cout << sum - count * M << "\n";
    }
}