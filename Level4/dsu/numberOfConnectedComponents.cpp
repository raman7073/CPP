//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int rank1[100001];

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Find function
    int find(int node, int parent[])
    {

        // If the node is the parent of
        // itself then it is the leader
        // of the tree.
        if (node == parent[node])
            return node;

        // Else, finding parent and also
        //  compressing the paths.
        return parent[node] = find(parent[node], parent);
    }
    // Function to merge two nodes a and b.
    void unionNodes(int u, int v, int parent[], int rank[], int n)
    {
        // code here
        //  Make u as a leader
        // of its tree.
        int rep_u = find(u, parent);

        // Make v as a leader
        // of its tree.
        int rep_v = find(v, parent);

        // If u and v are not equal,
        // because if they are equal then
        // it means they are already in
        // same tree and it does not make
        // sense to perform union operation.
        if (rep_u != rep_v)
        {
            // Checking tree with
            // smaller depth/height.
            if (rank[rep_u] < rank[rep_v])
            {
                int temp = rep_u;
                rep_u = rep_v;
                rep_v = temp;
            }
            // Attaching lower rank tree
            // to the higher one.
            parent[rep_v] = rep_u;

            // If now ranks are equal
            // increasing rank of u.
            if (rank[rep_u] == rank[rep_v])
                rank[rep_u]++;
        }
    }

    // Function to determine number of connected components.
    int findNumberOfConnectedComponents(int n, int arr[], int rank1[])
    {
        // code here
        set<int> s;
        for (int i = 1; i <= n; i++)
        {
            // cout<<arr[i]<<" ";
            s.insert(find(i, arr));
        }
        return s.size();
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        // taking number of nodes
        int n;
        cin >> n;

        // initializing parent array and
        // rank array
        for (int i = 1; i <= n; i++)
        {
            arr[i] = i;
            rank1[i] = 1;
        }

        // taking number of queries
        int q;
        cin >> q;
        Solution obj;
        while (q--)
        {
            int a, b;
            cin >> a >> b;

            // calling unionNodes() function
            obj.unionNodes(a, b, arr, rank1, n);
        }

        // calling function findNumberofConnectedComponents()
        cout << obj.findNumberOfConnectedComponents(n, arr, rank1) << endl;
    }
    return 0;
}
// } Driver Code Ends