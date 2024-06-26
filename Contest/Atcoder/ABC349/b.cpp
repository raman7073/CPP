#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

bool isGoodString(const std::string &s)
{
    std::unordered_map<char, int> count;
    for (char c : s)
    {
        count[c]++;
    }
    std::vector<int> v(101);
    for (auto &kv : count)
    {
        v[kv.second]++;
    }
    // for (int i = 0; i < 101; i++)
    // {
    //     std::cout << v[i] << " ";
    // }
    for (int i = 1; i < 101; i++)
    {
        if (v[i] != 0 && v[i] != 2)
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

    if (isGoodString(s))
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}