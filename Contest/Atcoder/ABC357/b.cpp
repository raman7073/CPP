#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string S;
    std::cin >> S;

    int upperCount = 0, lowerCount = 0;

    for (char c : S)
    {
        if (std::isupper(c))
        {
            upperCount++;
        }
        else if (std::islower(c))
        {
            lowerCount++;
        }
    }

    if (upperCount > lowerCount)
    {

        std::transform(S.begin(), S.end(), S.begin(), ::toupper);
    }
    else
    {

        std::transform(S.begin(), S.end(), S.begin(), ::tolower);
    }

    std::cout << S << std::endl;

    return 0;
}
