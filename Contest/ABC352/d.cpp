#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, K;
    std::cin >> N >> K;

    std::vector<int> P(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> P[i];
    }

    std::vector<int> sortedP(P);
    std::sort(sortedP.begin(), sortedP.end());

    int minDiff = N;
    for (int i = 0; i <= N - K; i++)
    {
        int diff = sortedP[i + K - 1] - sortedP[i];
        minDiff = std::min(minDiff, diff);
    }

    std::cout << minDiff << std::endl;

    return 0;
}