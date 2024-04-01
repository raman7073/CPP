#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class UnionFind
{
private:
    vector<int> parent;

public:
    UnionFind(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y)
    {
        parent[find(x)] = find(y);
    }
};

int main()
{
    int N, Q;
    string S;
    cin >> N >> S >> Q;

    // Create Union-Find structure to keep track of character replacements
    UnionFind uf(26); // We'll use characters 'a' to 'z'

    // Process the queries and merge characters accordingly
    char c, d;
    for (int i = 0; i < Q; ++i)
    {
        cin >> c >> d;
        uf.merge(c - 'a', d - 'a');
    }

    // Apply replacements to the string
    for (char &ch : S)
    {
        ch = 'a' + uf.find(ch - 'a');
    }

    // Output the modified string
    cout << S << endl;

    return 0;
}
