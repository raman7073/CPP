#include <iostream>
using namespace std;

const long long MOD = 998244353;

long long mod_exp(long long base, long long exp, long long mod)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long long mod_inv(long long a, long long mod)
{
    return mod_exp(a, mod - 2, mod);
}

int main()
{
    long long N;
    cin >> N;

    long long lengthN = to_string(N).length();
    long long r = mod_exp(10, lengthN, MOD);

    long long series_sum;
    if (r == 1)
    {

        series_sum = N % MOD;
    }
    else
    {

        long long rN = mod_exp(r, N, MOD);
        series_sum = (rN - 1 + MOD) % MOD * mod_inv(r - 1, MOD) % MOD;
    }

    long long V_N = N % MOD * series_sum % MOD;

    cout << V_N << endl;
    return 0;
}
