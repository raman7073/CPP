#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
#define int long long

using namespace std;

class DSU
{
public:
    DSU(int n) : parent(n), size(n, 1)
    {
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }

    int getSize(int x)
    {
        return size[find(x)];
    }

private:
    vector<int> parent;
    vector<int> size;
};

int32_t main()
{
    int Q;
    long long K;
    cin >> Q >> K;

    DSU dsu(2 * Q);                         // We use 2*Q to handle both types of queries efficiently
    unordered_map<long long, int> indexMap; // Map element to its corresponding index in DSU
    int currentIndex = 0;

    while (Q--)
    {
        int type, x;
        cin >> type >> x;

        if (type == 1)
        {
            if (indexMap.find(x) == indexMap.end())
            {
                indexMap[x] = currentIndex++;
            }
            if (indexMap.find(x + K) != indexMap.end())
            {
                dsu.merge(indexMap[x], indexMap[x + K]);
            }
            if (indexMap.find(x - K) != indexMap.end())
            {
                dsu.merge(indexMap[x], indexMap[x - K]);
            }
        }
        else
        {
            cout << dsu.getSize(indexMap[x]) << endl;
        }
    }

    return 0;
}
