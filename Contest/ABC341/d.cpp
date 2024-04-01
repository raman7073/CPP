#include <iostream>
using namespace std;
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
long long lcm(long long a, long long b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    long long N, M, K;
    cin >> N >> M >> K;
    long long L = lcm(N, M);
    long long lo = 0, hi = 2e+18, ans;
    while (lo + 1 < hi)
    {
        long long mid = (hi + lo) / 2;
        if (((mid / N) + (mid / M) - 2 * (mid / L)) < K)
        {
            lo = mid;
        }
        else
        {
            ans = mid;
            hi = mid;
        }
    }
    cout << ans;
    return 0;
}
