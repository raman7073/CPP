#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
void bfs(int src, vector<vector<int>> &adj, vector<bool> &vis,vector<int>&dis)
{
    queue<int> qu;
    qu.push(src);
    vis[src]=true;
    dis[src]=0;
    while (!qu.empty())
    {
        int x = qu.front();
        qu.pop();
        for (int nbr : adj[x])
        {
            if (!vis[nbr])
            {
                vis[nbr]=true;
                dis[nbr]=dis[x]+1;
                qu.push(nbr);
            }
        }
    }
}
int min_dice_throws(int n, vector<pair<int, int>> snakes, vector<pair<int, int>> ladders)
{
    vector<int> board(n+1,0);
    for(auto sp :snakes){
        int st=sp.first;
        int en=sp.second;
        board[st]=en-st;
    }
    for(auto sp :ladders){
        int st=sp.first;
        int en=sp.second;
        board[st]=en-st;
    }
    vector<vector<int>> g (n+1,vector<int>());
    for(int u=1;u<n;u++){
        for(int dice=1;dice<=6;dice++){
            int v = u+dice;
            v+=board[v];
            if(v<=n){
                g[u].push_back(v);
            }
        }
    }
    vector<bool>vis(n+1,false);
    vector<int>dis(n+1);
    bfs(1,g,vis,dis);
    return dis[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}