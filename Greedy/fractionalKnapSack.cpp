//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
public:
    static bool comp(Item A, Item B)
    {
        return A.value * B.weight > B.value * A.weight;
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr + n, comp);
        double v = 0.0;
        int idx = 0;
        while (idx < n && W > 0)
        {
            int currentWeight = arr[idx].weight;

            if (currentWeight <= W)
            {
                W -= currentWeight;
                v += arr[idx].value;
            }
            else if (currentWeight > W && W != 0)
            {
                v += (double)W / currentWeight * arr[idx].value;
                break;
            }
            idx++;
        }
        // cout<<"rem "<<W<<" ";

        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--)
    {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends