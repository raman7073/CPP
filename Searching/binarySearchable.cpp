#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        vector<int> v(n), suffixMin(n), prefixMax(n);

        for (int i = 0; i < n; i++)
        {

            cin >> v[i];
        }

        int mx = v[0];

        prefixMax[0] = 0;

        int mn = v[n - 1];

        suffixMin[n - 1] = 1e9 + 1;

        for (int i = 1; i < n; i++)
        {

            mx = max(mx, v[i - 1]);

            prefixMax[i] = mx;
        }

        for (int i = n - 2; i >= 0; i--)
        {

            mn = min(mn, v[i + 1]);

            suffixMin[i] = mn;
        }

        vector<int> ans;

        int vdx = 0;

        for (int i = 0; i < n; i++)
        {

            if (prefixMax[i] < v[i] && v[i] < suffixMin[i])
            {

                vdx++;

                ans.push_back(i);
            }
        }

        // for(int y:pmx) cout<<y<<" ";

        // cout<<endl;

        // for(int y:smn) cout<<y<<" ";

        // cout<<endl;

        cout << vdx << endl;

        for (int x : ans)
            cout << x << " ";

        cout << endl;
    }

    return 0;
}