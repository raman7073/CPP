//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    priority_queue<int> mxh;
    priority_queue<int, vector<int>, greater<int>> mnh;

public:
    // Function to insert heap.
    void insertHeap(int &x)
    {
        if (mnh.empty() && mxh.empty())
        {
            mxh.push(x);
            return;
        }

        if (mxh.size() > mnh.size())
        {

            int y = mxh.top();
            if (y > x)
            {
                mxh.pop();
                mxh.push(x);
                mnh.push(y);
            }
            else
            {
                mnh.push(x);
            }
        }
        else
        {

            int y = mnh.top();
            if (y < x)
            {
                mnh.pop();
                mnh.push(x);
                mxh.push(y);
            }
            else
            {
                mxh.push(x);
            }
        }
    }

    // Function to return Median.
    double getMedian()
    {

        if (mxh.size() > mnh.size())
        {

            return (double)mxh.top();
        }
        else
        {

            return (double)(mxh.top() + mnh.top()) / 2;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x;
            ob.insertHeap(x);
            cout << floor(ob.getMedian()) << endl;
        }
    }
    return 0;
}
// } Driver Code Ends