#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class key, class cmp = std::less<key>>
using op_set = tree<key, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
#ifdef thunder
#include "bug.h"
#else
#define bug(...)
#endif

#define ll long long
#define lld double
#define all(x) x.begin(), x.end()
#define iceil(n, x) (((n) + (x) - 1) / (x))

const ll INF = 2e18;
const ll mod = 1000000007;
const ll maxn = 2e5 + 5;

ll n;
vector<ll> g[maxn];
vector<ll> revg[maxn];
vector<ll> a(maxn);
vector<ll> vis(maxn);
vector<ll> order;
vector<ll> cond_sz(maxn);
vector<ll> cond_ids(maxn);
vector<ll> cond_g[maxn];
vector<ll> dp(maxn);

void dfs(ll node)
{
    vis[node] = 1;
    for (auto &i : g[node])
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    order.push_back(node);
}

void dfs1(ll node, const ll id)
{
    cond_ids[node] = id;
    cond_sz[id]++;
    vis[node] = 1;
    for (auto &i : revg[node])
    {
        if (!vis[i])
        {
            dfs1(i, id);
        }
    }
}

void dfs_dp(ll node)
{
    vis[node] = 1;
    dp[node] = cond_sz[node];
    for (auto &i : cond_g[node])
    {
        if (!vis[i])
        {
            dfs_dp(i);
        }
        dp[node] += dp[i];
    }
}

void solve()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        g[i].push_back(a[i]);
        revg[a[i]].push_back(i);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    reverse(all(order));
    vis = vector<ll>(maxn, 0);
    for (ll i : order)
    {
        if (!vis[i])
        {
            dfs1(i, i);
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        for (auto &j : g[i])
        {
            if (cond_ids[i] != cond_ids[j])
            {
                cond_g[cond_ids[i]].push_back(cond_ids[j]);
            }
        }
    }
    vis = vector<ll>(maxn, 0);
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs_dp(i);
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        ans += dp[cond_ids[i]];
    }
    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t = 1;
    // cin>>t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}