#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers;
    int num;

    // Read the input until 0 is encountered
    while (std::cin >> num && num != 0)
    {
        numbers.push_back(num);
    }
    std::cout << 0 << std::endl;
    for (int i = numbers.size() - 1; i >= 0; i--)
    {
        std::cout << numbers[i] << std::endl;
    }

    return 0;
}