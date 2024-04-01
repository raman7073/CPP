#include <iostream>
#include <vector>
#include <set>
using namespace std;

void dfs(int current, int destination, vector<vector<int>> &adjList, vector<bool> &visited, vector<int> &path, vector<vector<int>> &allPaths, vector<int> &value)
{
    visited[current] = true;
    path.push_back(value[current]); // Adjust indexing for 'value' array

    if (current == destination)
    {
        allPaths.push_back(path);
    }
    else
    {
        for (int neighbor : adjList[current])
        {
            if (!visited[neighbor])
            {
                dfs(neighbor, destination, adjList, visited, path, allPaths, value);
            }
        }
    }

    visited[current] = false;
    path.pop_back();
}

vector<vector<int>> findAllPaths(int start, int end, vector<vector<int>> &adjList, vector<int> &value)
{
    vector<vector<int>> allPaths;
    vector<bool> visited(adjList.size(), false);
    vector<int> path;

    dfs(start, end, adjList, visited, path, allPaths, value);

    return allPaths;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<int> value(N + 1);
    vector<vector<int>> adjList(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> value[i];
    }
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<vector<int>> allPaths = findAllPaths(1, N, adjList, value);

    set<int> s;
    int ans = 0;
    for (const auto &path : allPaths)
    {
        s.insert(path[0]);

        int flag = 1;
        for (int i = 1; i < path.size(); i++)
        {
            if (path[i] < path[i - 1])
            {
                flag = 0;
                break;
            }
            s.insert(path[i]);
        }
        if (flag == 1)
        { // Correct comparison
            ans = max(ans, (int)s.size());
        }

        s.clear();
    }
    cout << ans;

    return 0;
}
