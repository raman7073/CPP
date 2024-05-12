#include <iostream>
#include <vector>

int main()
{
    int N, K;
    std::cin >> N >> K;

    std::vector<int> groups(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> groups[i];
    }

    int attractionCount = 0;

    int i = 0;
    while (i < N)
    {
        int j = i;
        int sum = groups[j];
        while (j < N && sum <= K)
        {
            j++;
            sum += groups[j];
        }
        i = j;
        attractionCount++;
    }

    std::cout << attractionCount << std::endl;

    return 0;
}