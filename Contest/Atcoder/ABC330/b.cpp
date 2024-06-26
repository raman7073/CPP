#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int N, L, R;
    cin >> N >> L >> R;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
    
        int Xi = max(L, min(R, A[i]));
        cout << Xi << " ";
    }

    return 0;
}
