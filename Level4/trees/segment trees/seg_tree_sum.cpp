#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long int
struct sgtree
{
    vector<int> sgt;
    int n;
    void init(int _n)
    {
        this->n = _n;
        this->sgt.resize(4 * _n + 5, 0);
    }
    void build(int st, int en, int node, vector<int> &v)
    {
        if (st == en)
        {
            sgt[node] = v[st];
            return;
        }
        int mid = (st + en) / 2;
        // left subtree
        build(st, mid, 2 * node, v);
        // right subtree
        build(mid + 1, en, 2 * node + 1, v);
        sgt[node] = sgt[2 * node] + sgt[2 * node + 1];
    }
    void build(vector<int> &v)
    {
        build(0, this->n - 1, 1, v);
    }
    int query(int st, int en, int node, int l, int r)
    {
        if (r < st || l > en)
        {

            return 0;
        }
        if (st >= l && en <= r)
        {

            return sgt[node];
        }
        int mid = (st + en) / 2;
        int l1 = query(st, mid, 2 * node, l, r);
        int l2 = query(mid + 1, en, 2 * node + 1, l, r);
        return l1 + l2;
    }
    int query(int l, int r)
    {
        return query(0, this->n-1, 1, l, r);
    }
    void update(int st, int en, int node, int idx, int value)
    {
        if (st == en)
        {
            sgt[node] = value;
            return;
        }
        int mid = (st + en) / 2;
        if (idx <= mid)
        {
            update(st, mid, 2 * node, idx, value);
        }
        else
        {
            update(mid + 1, en, 2 * node + 1, idx, value);
        }
        sgt[node] = sgt[2 * node] + sgt[2 * node + 1];
        return;
    }
    void update(int idx, int value)
    {
        update(0, n - 1, 1, idx, value);
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sgtree s;
    s.init(n);
    s.build(v);
    for (int i = 0; i < m; i++)
    {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1)
        {
            s.update(l, r);
        }
        else
        {
            r--;
            cout << s.query(l, r) << endl;
            
        }
    }
    return 0;
}