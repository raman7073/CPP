#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    vector<int> palin(N, 0);

    for (int i = 1; i < N; ++i) {
        palin[i] = palin[i - 1] + (S[i - 1] == S[i] ? 1 : 0);
    }

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            char c;
            cin >> x >> c;
            --x;
            if (x > 0 && S[x] == S[x - 1]) {
                palin[x] = palin[x - 1];
            }
            if (x < N - 1 && S[x] == S[x + 1]) {
                palin[x + 1] = palin[x];
            }
            S[x] = c;
        } else {
            int L, R;
            cin >> L >> R;
            --L, --R;
            int cnt = palin[R] - (L > 0 ? palin[L - 1] : 0);
            if (cnt > 0) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
