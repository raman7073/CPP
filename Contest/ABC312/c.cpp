#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

bool comp(int a, int b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
    }
    sort(A.begin(), A.end(), comp);
    sort(B.begin(), B.end());
    // for (int x : A)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
    // for (int x : B)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int x = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
        //  cout<<"lb-->"<<x<<endl;
        if (x != m)
        {
            int ns = n - i;
            int nb = m - x;
            // cout<<"ns-->"<<ns<<"nb--->"<<nb<<endl;
            if (ns >= nb && ans > A[i])
            {
                ans = A[i];
            }
        }
    }
    if (ans == INT_MAX)
    {
        ans = B[m - 1] + 1;
    }
   
    cout << ans;
    return 0;
}