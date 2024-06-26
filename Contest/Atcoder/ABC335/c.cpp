#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<pair<int, int>> query;
    for (int i = 0; i < Q; i++)
    {
        int queryType;
        cin >> queryType;
        int t = query.size();

        if (queryType == 1)
        {
            char direction;
            cin >> direction;

            if (direction == 'R')
            {
                if (t != 0)
                {
                    pair<int, int> p = query[t - 1];
                    query.push_back({p.first + 1, p.second});
                    continue;
                }
                query.push_back({1, 0});
            }
            else if (direction == 'L')
            {
                if (t != 0)
                {
                    pair<int, int> p = query[t - 1];
                    query.push_back({p.first - 1, p.second});
                    continue;
                }
                query.push_back({-1, 0});
            }
            else if (direction == 'U')
            {
                if (t != 0)
                {
                    pair<int, int> p = query[t - 1];
                    query.push_back({p.first, p.second + 1});
                    continue;
                }
                query.push_back({0, 1});
            }
            else if (direction == 'D')
            {
                if (t != 0)
                {
                    pair<int, int> p = query[t - 1];
                    query.push_back({p.first, p.second - 1});
                    continue;
                }
                query.push_back({0, -1});
            }
        }
        else if (queryType == 2)
        {
            int p;
            cin >> p;
            if (p > t)
            {
                cout << (p - t) << " " << 0 << endl;
            }
            else
            {
                pair<int, int> pi = query[t - p];
                cout << pi.first + 1 << " " << pi.second << endl;
            }
        }
    }

        return 0;
    }