#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canFormPyramid(vector<int>& A, int mid, int k) {
    int left = mid - 1;
    int right = mid + 1;
    int height = k - 1;

    while (height > 0 && (left >= 0 || right < A.size())) {
        bool canReduceLeft = left >= 0 && A[left] >= height;
        bool canReduceRight = right < A.size() && A[right] >= height;

        if (!canReduceLeft && !canReduceRight) {
            return false;
        }

        if (canReduceLeft) {
            left--;
        }
        if (canReduceRight) {
            right++;
        }

        height--;
    }

    return height == 0;
}

int maxPyramidSize(vector<int>& A) {
    int maxPossibleSize = 0;

    for (int i = 0; i < A.size(); ++i) {
        int size = 1;
        while (size <= A[i] && canFormPyramid(A, i, size)) {
            maxPossibleSize = max(maxPossibleSize, size);
            size++;
        }
    }

    return 2 * maxPossibleSize - 1;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    cout << maxPyramidSize(A) << endl;

    return 0;
}
