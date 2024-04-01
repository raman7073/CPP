#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> C(N);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }

    vector<int> A(M);
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
    }

    vector<vector<int>> L(M, vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> L[i][j];
        }
    }

    int maxReward = 0;

    // Iterate through all possible skill levels
    for (int skill1Level = 1; skill1Level <= 5; ++skill1Level) {
        for (int skill2Level = 1; skill2Level <= 5; ++skill2Level) {
            int totalCost = C[0] * (skill1Level - 1) + C[1] * (skill2Level - 1);
            int totalReward = 0;

            // Check if the current skill levels meet all achievements
            for (int achievement = 0; achievement < M; ++achievement) {
                bool achieved = true;
                for (int skill = 0; skill < N; ++skill) {
                    if (skill == 0 && skill1Level < L[achievement][skill]) {
                        achieved = false;
                        break;
                    }
                    if (skill == 1 && skill2Level < L[achievement][skill]) {
                        achieved = false;
                        break;
                    }
                }
                if (achieved) {
                    totalReward += A[achievement];
                }
            }

            maxReward = max(maxReward, totalReward - totalCost);
        }
    }

    cout << maxReward << endl;

    return 0;
}
