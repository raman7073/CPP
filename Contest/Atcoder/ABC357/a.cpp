#include <iostream>
#include <vector>

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::vector<int> H(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> H[i];
    }

    int count = 0;
    for (int i = 0; i < N; ++i)
    {
        if (M >= H[i])
        {
            M -= H[i];
            count++;
        }
        else
        {
            break;
        }
    }

    std::cout << count << std::endl;
    return 0;
}
