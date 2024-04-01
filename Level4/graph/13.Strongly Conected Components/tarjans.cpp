#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph
{
    int V;            // Number of vertices
    vector<int> *adj; // Adjacency list

    void tarjanUtil(int u, vector<int> &disc, vector<int> &low, stack<int> &st, vector<bool> &inStack, vector<vector<int>> &scc)
    {
        static int time = 0;

        disc[u] = low[u] = ++time;
        st.push(u);
        inStack[u] = true;

        for (int v : adj[u])
        {
            if (disc[v] == -1)
            {
                tarjanUtil(v, disc, low, st, inStack, scc);
                low[u] = min(low[u], low[v]);
            }
            else if (inStack[v])
            {
                low[u] = min(low[u], disc[v]);
            }
        }

        if (low[u] == disc[u])
        {
            vector<int> currentSCC;
            while (true)
            {
                int v = st.top();
                st.pop();
                inStack[v] = false;
                currentSCC.push_back(v);
                if (u == v)
                    break;
            }
            scc.push_back(currentSCC);
        }
    }

public:
    Graph(int V)
    {
        this->V = V;
        adj = new vector<int>[V];
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    vector<vector<int>> findSCCs()
    {
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        stack<int> st;
        vector<bool> inStack(V, false);
        vector<vector<int>> scc;

        for (int i = 0; i < V; ++i)
        {
            if (disc[i] == -1)
            {
                tarjanUtil(i, disc, low, st, inStack, scc);
            }
        }

        return scc;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    vector<vector<int>> scc = g.findSCCs();

    cout << "Strongly Connected Components:\n";
    for (const vector<int> &component : scc)
    {
        for (int vertex : component)
        {
            cout << vertex << " ";
        }
        cout << "\n";
    }

    return 0;
}
