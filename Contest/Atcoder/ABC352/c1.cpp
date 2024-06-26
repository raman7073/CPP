#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<long long, long long>> giants(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> giants[i].first >> giants[i].second;
    }

    sort(giants.begin(), giants.end(), [](const auto &a, const auto &b)
         { return a.first < b.se; });
    for (auto &giant : giants)
    {
        cout << giant.first << " " << giant.second << endl;
    }
    long long height = 0, maxHeight = 0;
    for (int i = 0; i < N; ++i)
    {
        height += giants[i].first;
        maxHeight = max(maxHeight, height + giants[i].second);
    }

    cout << maxHeight << endl;

    return 0;
}
