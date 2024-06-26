#include <iostream>

int main()
{
    int A, B;
    std::cin >> A >> B;

    if (A != B)
    {
        std::cout << 6 - A - B << std::endl;
    }
    else
    {
        std::cout << -1 << std::endl;
    }

    return 0;
}