// AC
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> giants(N);
    for (int i = 0; i < N; i++)
    {
        cin >> giants[i].first >> giants[i].second;
    }

    sort(giants.begin(), giants.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.first + b.second > b.first + a.second; });

    long long height = giants[0].first + giants[0].second;
    long long currentShoulderHeight = giants[0].first;

    for (int i = 1; i < N; i++)
    {
        height = max(height, currentShoulderHeight + giants[i].second);
        currentShoulderHeight += giants[i].first;
    }

    cout << height << endl;

    return 0;
}