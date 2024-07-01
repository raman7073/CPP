#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> W(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
        A[i]--;
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> W[i];
    }

    unordered_map<int, vector<int>> boxItems;

    for (int i = 0; i < N; ++i)
    {
        boxItems[A[i]].push_back(W[i]);
    }

    long long totalCost = 0;

    for (auto &entry : boxItems)
    {
        vector<int> &weights = entry.second;
        if (weights.size() > 1)
        {
            sort(weights.begin(), weights.end());
            for (int i = 0; i < weights.size() - 1; ++i)
            {
                totalCost += weights[i];
            }
        }
    }

    cout << totalCost << endl;
    return 0;
}
