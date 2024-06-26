#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 505;

vector<int> tree[MAXN];
int t[MAXN];
ll s[MAXN];
ll g[MAXN];
bool defeated[MAXN];

bool dfs(int v, ll strength) {
    if (t[v] == 1) {
        if (strength < s[v]) {
            return false;
        }
        strength += g[v];
    } else if (t[v] == 2) {
        strength *= g[v];
    }

    for (int u : tree[v]) {
        if (!dfs(u, strength)) {
            return false;
        }
    }

    return true;
}

int main() {
    int N;
    cin >> N;

    for (int i = 2; i <= N; ++i) {
        int p;
        cin >> p >> t[i] >> s[i] >> g[i];
        tree[p].push_back(i);
    }

    bool result = dfs(1, 1LL);

    if (result) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
