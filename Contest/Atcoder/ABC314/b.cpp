#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>());
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++)
        {
            int b;
            cin >> b;
            v[i].push_back(b);
        }
    }
    int x;
    cin >> x;
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++)
    {
        int sz = v[i].size();
        for (int j = 0; j < sz; j++)
        {
            if (v[i][j] == x)
            {
                vp.push_back({sz, i + 1});
            }
        }
    }
    if (vp.size() == 0)
    {
        cout << 0;
    }
    else
    {
        sort(vp.begin(), vp.end());
        vector<int> ans;
        ans.push_back(vp[0].second);
        for (int i = 1; i < vp.size(); i++)
        {
            if (vp[i].first == vp[i - 1].first)
            {
                ans.push_back(vp[i].second);
            }
            else
            {
                break;
            }
        }
        cout << ans.size() << endl;
        for (int x : ans)
        {
            cout << x << " ";
        }
    }

    return 0;
}