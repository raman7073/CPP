#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int takahashiScore = 0, aokiScore = 0;

    for (int i = 0; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;

        takahashiScore += X;
        aokiScore += Y;
    }

    if (takahashiScore > aokiScore) {
        cout << "Takahashi" << endl;
    } else if (takahashiScore < aokiScore) {
        cout << "Aoki" << endl;
    } else {
        cout << "Draw" << endl;
    }

    return 0;
}
