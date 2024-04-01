#include <iostream>
#include <string>

bool isBidirectionalArrowString(const std::string &s)
{
    if (s.length() < 3)
    {
        return false;
    }
    if (s[0] != '<' || s[s.length() - 1] != '>')
    {
        return false;
    }
    for (int i = 1; i < s.length() - 1; i++)
    {
        if (s[i] != '=')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string s;
    std::cin >> s;

    if (isBidirectionalArrowString(s))
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}