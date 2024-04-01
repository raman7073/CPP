//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the maximum number of activities that can
    // be performed by a single person.
    static bool comp(pair<int, int> p1, pair<int, int> p2)
    {
        if (p1.second == p2.second)
        {
            return p1.first < p2.first;
        }
        return p1.second < p2.second;
    }
    int activitySelection(vector<int> &start, vector<int> &end, int n)
    {
        // Your code here
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++)
        {
            vp.push_back({start[i], end[i]});
        }
        sort(vp.begin(), vp.end(), comp);
        // for(auto p:vp){
        //     cout<<p.first<< " "<<p.second<<endl;
        // }
        int count = 1; // Always select the first activity
        int lastStart = vp[0].first;
        int lastEnd = vp[0].second;

        for (int i = 1; i < n; ++i)
        {
            // If this activity has a start time greater than or equal to the last selected end time
            if (vp[i].second > lastStart && vp[i].first > lastEnd)
            {
                lastStart = vp[i].first;
                lastEnd = vp[i].second;
                ++count;
                // cout<<vp[i].first<<" "<<vp[i].second<<endl;
            }
        }

        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;

    // testcases
    cin >> t;
    while (t--)
    {
        // size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);

        // adding elements to arrays start and end
        for (int i = 0; i < n; i++)
            cin >> start[i];
        for (int i = 0; i < n; i++)
            cin >> end[i];
        Solution ob;
        // function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends