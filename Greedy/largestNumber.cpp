//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return Largest Number

class Solution
{
public:
    // Function to return the largest possible number of n digits
    // with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        // Your code here
        string ans = "";
        int len = 0;
        while (len < n)
        {
            if (sum >= 9)
            {
                ans += to_string(9);
                sum = sum - 9;
                len++;
            }
            else if (sum > 0 && sum < 9)
            {
                ans += to_string(sum);
                sum = 0;
                len++;
            }
            else
            {
                ans += to_string(0);
                len++;
            }
        }
        // cout<<sum<<endl;
        if (sum != 0)
            return "-1";
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    // taking testcases
    int t;
    cin >> t;

    while (t--)
    {
        // taking n and sum
        int n, sum;
        cin >> n >> sum;

        Solution obj;
        // function call
        cout << obj.largestNumber(n, sum) << endl;
    }
    return 0;
}
// } Driver Code Ends