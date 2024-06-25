//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// } Driver Code Ends

class Solution
{
public:
    long maxEdgeSum(int n, vector<vector<int>> &edges)
    {
        // Sort edges based on weight
        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[2] < b[2]; });

        UnionFind uf(n);
        long totalMaxWeight = 0;

        for (const auto &edge : edges)
        {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            int weight = edge[2];

            int sizeU = uf.getSize(u);
            int sizeV = uf.getSize(v);

            totalMaxWeight += (long)weight * sizeU * sizeV;

            uf.unionSets(u, v);
        }

        return totalMaxWeight;
    }

private:
    class UnionFind
    {
    public:
        vector<int> parent;
        vector<int> size;

        UnionFind(int n)
        {
            parent.resize(n);
            size.resize(n, 1);
            for (int i = 0; i < n; ++i)
            {
                parent[i] = i;
            }
        }

        int find(int u)
        {
            if (parent[u] != u)
            {
                parent[u] = find(parent[u]);
            }
            return parent[u];
        }

        bool unionSets(int u, int v)
        {
            int rootU = find(u);
            int rootV = find(v);

            if (rootU == rootV)
            {
                return false;
            }

            if (size[rootU] < size[rootV])
            {
                parent[rootU] = rootV;
                size[rootV] += size[rootU];
            }
            else
            {
                parent[rootV] = rootU;
                size[rootU] += size[rootV];
            }

            return true;
        }

        int getSize(int u)
        {
            return size[find(u)];
        }
    };
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        vector<vector<int>> edges(n - 1, vector<int>(3));
        Matrix::input(edges, n - 1, 3);

        Solution obj;
        long long res = obj.maxEdgeSum(n, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends