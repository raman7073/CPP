#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// wrong sol
vector<int> calculateLISFromLeft(const vector<int> &arr)
{
    vector<int> lis, dp(arr.size());
    for (size_t i = 0; i < arr.size(); ++i)
    {
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
        if (it == lis.end())
        {
            lis.push_back(arr[i]);
        }
        else
        {
            *it = arr[i];
        }
        dp[i] = lis.size();
    }
    return dp;
}

vector<int> calculateLISFromRight(const vector<int> &arr)
{
    vector<int> lis, dp(arr.size());
    for (int i = arr.size() - 1; i >= 0; --i)
    {
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
        if (it == lis.end())
        {
            lis.push_back(arr[i]);
        }
        else
        {
            *it = arr[i];
        }
        dp[i] = lis.size();
    }
    return dp;
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    vector<int> leftLIS = calculateLISFromLeft(A);

    vector<int> rightLIS = calculateLISFromRight(A);

    cout << leftLIS[n] << endl;

    return 0;
}
