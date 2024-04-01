//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        buildHeap(arr, n);
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(arr[0]);
            swap(arr[0], arr[n - 1 - i]);
            heapify(arr, n - 1 - i, 0);
        }
        return ans;
    }
    void buildHeap(int arr[], int n)
    {
        // Your Code Here
        for (int i = (n - 2) / 2; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    }
    void heapify(int arr[], int n, int i)
    {
        // Your Code Here
        int largest = i, left = 2 * i + 1, right = 2 * i + 2;
        if (left < n && arr[left] > arr[largest])
        {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest])
        {
            largest = right;
        }
        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> result = ob.kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends