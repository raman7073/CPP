#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int findCenter(vector<vector<int>> edges)
{
    int n = edges.size();
    vector<list<int>> v(n + 2, list<int>());
    for (int i = 0; i < n; i++)
    {
        v[edges[i][0]].push_back(edges[i][1]);
        v[edges[i][1]].push_back(edges[i][0]);
    }
    int ans = 0;
    for (int i = 1; i < v.size(); i++)
    {
        std::cout << v[i].size() << std::endl;
        if (v[i].size() == n)
            ans = i;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}