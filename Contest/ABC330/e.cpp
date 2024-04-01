#include <iostream>
#include <vector>
#include <set>

using namespace std;
int findMinimumMissingElement(const std::vector<int>& multiset) {
    int maxElement = -1;
    
    // Find the maximum element in the multiset
    for (int element : multiset) {
        maxElement = std::max(maxElement, element);
    }

    // Iterate through the multiset to mark present elements
    std::vector<bool> isPresent(maxElement + 1, false);
    for (int element : multiset) {
        isPresent[element] = true;
    }

    // Find the minimum missing element
    for (int i = 0; i <= maxElement; ++i) {
        if (!isPresent[i]) {
            return i; // Return the minimum missing element
        }
    }

    // If all elements are present, return -1 or any suitable value indicating no missing element
    return -1;
}

int main() {
    // Read input values
    int N, Q;
    cin >> N >> Q;

    // Read the sequence A
    vector<int> A(N);
    multiset<int> values;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        values.insert(A[i]);
    }

    // Initialize the mex variable
    int mex = 0;
    while (values.count(mex)) {
                ++mex;
    }

    // Process each query
    for (int q = 0; q < Q; ++q) {
        int i, x;
        cin >> i >> x;

        // Update A
        --i; // Convert to 0-based index
        values.erase(values.lower_bound(A[i]));
        A[i]=x;
        values.insert(x);                         // O(log N)
        
        if (x <= mex) {
            // Find the new mex if x is the previous mex
            mex = findMinimumMissingElement(values);
        }

        // Print the mex of A
        cout << mex << endl;
    }

    return 0;
}
