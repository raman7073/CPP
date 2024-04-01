/* Given an array of n distinct elements.
Find the minimum number of swaps required to sort the array in strictly increasing order.
*/
/*
 Yes, your code can be further optimized.
 Instead of creating a separate vector to store the pairs of elements
 with their indices, you can use a map or unordered_map to store the
 indices of elements in the original array. This way, you can directly
  access the index of an element in O(1) time.

Additionally, you can use a visited array to keep track of the elements
 that have been visited or swapped. This will help you avoid unnecessary
  swaps and reduce the number of iterations.

Overall, these optimizations will improve the time complexity of your code.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums)
    {
        // Code here
        int cnt = 0;
        vector<pair<int, int>> copy;
        for (int i = 0; i < nums.size(); i++)
        {
            copy.push_back(make_pair(nums[i], i));
        }
        sort(copy.begin(), copy.end());
        int i = 0;
        while (i <= nums.size() - 1)
        {
            if (i == copy[i].second)
            {
                i++;
                continue;
            }
            else
            {
                swap(copy[copy[i].second], copy[i]);
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.minSwaps(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends