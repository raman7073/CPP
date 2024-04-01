#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read input
    int N, D;
    cin >> N >> D;

    vector<int> A(N);

    // Read the array A
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the array A
    sort(A.begin(), A.end());

    // Initialize variables
    vector<int> dp(N, 1);

    // Dynamic Programming with binary search
    for (int i = 1; i < N; ++i) {
        int lowerBound = lower_bound(A.begin(), A.begin() + i, A[i] - D) - A.begin();
        if (lowerBound > 0) {
            dp[i] = max(dp[i], dp[lowerBound - 1] + 1);
        }
        dp[i] = max(dp[i], dp[i - 1]);
    }

    // Find the maximum length
    int maxLength = *max_element(dp.begin(), dp.end());

    // Print the answer
    cout << maxLength << endl;

    return 0;
}
