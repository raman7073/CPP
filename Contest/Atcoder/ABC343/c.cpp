#include <iostream>
#include <cmath>
#include <string>
#include <algorithm> // Add the missing header file

using namespace std;

bool isPalindrome(string s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    unsigned long long N;
    cin >> N;

    unsigned long long maxPalindromeCube = 0;
    for (unsigned long long x = 1; x <= (unsigned long long)cbrt(N); x++)
    {
        unsigned long long cube = x * x * x;
        string cubeStr = to_string(cube);
        if (isPalindrome(cubeStr) && cube <= N)
        {
            maxPalindromeCube = std::max(maxPalindromeCube, cube);
        }
    }

    cout << maxPalindromeCube << endl;

    return 0;
}