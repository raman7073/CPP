#include <iostream>

int calculateT(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return 4 * calculateT(n - 1) - 4 * calculateT(n - 2);
    }
}

int main()
{
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    int result = calculateT(n);
    std::cout << "T(" << n << ") = " << result << std::endl;

    return 0;
}