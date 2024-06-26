#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, L, R;
    std::cin >> N >> L >> R;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        A[i] = i + 1;
    }

    std::reverse(A.begin() + L - 1, A.begin() + R);

    for (int i = 0; i < N; i++)
    {
        std::cout << A[i] << " ";
    }

    return 0;
}