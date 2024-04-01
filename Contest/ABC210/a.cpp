/*https://atcoder.jp/contests/abc210/tasks/abc210_a*/
#include <iostream>

using namespace std;

int main()
{
    long long N, A, X, Y;
    cin >> N >> A >> X >> Y;
    long long ans = (N > A) ? A * X + (N - A) * Y : N * X;
    cout << ans;

    return 0;
}
