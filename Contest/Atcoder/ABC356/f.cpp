#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_set<long long> S;
unordered_map<long long, int> componentSize;

int findComponentSize(long long x)
{
    if (componentSize.find(x) == componentSize.end())
    {
        return 0;
    }
    return componentSize[x];
}

void addElement(long long x, long long K)
{
    S.insert(x);
    for (auto it = S.begin(); it != S.end(); ++it)
    {
        long long diff = abs(x - *it);
        if (diff <= K)
        {
            componentSize[*it]++;
            componentSize[x]++;
        }
    }
}

void removeElement(long long x, long long K)
{
    S.erase(x);
    for (auto it = S.begin(); it != S.end(); ++it)
    {
        long long diff = abs(x - *it);
        if (diff <= K)
        {
            componentSize[*it]--;
            componentSize[x]--;
        }
    }
}

int main()
{
    int Q;
    long long K;
    cin >> Q >> K;

    for (int i = 0; i < Q; ++i)
    {
        int type;
        long long x;
        cin >> type >> x;

        if (type == 1)
        {
            if (S.find(x) == S.end())
            {
                addElement(x, K);
            }
            else
            {
                removeElement(x, K);
            }
        }
        else if (type == 2)
        {
            cout << findComponentSize(x) << "";
        }
    }

    return 0;
}