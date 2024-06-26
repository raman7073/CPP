#include <bits/stdc++.h>

using namespace std;

long long total_payment(long long N)
{
    priority_queue<long long> pq;
    long long payment = 0;
    pq.push(N);

    while (!pq.empty())
    {
        long long x = pq.top();
        pq.pop();
        payment += x;
        if (x % 2 == 0 && (x / 2 >= 2))
        {
            pq.push(x / 2);
            pq.push(x / 2);
        }
        else
        {
            if ((x / 2) >= 2)
                pq.push(x / 2);
            if ((x / 2 + 1) >= 2)
                pq.push(x / 2 + 1);
        }
    }

    return payment;
}

int main()
{
    long long N;
    cin >> N;
    if (N < 2)
    {
        cout << 0;
    }
    else
    {
        cout << total_payment(N);
    }

    return 0;
}
