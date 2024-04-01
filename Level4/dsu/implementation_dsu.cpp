/* Amortized O(1)*/
class DSU
{

    // Declaring two arrays to hold
    // information about parent and
    // rank of each node.
    vector<int> parent;
    vector<int> rank;

public:
    // Constructor
    DSU(int n)
    {

        // Defining size of the arrays.
        this.parent.reserve(n);
        this.rank.reserve(n);

        // Initializing their values
        // by is and 0s.
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Find function
    int find(int node)
    {

        // If the node is the parent of
        // itself then it is the leader
        // of the tree.
        if (node == parent[node])
            return node;

        // Else, finding parent and also
        //  compressing the paths.
        return parent[node] = find(parent[node]);
    }

    // Union function
    void Union(int u, int v)
    {

        // Make u as a leader
        // of its tree.
        rep_u = find(u);

        // Make v as a leader
        // of its tree.
        rep_v = find(v);

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
    bool isConnected(int u, int v)
    {
        if (find(u) == find(v))
            return true;
        else
            return false;
    }
};
