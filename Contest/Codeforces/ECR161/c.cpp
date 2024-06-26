#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Precompute distances to nearest cities
        vector<long long> nearest_dist(n);
        nearest_dist[0] = abs(a[1] - a[0]);
        nearest_dist[n-1] = abs(a[n-1] - a[n-2]);
        for (int i = 1; i < n-1; ++i) {
            nearest_dist[i] = min(abs(a[i] - a[i-1]), abs(a[i] - a[i+1]));
        }

        int m;
        cin >> m;
        while (m--) {
            int x, y;
            cin >> x >> y;
            --x; --y;

            if (x > y) swap(x, y);

            long long cost = 0;
            if (x == y - 1) {
                // Direct jump if cities are next to each other
                cost = abs(a[y] - a[x]);
            } else {
                // Move to nearest cities and add the cost
                for (int i = x; i < y; ++i) {
                    cost += nearest_dist[i];
                }
            }
            cout << cost << endl;
        }
    }

    return 0;
}
