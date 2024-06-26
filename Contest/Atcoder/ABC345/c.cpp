#include <iostream>
#include <string>
#include <unordered_set>

int main()
{
    std::string S;
    std::cin >> S;

    int n = S.length();
    std::unordered_set<std::string> uniqueStrings;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            std::string temp = S;
            std::swap(temp[i], temp[j]);
            uniqueStrings.insert(temp);
        }
    }

    std::cout << uniqueStrings.size() << std::endl;

    return 0;
}
