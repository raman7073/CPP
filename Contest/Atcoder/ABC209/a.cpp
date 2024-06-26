/*
 https://atcoder.jp/contests/abc209/tasks/abc209_a
 Concept: Number of integers greater than or equal to A and less than or equal to B is
    n = (B-A+1)
 */
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (b < a)
        cout << 0 << endl;
    else
        cout << (b - a + 1) << endl;
    return 0;
}