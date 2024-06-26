#include <bits/stdc++.h>

using namespace std;

constexpr int inf = 1 << 30;

constexpr array<pair<int, int>, 4> dxy = {{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}};

int main()
{
    // in
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    int sx = -1, sy = -1, gx = -1, gy = -1;
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
                gx = i;
                gy = j;
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

    // s[i][j] : (i, j) にある薬の強さ
    vector<vector<int>> s(h, vector<int>(w));
    for (int i = 0; i < n; ++i)
    {
        s[r[i]][c[i]] = e[i];
    }

    vector<vector<int>> dp(h, vector<int>(w, -1));
    dp[sx][sy] = 0;
    queue<pair<int, int>> que;
    que.push({sx, sy});
    while (not que.empty())
    {
        const auto [fx, fy] = que.front();
        que.pop();
        const int nd = max(dp[fx][fy], s[fx][fy]);
        if (nd <= 0)
        {
            continue;
        }
        for (const auto &[ax, ay] : dxy)
        {
            const int tx = fx + ax, ty = fy + ay;
            if (tx < 0 or ty < 0 or tx >= h or ty >= w or a[tx][ty] == '#')
            {
                continue;
            }
            if (dp[tx][ty] < nd - 1)
            {
                dp[tx][ty] = nd - 1;
                que.push({tx, ty});
            }
        }
    }

    bool ans = dp[gx][gy] != -1;
    cout << (ans ? "Yes" : "No") << endl;
}
