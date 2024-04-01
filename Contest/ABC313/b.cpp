#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
void dfs(int currentNode, vector<bool> &vis, vector<vector<int>> &v)
{
    vis[currentNode] = true;
    for (int nb : v[currentNode])
    {
        if (vis[nb] == false)
            dfs(nb, vis, v);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    int ans = -1;
    vector<int> res;

    for (int i = 1; i <= n; i++)
    {
        vector<bool> vis(n + 1, false);
        dfs(i, vis, v);
        ans = i;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == false)
            {
                ans = -1;
                break;
            }
        }
        if(ans!=-1){
            res.push_back(ans);
        }
    }
    if(res.size()==1){
        cout<<res[0];
    }else{
      cout<<-1;
    }
   
    return 0;
}