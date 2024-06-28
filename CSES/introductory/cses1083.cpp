#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    long long sum = 0;
    long long x;
    long long t = n - 1;
    while (t--)
    {
        cin >> x;
        sum += x;
    }
    cout << (n * (n + 1) / 2 - sum) << endl;

    return 0;
}