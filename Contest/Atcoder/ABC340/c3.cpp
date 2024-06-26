#include <iostream>
#include <cmath>

using namespace std;

long long totalMoneyPaid(long long N)
{
    long long total = 0;
    while (N >= 2)
    {
        long long x = N;
        total += x;
        N = floor(x / 2) + ceil(x / 2);
    }
    return total;
}

int main()
{
    long long N;
    cin >> N;

    long long result = totalMoneyPaid(N);
    cout << result << endl;

    return 0;
}
