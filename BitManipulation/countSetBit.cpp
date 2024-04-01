//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int countSetBitsUtil(int x)
    {
        int count = 0;
        while (x)
        {
            count += x & 1;
            x >>= 1;
        }
        return count;
    }
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    /*
      1.Find the largest power of 2 less than or equal to N. Let's call this x.
        The number of set bits in the range [0, x]
        can be found by the formula x * 2^(x-1).

      2.Then, add the set bits in the range [x+1, N].

      3.Repeat the process for the remaining numbers (N - x).
    */
    int countSetBits(int n)
    {
        // Your logic here
        if (n == 0)
            return 0;

        int x = 0;
        while ((1 << (x + 1)) <= n)
        {
            x++;
        }

        int bitsUpTo2PowX = x * (1 << (x - 1));
        int msb2PowXToN = n - (1 << x) + 1;
        int rest = n - (1 << x);

        return bitsUpTo2PowX + msb2PowXToN + countSetBits(rest);
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {
        int n;
        cin >> n; // input n
        Solution ob;
        cout << ob.countSetBits(n) << endl; // print the answer
    }
    return 0;
}

// } Driver Code Ends