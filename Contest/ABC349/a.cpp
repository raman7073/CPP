#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> A(N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        std::cin >> A[i];
    }

    int sum = 0;
    for (int i = 0; i < N - 1; i++)
    {
        sum += A[i];
    }

    int score_N = -sum;
    std::cout << score_N << std::endl;

    return 0;
}