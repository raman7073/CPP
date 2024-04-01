#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
vector<int> order(2e5+1);
vector<int> bfs(int n, vector<vector<int>> &adj)
{
    queue<int> qu;
    vector<bool> vis(n + 1, false);
    qu.push(1);
    vis[1] = true;
    vector<int> ans;
    while (!qu.empty())
    {
        int x = qu.front();
        qu.pop();
        ans.push_back(x);

        for (int nbr : adj[x])
        {
            if (!vis[nbr])
            {
                vis[nbr] = true;
                qu.push(nbr);
            }
        }
    }
    return ans;
}
bool comp(int i, int j)
{

    return order[i] < order[j];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1, vector<int>());
    int x, y;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<int> seq(n);
    order.reserve(n+1);
    for (int i = 0; i < n; i++)
    {
        cin >> seq[i];
        order[seq[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        sort(v[i].begin(), v[i].end(), comp);
    }
    vector<int> res = bfs(n, v);
    // for (int x : res)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
    if (res == seq)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}