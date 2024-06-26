#include <bits/stdc++.h>

using namespace std;

constexpr int inf = 1 << 30;

constexpr array<pair<int, int>, 4> dxy = {{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}};

vector<vector<int>> bfs(const vector<string> &s, const int sx, const int sy)
{
    const int h = (int)s.size(), w = (int)s[0].size();
    vector<vector<int>> dist(h, vector<int>(w, inf));
    if (s[sx][sy] == '#')
    {
        return dist;
    }
    queue<pair<int, int>> que;
    dist[sx][sy] = 0;
    que.push({sx, sy});
    while (not que.empty())
    {
        const auto [fx, fy] = que.front();
        que.pop();
        for (const auto &[ax, ay] : dxy)
        {
            const int tx = fx + ax, ty = fy + ay;
            if (tx < 0 or ty < 0 or tx >= h or ty >= w or s[tx][ty] == '#')
            {
                continue;
            }
            if (dist[tx][ty] > dist[fx][fy] + 1)
            {
                dist[tx][ty] = dist[fx][fy] + 1;
                que.push({tx, ty});
            }
        }
    }
    return dist;
}

vector<bool> bfs2(const vector<vector<bool>> &isReachable, const int s)
{
    const int n = (int)isReachable.size();
    vector<bool> isSeen(n);
    queue<int> que;
    isSeen[s] = true;
    que.push(s);
    while (not que.empty())
    {
        const int f = que.front();
        que.pop();
        for (int t = 0; t < n; ++t)
        {
            if (isReachable[f][t] and (not isSeen[t]))
            {
                isSeen[t] = true;
                que.push(t);
            }
        }
    }
    return isSeen;
}

int main()
{
    // in
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    int sx = -1, sy = -1, tx = -1, ty = -1;
    for (int i = 0; i < h; ++i)
    {
        cin >> a[i];
        for (int j = 0; j < w; ++j)
        {
            if (a[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            if (a[i][j] == 'T')
            {
                tx = i;
                ty = j;
            }
        }
    }

    int n;
    cin >> n;
    vector<int> r(n), c(n), e(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> r[i] >> c[i] >> e[i];
        --r[i], --c[i];
    }

    // solve
    r.push_back(sx);
    c.push_back(sy);
    e.push_back(0);
    r.push_back(tx);
    c.push_back(ty);
    e.push_back(0);
    n += 2;

    // dist[i][j] : (r[i], c[i]) から (r[j], c[j]) への距離
    vector<vector<bool>> isReachable(n, vector<bool>(n));
    vector<vector<int>> dist;
    for (int i = 0; i < n; ++i)
    {
        auto distMap = bfs(a, r[i], c[i]);
        for (int j = 0; j < n; ++j)
        {
            if (distMap[r[j]][c[j]] <= e[i])
            {
                isReachable[i][j] = true;
            }
        }
    }

    const auto res = bfs2(isReachable, n - 2);

    // out
    const bool ans = res[n - 1];
    cout << (ans ? "Yes" : "No") << endl;
}
