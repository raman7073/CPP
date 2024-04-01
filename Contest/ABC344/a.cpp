#include <iostream>
#include <string>

std::string removeBetweenBars(const std::string &s)
{
    size_t firstBar = s.find('|');
    size_t secondBar = s.find('|', firstBar + 1);
    return s.substr(0, firstBar) + s.substr(secondBar + 1);
}

int main()
{
    std::string s;
    std::cin >> s;
    std::cout << removeBetweenBars(s) << std::endl;
    return 0;
}