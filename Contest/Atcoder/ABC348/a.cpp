#include <iostream>
#include <string>

int main()
{
    int N;
    std::cin >> N;

    std::string result;
    for (int i = 1; i <= N; i++)
    {
        if (i % 3 == 0)
        {
            result += 'x';
        }
        else
        {
            result += 'o';
        }
    }

    std::cout << result << std::endl;

    return 0;
}