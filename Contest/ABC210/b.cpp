/*https://atcoder.jp/contests/abc210/tasks/abc210_b*/
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    string S;
    cin >> N >> S;
    int idx = S.find_first_of('1') + 1;
    if (idx % 2 == 1)
    {
        cout << "Takahashi";
    }
    else
    {
        cout << "Aoki";
    }

    return 0;
}