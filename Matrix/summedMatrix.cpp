
/*
2 <= (i + j) <= 2 * n;
which number occur how many times in a matrix?

n = 1

 2

n = 2

    2 3
    3 4
n = 3

    2 3 4
    3 4 5
    4 5 6

n = 4
    2 3 4 5
    3 4 5 6
    4 5 6 7
    5 6 7 8

*/
//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long sumMatrix(long long n, long long q)
    {
        // code here
        if (q >= 2 && q <= 2 * n)
        {
            long long x = n + 1;
            long long ans = n - abs(q - x);
            return ans;
        }
        else
            return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, q;

        cin >> n >> q;

        Solution ob;
        cout << ob.sumMatrix(n, q) << endl;
    }
    return 0;
}
// } Driver Code Ends