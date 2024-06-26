#include <iostream>
#include <vector>

using namespace std;

vector<pair<long long, long long>> f(long long l, long long r, long long L, long long R)
{
    if (L <= l && r <= R)
    {
        cout << "1 --> ";
        cout << l << " " << r << " " << L << " " << R << endl;
        return {{l, r}};
    }
    long long m = (l + r) / 2;
    if (R <= m)
    {
        cout << "2 --> ";
        cout << l << " " << m << " " << L << " " << R << endl;
        return f(l, m, L, R);
    }
    if (m <= L)
    {
        cout << "3 --> ";
        cout << m << " " << r << " " << L << " " << R << endl;
        return f(m, r, L, R);
    }
    cout << "4 --> ";
    cout << l << " " << m << " " << L << " " << R << endl;
    auto left_part = f(l, m, L, R);
    for (auto p : left_part)
    {
        cout << p.first << " " << p.second << endl;
    }
    cout << "5 --> ";
    cout << m << " " << r << " " << L << " " << R << endl;
    auto right_part = f(m, r, L, R);
    for (auto p : right_part)
    {
        cout << p.first << " " << p.second << endl;
    }
    cout << "6 --> ";
    left_part.insert(left_part.end(), right_part.begin(), right_part.end());
    for (auto p : left_part)
    {
        cout << p.first << " " << p.second << endl;
    }
    cout << "----------------------------------------------------->\n";
    return left_part;
}

int main()
{
    long long L, R;
    cin >> L >> R;

    auto ans = f(0, 1LL << 60, L, R);
    cout << ans.size() << endl;
    for (const auto &p : ans)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
