#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> missingColors(K);
    for (int i = 0; i < K; ++i) {
        cin >> missingColors[i];
    }

    sort(missingColors.begin(), missingColors.end());

    int totalWeirdness = 0;

    // Pair each remaining sock with the one closest in color
    for (int i = 1; i <= N - K; ++i) {
        totalWeirdness += min(abs(i - missingColors.front()), abs(i - missingColors.back()));
    }

    cout << totalWeirdness << endl;

    return 0;
}
