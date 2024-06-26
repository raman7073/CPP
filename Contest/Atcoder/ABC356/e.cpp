#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    long long ans = 0;
    sort(A.begin(), A.end());
    vector<long long> postFixSum(N + 1, 0);
    for (int i = N - 1; i >= 0; --i)
    {
        postFixSum[i] = postFixSum[i + 1] + A[i];
    }
    // for (int x : postFixSum)
    // {
    //     cout << x << " ";
    // }
    for (int i = 0; i < N - 1; i++)
    {
        ans += postFixSum[i + 1] / A[i];
    }

    cout << ans;

    return 0;
}
