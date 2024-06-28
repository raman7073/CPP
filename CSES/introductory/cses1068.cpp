#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    std::cin >> n;

    while (n > 1)
    {
        std::cout << n << " ";
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = 3 * n + 1;
        }
    }
    if (n == 1)
        std::cout << n;

    return 0;
}