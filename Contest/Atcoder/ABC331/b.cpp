#include <iostream>
#include <climits>

using namespace std;

int main() {
    int N, S, M, L;
    cin >> N >> S >> M >> L;

    int minCost = INT_MAX;

    
    for (int packs6 = 0; packs6 <= N; ++packs6) {
        for (int packs8 = 0; packs8 <= N; ++packs8) {
            for (int packs12 = 0; packs12 <= N; ++packs12) {
                int totalEggs = packs6 * 6 + packs8 * 8 + packs12 * 12;

                
                if (totalEggs >= N) {
                    int cost = packs6 * S + packs8 * M + packs12 * L;
                    minCost = min(minCost, cost);
                    break;
                }
            }
        }
    }

    cout << minCost << endl;

    return 0;
}
