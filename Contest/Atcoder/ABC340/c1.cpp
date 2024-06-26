#include <iostream>

using namespace std;

long long getLogOf2(long long N)
{
    long long x = 0;
    long long temp = N;
    while (temp > 1)
    {
        temp /= 2;
        ++x;
    }
    return x;
}
bool is_power_of_2(long long N)
{
    return (N > 0) && ((N & (N - 1)) == 0);
}

int main()
{
    long long N;
    cin >> N;

    if (N < 2)
    {
        cout << 0;
    }
    else if (is_power_of_2(N))
    {
        long long x = getLogOf2(N);
        cout << N * x;
    }
    else
    {
        long long x = getLogOf2(N);
        long long n;
        if (N % 2 == 0)
        {
            n = (N / 2) - 2;
        }
        else
        {
            n = N / 2;
        }
        cout << (N * x + (n));
    }

    return 0;
}
