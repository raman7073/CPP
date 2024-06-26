#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<long long> sleighs(N);
    for (int i = 0; i < N; ++i) {
        cin >> sleighs[i];
    }

    sort(sleighs.begin(), sleighs.end());

    vector<long long> prefixSum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefixSum[i + 1] = prefixSum[i] + sleighs[i];
    }

    for (int q = 0; q < Q; ++q) {
        long long X;
        cin >> X;
        int left = 0, right = N;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (prefixSum[mid] <= X) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        cout << left << endl;
    }

    return 0;
}
