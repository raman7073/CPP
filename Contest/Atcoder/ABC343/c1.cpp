// Accepted Solution
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<unsigned long long> palindromicCubes = {1, 8, 343, 1331, 1030301, 1367631, 1003003001, 10662526601, 1000300030001, 1030607060301, 1334996994331, 1000030000300001, 1033394994933301, 1331399339931331};

unsigned long long maxPalindromeCube(unsigned long long N)
{
    auto it = upper_bound(palindromicCubes.begin(), palindromicCubes.end(), N);
    if (it == palindromicCubes.begin())
        return 0;
    return *(--it);
}

int main()
{
    unsigned long long N;
    cin >> N;

    unsigned long long result = maxPalindromeCube(N);
    cout << result << endl;

    return 0;
}
