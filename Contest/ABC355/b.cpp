#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> B(M);

    for (int i = 0; i < N; i++)
    {
        std::cin >> A[i];
    }

    for (int i = 0; i < M; i++)
    {
        std::cin >> B[i];
    }
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    int flag = 0;
    for (int i = 0; i < N - 1; i++)
    {
        auto it = std::lower_bound(B.begin(), B.end(), A[i]) - B.begin();
        if (it != M)
        {
            int ele = B[it];
            if (A[i + 1] < ele)
            {
                flag = 1;
                break;
            }
        }
        else
        {
            if (A[i + 1] > A[i])
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}