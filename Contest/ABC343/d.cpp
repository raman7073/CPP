#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    long long N, T;
    cin >> N >> T;

    vector<long long> scores(N, 0);
    unordered_map<long long, long long> uniqueCounts;
    uniqueCounts[0] = N;
    // cout << uniqueCounts.size() << endl;

    for (long long i = 0; i < T; i++)
    {
        long long A, B;
        cin >> A >> B;

        uniqueCounts[scores[A - 1]]--;
        if (uniqueCounts[scores[A - 1]] == 0)
            uniqueCounts.erase(scores[A - 1]);

        scores[A - 1] += B;
        uniqueCounts[scores[A - 1]]++;

        cout << uniqueCounts.size() << endl;
    }

    return 0;
}