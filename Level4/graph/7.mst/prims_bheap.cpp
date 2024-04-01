/* for undirected connected weighted graph */
#include <bits/stdc++.h>
using namespace std;

// Print the minimum spanning tree
void printMst(vector<int> &parent, vector<vector<pair<int, int>>> &graph)
{
    cout << "Src.\tDest.\tWeight\n";
    for (int i = 1; i < parent.size(); i++)
    {
        // cout << i << "\t" << parent[i] << "\t" << graph[i][parent[i]] << "\n";
        cout << i << "\t" << parent[i] << "\n";
    }
}

int findMST(int V, vector<vector<pair<int, int>>> &graph)
{
    vector<int> parent(V);
    vector<bool> setMST(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int res = 0;

    parent[0] = -1;
    pq.push({0, 0}); // w , u
    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        if (setMST[p.second])
            continue;
        setMST[p.second] = true;
        res += p.first;
        for (pair<int, int> nbr : graph[p.second])
        {
            if (setMST[nbr.first] == false)
            {
                pq.push({nbr.second, nbr.first});
                parent[nbr.first] = p.second;
            }
        }
    }

    cout << endl;
    printMst(parent, graph);
    cout << endl;
    return res;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> graph(V, vector<pair<int, int>>());
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    cout << findMST(V, graph);
    return 0;
}
