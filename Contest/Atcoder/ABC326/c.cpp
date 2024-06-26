#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long N, M;
    cin >> N >> M;

    vector<long long> A(N);
    for (long long i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    long long maxGifts = LONG_LONG_MIN;
    for (long long i = 0; i < N; ++i)
    {
        int idx = lower_bound(A.begin(), A.end(), A[i] + M) - A.begin();
        
        maxGifts = max(maxGifts, (long long)(idx - i ));
        
    }

    if(maxGifts == LONG_LONG_MIN) {
        maxGifts = (long long)(0);
    }
    cout << maxGifts << endl;

    return 0;
}
