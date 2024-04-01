#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // Read input values
    int N;
    long long K;
    cin >> N >> K;

    vector<long long> X(N), Y(N);

    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
    }

    // Initialize the answer with a large value
    long long answer = LLONG_MAX;

    // Iterate through all possible pairs of x-coordinates and y-coordinates
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // Calculate the current x and y bounds
            long long xmin = min(X[i], X[j]);
            long long xmax = max(X[i], X[j]);
            long long ymin = min(Y[i], Y[j]);
            long long ymax = max(Y[i], Y[j]);

            // Count the number of points within or on the bounds
            long long count = 0;
            for (int k = 0; k < N; ++k) {
                if (xmin <= X[k] && X[k] <= xmax && ymin <= Y[k] && Y[k] <= ymax) {
                    ++count;
                }
            }

            // Check if the current bounds satisfy the conditions
            if (count >= N - K) {
                // Update the answer with the minimum possible side length
                answer = min(answer, max(xmax - xmin, ymax - ymin));
            }
        }
    }

    // Print the result
    cout << answer << endl;

    return 0;
}
