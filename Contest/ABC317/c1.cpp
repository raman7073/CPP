#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> E(N + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        E[a][b] = c;
        E[b][a] = c;
    }

    int ans = 0;
    vector<bool> used(N + 1, false);

    function<void(int, int)> dfs = [&](int v, int s)
    {
        used[v] = true;
        if (s > ans)
            ans = s;
        for (int i = 1; i <= N; ++i)
        {
            if (!used[i] && E[v][i])
            {
                dfs(i, s + E[v][i]);
            }
        }
        used[v] = false;
    };

    for (int i = 1; i <= N; ++i)
    {
        dfs(i, 0);
    }

    cout << ans << endl;

    return 0;
}
