#include <iostream>
#include <vector>

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::vector<int> goal(M);
    for (int i = 0; i < M; i++)
    {
        std::cin >> goal[i];
    }

    std::vector<std::vector<int>> nutrients(N, std::vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cin >> nutrients[i][j];
        }
    }

    bool metGoal = true;
    for (int i = 0; i < M; i++)
    {
        int total = 0;
        for (int j = 0; j < N; j++)
        {
            total += nutrients[j][i];
        }
        if (total < goal[i])
        {
            metGoal = false;
            break;
        }
    }

    if (metGoal)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}