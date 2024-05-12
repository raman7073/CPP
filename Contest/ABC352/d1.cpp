#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> P(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> P[i];
    }

    sort(P.begin(), P.end());

    int min_diff = INT_MAX;
    for (int i = 0; i <= N - K; ++i)
    {
        min_diff = min(min_diff, P[i + K - 1] - P[i]);
    }

    cout << min_diff << endl;

    return 0;
}
