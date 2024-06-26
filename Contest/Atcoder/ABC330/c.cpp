#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    long long D;
    cin >> D;
    long long answer = D;

    for (long long y = 0; y * y <= D; ++y) {
        long long x = sqrt(D - y * y);
        answer = min(answer, abs(x * x + y * y - D));
        if (x + 1 <= D) {
            answer = min(answer, abs((x + 1) * (x + 1) + y * y - D));
        }
    }
    cout << answer << endl;

    return 0;
}
