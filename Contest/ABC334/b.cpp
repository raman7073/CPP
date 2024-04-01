#include <iostream>
#include<cmath>

using namespace std;

int main() {
    long long A, M, L, R;
    cin >> A >> M >> L >> R;

    // Convert coordinates to be relative to A
    L = L - A;
    R = R - A;
    A = 0LL;

    // Calculate the number of Christmas trees between Takahashi and Aoki
    long long trees_between = floor(R / M) - floor((L - 1) / M);

    cout << trees_between << endl;

    return 0;
}
