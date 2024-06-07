#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> tests(M, vector<int>(N));
    vector<char> results(M);

    for (int i = 0; i < M; i++)
    {
        int C;
        cin >> C;
        for (int j = 0; j < C; j++)
        {
            cin >> tests[i][j];
        }
        cin >> results[i];
    }

    int count = 0;
    for (int i = 0; i < (1 << N); i++)
    {
        int realKeys = 0;
        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                realKeys++;
            }
        }

        if (realKeys < K)
        {
            continue;
        }

        bool valid = true;
        for (int j = 0; j < M; j++)
        {
            int insertedKeys = 0;
            for (int k = 0; k < N; k++)
            {
                if (i & (1 << (tests[j][k] - 1)))
                {
                    insertedKeys++;
                }
            }

            if (results[j] == 'o' && insertedKeys < K)
            {
                valid = false;
                break;
            }

            if (results[j] == 'x' && insertedKeys >= K)
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}