#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MOD = 1e9 + 7;

int countPairs(int n, int k, vector<int> &arr)
{
    unordered_map<int, unordered_map<int, int>> valueModCount;
    long long count = 0;

    for (int i = 1; i <= n; ++i)
    {
        int val = arr[i - 1];
        int modIndex = i % k;

        if (valueModCount.find(val) != valueModCount.end())
        {
            for (const auto &entry : valueModCount[val])
            {
                int modIdx = entry.first;
                int occurrence = entry.second;
                if ((modIndex + modIdx) % k == 0)
                {
                    count = (count + occurrence) % MOD;
                }
            }
        }

                valueModCount[val][modIndex]++;
    }

    return count;
}

int main()
{
    int n = 6;
    int k = 4;
    vector<int> arr = {1, 1, 1, 1, 1, 1};

    cout << countPairs(n, k, arr) << endl; // Example usage

    return 0;
}
