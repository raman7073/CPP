#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Ant
{
    int p;
    char d;
};

int main()
{
    int N;
    long long T;
    cin >> N >> T;
    string S;
    cin >> S;
    vector<int> X(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> X[i];
    }

    vector<Ant> ants(N);
    for (int i = 0; i < N; ++i)
    {
        ants[i] = {X[i], S[i]};
    }

    sort(ants.begin(), ants.end(), [](const Ant &a, const Ant &b)
         { return a.p < b.p; });

    long long count = 0;
    vector<int> rp;

    for (int i = 0; i < N; ++i)
    {
        if (ants[i].d == '1')
        {
            rp.push_back(ants[i].p);
        }
        else
        {
            auto it = lower_bound(rp.begin(), rp.end(), ants[i].p - 2 * T);
            cout << ants[i].p - 2 * T << " " << (rp.end() - it) << endl;
            count += rp.end() - it;
        }
    }

    cout << count << endl;
    return 0;
}
