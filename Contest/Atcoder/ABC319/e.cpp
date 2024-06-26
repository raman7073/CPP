#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
using namespace std;
typedef long long ll;
const ll INF = numeric_limits<ll>::max();

struct BusStop {
    ll p, t;
};

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<BusStop> stops(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        cin >> stops[i].p >> stops[i].t;
    }

    int Q;
    cin >> Q;

    vector<ll> query_results(Q);

    for (int q = 0; q < Q; ++q) {
        ll q_time;
        cin >> q_time;

        // Initialize the time to reach Aoki's house from the last bus stop
        ll time_to_aoki = Y;

        // Traverse the bus stops in reverse order
        for (int i = N - 2; i >= 0; --i) {
            ll next_bus_time = ((q_time - 1) / stops[i].p + 1) * stops[i].p;
            ll time_at_bus_stop = next_bus_time + stops[i].t;

            // Calculate the time to reach Aoki's house from this bus stop
            time_to_aoki = min(time_to_aoki, time_at_bus_stop + query_results[q]);
        }

        // Add the time to reach the first bus stop from Takahashi's house
        time_to_aoki += X;

        // Store the result for this query
        query_results[q] = time_to_aoki;
    }

    // Output the results
    for (int q = 0; q < Q; ++q) {
        cout << query_results[q] << endl;
    }

    return 0;
}
