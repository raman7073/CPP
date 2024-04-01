#include <iostream>

using namespace std;

int ctz(int x) {
    int count = 0;
    while ((x & 1) == 0) {
        x >>= 1;
        ++count;
    }

    return count;
}

int main() {
    int N;
    cin >> N;

    int result = ctz(N);
    
    cout << result << endl;

    return 0;
}
