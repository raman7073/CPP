/*
https://atcoder.jp/contests/abc209/tasks/abc209_c

if C is sorted in the increasing order, we can see that the number of possibilities for
A is the product of
(Ci−i+1).
 Ex:
  3 4
  we can use 3 numbers from c1 and 3 numbers from c2 so answer = 3*3 = 9
  as they are in increasing order the  previous number is always there in further number.

  1 ->2,3,4
  2 ->1,3,4
  3 ->1,2,4
  total is 9
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    sort(c.begin(), c.end());
    long long ans = 1;
    for (int i = 0; i < n; i++)
        ans = ans * max(0, c[i] - i) % 1000000007;
    cout << ans << endl;
}
