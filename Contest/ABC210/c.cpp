/*
https://atcoder.jp/contests/abc210/tasks/abc210_c
use unordered_map for keeping window
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    // Input variables
    int N, k;
    cin >> N >> k;

    // Array to store elements
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    // Hash map to store frequency of elements in the current window
    unordered_map<int, int> freqMap;

    // Initialize distinct element count for current window
    int distinctCount = 0;

    // Traverse the first window and store count of every element in hash map
    for (int i = 0; i < k; i++)
    {
        if (freqMap[arr[i]] == 0)
        {
            distinctCount++;
        }
        freqMap[arr[i]]++;
    }

    // Initialize answer with the distinct count of the first window
    int ans = distinctCount;

    // Traverse through the remaining array
    for (int i = k; i < N; i++)
    {
        // Remove first element of previous window
        freqMap[arr[i - k]]--;

        // If count becomes zero, erase the element from the map
        if (freqMap[arr[i - k]] == 0)
        {
            distinctCount--;
            freqMap.erase(arr[i - k]);
        }

        // Add new element of current window
        // If this element appears first time, increment distinct element count
        if (freqMap[arr[i]] == 0)
        {
            distinctCount++;
        }
        freqMap[arr[i]]++;

        // Update answer with the maximum distinct count
        ans = max(ans, distinctCount);
    }

    // Output the maximum distinct count
    cout << ans;

    return 0;
}
