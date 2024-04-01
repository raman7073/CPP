#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<long long> A(N), B(N), C(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
        B[i] = A[i];
        if (i != 0)
        {
            C[i] += B[i - 1];
        }
    }
    sort(B.begin(), B.end());
    C[0]=B[0];
    for (int i = 1; i < N; ++i)
    {
        C[i] = C[i - 1]+B[i];
       // cout<<C[i]<<" ";
    }

    for (int i = 0; i < N; i++)
    {
        int idx = upper_bound(B.begin(), B.end(), A[i]) - B.begin();
        //cout<<idx<<" ";
        if (idx != N)
        {
            if (idx > 0)
            {
                cout << (C[N - 1] - C[idx - 1]) << " ";
            }
            else
            {
                cout << C[N - 1] << " ";
            }
        }
        else
        {
            cout << 0 << " ";
        }
    }



    

    return 0;
}
