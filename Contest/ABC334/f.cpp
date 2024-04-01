#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    int N, K;
    cin >> N >> K;

    int SX, SY;
    cin >> SX >> SY;

    vector<pair<double, pair<int, int>>> distances; // {distance, {X, Y}}

    for (int i = 0; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;
        distances.push_back({distance(SX, SY, X, Y), {X, Y}});
    }

    sort(distances.begin(), distances.end());

    double totalDistance = 0;

    for (int i = 0; i < N; i += K) {
        int j = min(i + K, N) - 1;
        totalDistance += distances[j].first; // Travel to the farthest child in the group

        for (int k = j - 1; k >= i; --k) {
            totalDistance += distance(distances[k + 1].second.first, distances[k + 1].second.second,
                                      distances[k].second.first, distances[k].second.second);
        }
    }

    cout << fixed << totalDistance << endl;

    return 0;
}
