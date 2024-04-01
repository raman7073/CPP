/* https://atcoder.jp/contests/abc209/tasks/abc209_b
   You have X yen. Can you buy the whole product with that amount?
*/
#include <iostream>
using namespace std;

int main()
{
    long long n, x, ai;
    cin >> n >> x;

    long long sum = 0;
    for (long long i = 1; i <= n; i++)
    {
        cin >> ai;
        if (i % 2 == 0)
            ai--;
        sum += ai;
    }

    if (x >= sum)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
