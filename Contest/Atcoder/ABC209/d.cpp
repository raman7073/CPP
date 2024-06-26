/*
https://atcoder.jp/contests/abc209/editorial/2239
Assuming each road has length
1, let us paint red those town whose shortest distance to Town
i is even; otherwise, let us paint them blue.

Then, due to the bipartiteness of trees, we can see that if a person is currently at a red town, then he next goes to blue town; conversely, a person who is now at a blue town will always move to a red town. Therefore, if the colors of the vertices where Takahashi and Aoki were initially were are different, then they never meet at the same town; On the other hand, if those colors are same, they never meet at a road.
Therefore, after we precalculate the color of each town, we can answer each query in an
O(1) time.

To find the colors of the towns, we can use BFS or DFS.
*/
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
void bfs(const vector<vector<int>> &g, int nd, vector<int> &vis)
{
    queue<int> q;
    vis[nd] = 1;
    q.push(nd);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            if (!vis[v])
            {
                vis[v] = 3 - vis[u];
                q.push(v);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> v(n + 1, vector<int>());
    vector<int> vis(n + 1, 0);
    int x, y;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs(v, 1, vis);
    // for(int x: vis){
    //     cout<<x<<" ";
    // }
    while (q--)
    {
        cin >> x >> y;
        if (vis[x] == vis[y])
        {
            cout << "Town" << endl;
        }
        else
        {
            cout << "Road" << endl;
        }
    }

    return 0;
}