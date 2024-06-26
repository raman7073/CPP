#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    int N, M, L, Q;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cin >> M;
    vector<int> B(M);
    for (int i = 0; i < M; i++)
    {
        cin >> B[i];
    }
    cin >> L;
    vector<int> C(L);
    for (int i = 0; i < L; i++)
    {
        cin >> C[i];
    }
    cin >> Q;
    vector<int> X(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> X[i];
    }

    unordered_set<int> sumSet;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < L; k++)
            {
                sumSet.insert(A[i] + B[j] + C[k]);
            }
        }
    }

    for (int i = 0; i < Q; i++)
    {
        if (sumSet.count(X[i]) > 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}