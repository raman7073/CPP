#include <bits/stdc++.h>
using namespace std;

int calculateLIS(const vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    ans.push_back(nums[0]);

    for (int i = 1; i < n; i++)
    {
        if (nums[i] > ans.back())
        {
            ans.push_back(nums[i]);
        }
        else
        {

            int low = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[low] = nums[i];
        }
    }

    return ans.size();
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
    if (A[0] != 1)
        A[0] = 1;
    else
        A[1] = 2;
    int currentLIS = calculateLIS(A);
    int maxLIS = currentLIS;

    cout << maxLIS << endl;

    return 0;
}
