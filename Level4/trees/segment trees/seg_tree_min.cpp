#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
struct segtree
{
    vector<int> sgt;
    int n;
    void init(int _n)
    {
        this->n = _n;
        this->sgt.resize(4 * _n + 5);
    }
    void build(int st, int en, int node, vector<int> &v)
    {
        if (st == en)
        {

            sgt[node] = v[st];
            return;
        }
        int mid = (st + en) / 2;
        build(st, mid, 2 * node, v);
        build(mid + 1, en, 2 * node + 1, v);
        sgt[node] = min(sgt[2 * node], sgt[2 * node + 1]);
    }
    void build(vector<int> &v)
    {
        build(0, this->n - 1, 1, v);
    }
    int query(int st, int en, int node, int l, int r)
    {
        if (r < st || l > en)
        {

            return INT_MAX;
        }
        if (st >= l && en <= r)
        {

            return sgt[node];
        }
        int mid = (st + en) / 2;
        int l1 = query(st, mid, 2 * node, l, r);
        int l2 = query(mid + 1, en, 2 * node + 1, l, r);
        return min(l1, l2);
    }
    int query(int l, int r)
    {
        return query(0, this->n - 1, 1, l, r);
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
        sgt[node] = min(sgt[2 * node], sgt[2 * node + 1]);
    }
    void update(int idx, int value)
    {
        update(0, this->n - 1, 1, idx, value);
    }
};

int main()
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
    segtree tree;
    tree.init(n);
    tree.build(v);
    while (m--)
    {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1)
        {
            tree.update(l, r);
        }
        else
        {
            r--;
            int x = tree.query(l, r);
            cout << x << endl;
        }
    }
    return 0;
}