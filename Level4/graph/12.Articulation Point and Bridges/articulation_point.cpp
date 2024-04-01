#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int time = 1;               // discovery time variable, it starts with 1 as discussed above
    vector<bool> vis, ap;       // visited array,articulation point
    vector<int> par, disc, low; // arrays to keep track for parent, discovery time, low values
    // method to print stack till the top of the stack not equal to an edge
    void printStackTill_UV(stack<pair<int, int>> &st, pair<int, int> &p)
    {
        while (!st.empty())
        {
            cout << st.top().first << "-" << st.top().second << ", ";
            if (st.top() == p)
            {
                st.pop();
                break;
            }
            st.pop();
        }
        cout << endl;
    }

public:
    void print_biconnected_component(vector<vector<int>> &graph, int &n)
    {
        low.resize(n + 1, 0);     // mark the low value of each node is 0
        vis.resize(n + 1, false); // mark the visited array as false
        par.resize(n + 1, -1);    // mark the parent of each node as -1
        disc.resize(n + 1, 0);    // mark the discovery time of each node
        ap.resize(n + 1, false);  // mark the node as non-articulation point

        // greaph can have multiple components, so we need to go to each
        // node and apply DFS
        for (int i = 1; i <= n; i++)
        {
            // if the current is not previously visited
            if (vis[i] == false)
            {
                stack<pair<int, int>> st; // stack of edges
                DFS(i, graph, st);        // call DFS

                // print the stack when DFS call returns
                while (!st.empty())
                {
                    cout << st.top().first << "-" << st.top().second << ", ";
                    st.pop();
                }
            }
        }
    }
    void DFS(int src, vector<vector<int>> &graph, stack<pair<int, int>> &st)
    {
        disc[src] = low[src] = time; // mark the low time and discovery time
        time++;                      // increment the time
        vis[src] = true;             // mark visited as true
        int child = 0;               // varible to keep count of DFS call made from source

        vector<int> nbrs = graph[src]; // iterate over all neighbours
        for (auto &nbr : nbrs)
        {
            pair<int, int> edge = {src, nbr}; // current edge
            if (vis[nbr] == false)
            { // if the neighbour is not previously visited
                child += 1;
                par[nbr] = src;                     // mark the parent
                st.push(edge);                      // push edge to stack
                DFS(nbr, graph, st);                // make DFS call
                low[src] = min(low[src], low[nbr]); // update the low time
                // for root node
                if (par[src] == -1 and child > 1)
                { // check for Articulation point, if it's true then print all edges
                    ap[src] = true;
                    printStackTill_UV(st, edge);
                }
                // for non-root node
                if (par[src] != -1 and low[nbr] >= disc[src])
                { // check for Articulation point, if it's true then print all edges
                    ap[src] = true;
                    printStackTill_UV(st, edge);
                }
            } //if there is back edge
            else if (par[src] != nbr and disc[nbr] < low[src])
            {                         // if the neighbour is previously visited
                low[src] = disc[nbr]; // update the low value
                st.push(edge);        // push edge to stack
            }
        }
    }
};
int main()
{
    // Driver code
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>{});
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    Solution sol;
    sol.print_biconnected_component(graph, n);
    cout << endl;
    cout << "aticulation point --->";
    for (int i = 1; i <= n; i++)
    {
        if (sol.ap[i] == true)
            cout << i << " ";
    }
}
