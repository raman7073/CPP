#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> A(M), B(M), C(M);
    for (int i = 0; i < M; i++)
    {
        cin >> A[i] >> B[i] >> C[i];
    }

    vector<int> rank(N, -1);
    for (int i = 0; i < N; i++)
    {
        rank[i] = i + 1;
    }

    for (int i = 0; i < M; i++)
    {
        int diff = rank[A[i] - 1] - rank[B[i] - 1];
        if (diff != C[i])
        {
            rank[i] = -1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << rank[i] << " ";
    }

    return 0;
}