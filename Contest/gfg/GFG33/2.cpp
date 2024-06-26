#include <bits/stdc++.h>
using namespace std;
// identify identical subarrays, and check for min operations
// considering removing all elements from left or right
int arrayOptimization(int n, vector<int> &arr)
{
    // code here
    unordered_map<int, int> map;
    int l = 0, r = 0;
    int res = INT_MAX;

    while (r < n)
    {
        map[arr[r]]++;

        while (map[arr[r]] > 1)
        {
            map[arr[l]]--;
            l++;
        }

        res = min(res, l * 2 + (n - 1 - r));
        res = min(res, l + (n - 1 - r) * 2);
        r++;
    }

    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << arrayOptimization(n, arr) << endl;
    return 0;
}