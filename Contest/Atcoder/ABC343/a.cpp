#include <iostream>

int main()
{
    int A, B;
    std::cin >> A >> B;

    int result = (A + B) % 10;
    if (result == 9)
    {
        result = 8;
    }
    else
    {
        result = 9;
    }

    std::cout << result << std::endl;

    return 0;
}