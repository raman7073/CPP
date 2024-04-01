#include <iostream>
#include <vector>

using namespace std;

struct Node {
    long long sum;
};

class SegmentTree {
private:
    vector<Node> tree;
    int n;

public:
    SegmentTree(const vector<long long>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(a, 1, 0, n - 1);
    }

    long long query(int l, int r, int s, int d, int k) {
        return query(1, 0, n - 1, l, r, s, d, k);
    }

private:
    void build(const vector<long long>& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v].sum = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, 2 * v, tl, tm);
            build(a, 2 * v + 1, tm + 1, tr);
            tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;
        }
    }

    long long query(int v, int tl, int tr, int l, int r, int s, int d, int k) {
        if (l > r) return 0;
        if (l == tl && r == tr) {
            return querySequence(s, d, k, tl, tr);
        }
        int tm = (tl + tr) / 2;
        return query(2 * v, tl, tm, l, min(r, tm), s, d, k) +
               query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, s, d, k);
    }

    long long querySequence(int s, int d, int k, int tl, int tr) {
        long long sum = 0;
        for (int i = tl, j = s; i <= tr; i += d, ++j) {
            sum += (j * k) * tree[i].sum;
        }
        return sum;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        SegmentTree segmentTree(a);

        while (q--) {
            int s, d, k;
            cin >> s >> d >> k;
            s--; // Adjusting index to 0-based

            long long sum = segmentTree.query(s, n - 1, s, d, k);
            cout << "ans-->"<<sum << " ";
        }
        cout << endl;
    }

    return 0;
}
