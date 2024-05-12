#include <iostream>

int main()
{
    int N, X, Y, Z;
    std::cin >> N >> X >> Y >> Z;

    if ((Z <= Y && X <= Z) || (Z <= X && Y <= Z))
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}