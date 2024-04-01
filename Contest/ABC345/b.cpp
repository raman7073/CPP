#include <iostream>
#include <cmath>

int main()
{
    long long X;
    std::cin >> X;

    long long result;
    if (X >= 0)
    {
        result = (X + 9) / 10;
    }
    else
    {
        result = (X) / 10;
    }

    std::cout << result << std::endl;

    return 0;
}
