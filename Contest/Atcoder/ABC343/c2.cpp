#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isPalindrome(unsigned long long num)
{
    unsigned long long reversed = 0;
    unsigned long long original = num;

    while (num > 0)
    {
        unsigned long long digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }

    return original == reversed;
}

long long maxPalindromeCube(long long N)
{
    for (long long x = cbrt(N); x >= 1; --x)
    {
        long long cube = x * x * x;
        if (cube <= N && isPalindrome(cube))
        {
            return cube;
        }
    }
    return 0; // Not found
}

int main()
{
    long long N;
    cin >> N;

    long long result = maxPalindromeCube(N);
    cout << result << endl;

    return 0;
}
