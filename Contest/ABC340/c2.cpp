#include <iostream>

using namespace std;

long long total_payment(long long N)
{
    long long payment = 0;
    long long x = N;

    while (x >= 2)
    {
        long long count = N / x;
        payment += x * count;
        x = x / 2 + x % 2;
    }

    return payment;
}

int main()
{
    long long N;
    cin >> N;

    cout << total_payment(N) << endl;

    return 0;
}
