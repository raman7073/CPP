#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    // If N == 3, handle it as a special case
    if (N == 3) {
        cout << "2\n";
        cout << "2 1 2\n";
        cout << "1 3\n";
        cout.flush();

        string response;
        cin >> response;

        if (response == "10") {
            cout << "1\n";
        } else if (response == "01") {
            cout << "3\n";
        } else {
            cout << "2\n";
        }
    } else {
        // For N > 3, use the binary approach
        int M = ceil(log2(N));
        cout << M << endl;

        for (int i = 0; i < M; ++i) {
            cout << N - (N >> (i + 1) << (i + 1));
            for (int j = 1; j <= N; ++j) {
                if ((j >> i) & 1) {
                    cout << " " << j;
                }
            }
            cout << endl;
        }
        cout.flush();

        string S;
        cin >> S;

        int bad_bottle = 0;
        for (int i = 0; i < M; ++i) {
            if (S[i] == '1') {
                bad_bottle |= (1 << i);
            }
        }

        cout << bad_bottle << endl;
    }

    return 0;
}
