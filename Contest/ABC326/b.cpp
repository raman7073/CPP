#include <iostream>

bool is_326_like(int num)
{
    // Check if the product of hundreds and tens digits equals the ones digit
    return (num / 100) * ((num / 10) % 10) == (num % 10);
}

int find_next_326_like_number(int N)
{
    while (!is_326_like(N))
    {
        N++;
    }
    return N;
}

int main()
{

    int N;
    std::cin >> N;

    int result = find_next_326_like_number(N);
    std::cout << result << std::endl;

    return 0;
}
