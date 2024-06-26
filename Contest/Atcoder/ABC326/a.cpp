#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y;
    cin >> x >> y;
    int ans = y - x;
    if (ans > 2)
    {
        cout << "No";
    }
    else if (ans < -3)
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }

    return 0;
}