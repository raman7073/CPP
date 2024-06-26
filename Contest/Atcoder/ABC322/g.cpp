#include <iostream>

using namespace std;

const int MOD = 998244353;

int main() {
    int N, X;
    cin >> N >> X;

    long long result = 0;

    // Iterate over all possible values of S_i
    for (int Si = 0; Si <= min(9, X); ++Si) {
        // Iterate over all possible values of a, b
        for (int a = 1; a <= N; ++a) {
            for (int b = 1; b <= N; ++b) {
                if (a != b) {
                    // Calculate a^{k-i} - b^{k-i}
                    long long term = 1;
                    for (int i = 1; i <= N; ++i) {
                        term = (term * (i == Si ? a - b : 1)) % MOD;
                    }

                    // Check if S_i * (a^{k-i} - b^{k-i}) equals X
                    if (term == X) {
                        // Count the valid triples
                        result = (result + 1) % MOD;
                    }
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}
