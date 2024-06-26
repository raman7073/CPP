#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    vector<int> consecutiveOnes(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        consecutiveOnes[i] = consecutiveOnes[i - 1] + (S[i - 1] == '1');
    }

    while (Q--) {
        int c, L, R;
        cin >> c >> L >> R;

        if (c == 1) {
            for (int i = L; i <= R; ++i) {
                if (S[i - 1] == '1') {
                    consecutiveOnes[i]--;
                } else {
                    consecutiveOnes[i]++;
                }
                S[i - 1] = '0' + ('1' - S[i - 1]); // flip 0 to 1 and vice versa
            }
        } else {
            int result = consecutiveOnes[R] - consecutiveOnes[L - 1];
            cout << result << endl;
        }
    }

    return 0;
}
