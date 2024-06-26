#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> heights(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> heights[i];
    }

    int leftmostTallerBuilding = -1;
    for (int i = 1; i < N; i++)
    {
        if (heights[i] > heights[0])
        {
            leftmostTallerBuilding = i + 1;
            break;
        }
    }

    std::cout << leftmostTallerBuilding << std::endl;

    return 0;
}