#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    pair<int, int> last = {0, 0};
    vector<pair<int, pair<int, char>>> last1;
    for (int i = 1; i <= q; i++)
    {
        int type, x;
        cin >> type >> x;
        char c;
        x--;
        cin >> c;
        if (type == 1)
        {
            s[x] = c;
            last1.push_back({i, {x, c}});
        }
        else
        {
            last = {type, i};
        }
    }
    int sz = last1.size();
    if (sz && (last1[sz - 1].first > last.second))
    {
        int df = last1[sz - 1].first - last.second;
        if (last.first == 2)
        {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
        }
        else if (last.first == 3)
        {
            transform(s.begin(), s.end(), s.begin(), ::toupper);
        }
        for (int i = sz - df; i < sz; i++)
        {
            s[last1[i].second.first] = last1[i].second.second;
        }
    }
    else
    {

        if (last.first == 2)
        {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
        }
        else if (last.first == 3)
        {
            transform(s.begin(), s.end(), s.begin(), ::toupper);
        }
    }
    cout << s;

    return 0;
}