#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, L;
    cin >> N >> M >> L;

    vector<int> a(N), b(M);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < M; ++i) {
        cin >> b[i];
    }

    vector<vector<bool>> isExcluded(N, vector<bool>(M, false));

    for (int i = 0; i < L; ++i) {
        int c, d;
        cin >> c >> d;
        isExcluded[c - 1][d - 1] = true;
    }

    vector<long long> maxPriceA(N, 0);
    vector<long long> maxPriceB(M, 0);

    // Precompute the maximum cost for each main dish
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!isExcluded[i][j]) {
                maxPriceA[i] = max(maxPriceA[i], static_cast<long long>(a[i]) + b[j]);
            }
        }
    }

    // Precompute the maximum cost for each side dish
    for (int j = 0; j < M; ++j) {
        for (int i = 0; i < N; ++i) {
            if (!isExcluded[i][j]) {
                maxPriceB[j] = max(maxPriceB[j], static_cast<long long>(a[i]) + b[j]);
                break;
            }
        }
    }

    long long max_price = 0;

    // Iterate through all set meals
    for (int i = 0; i < N; ++i) {
        // Update the maximum price using precomputed values
        max_price = max(max_price, maxPriceA[i] + maxPriceB[distance(b.begin(), max_element(b.begin(), b.end()))]);
    }

    cout << max_price/2 << endl;

    return 0;
}
