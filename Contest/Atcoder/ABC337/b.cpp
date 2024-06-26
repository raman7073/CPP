#include <iostream>
#include <string>
#include <map>
using namespace std;

bool isExtendedABC(const string &S)
{
    map<char, int> mp;
    int n = S.length();

    for (int i = 0; i < n; i++)
    {
        mp[S[i]] = i;
        if (S[i] == 'A')
        {
            if (mp.count('B') || mp.count('C'))
            {
                return false;
            }
        }
        else if (S[i] == 'B')
        {
            if (mp.count('C'))
            {
                return false;
            }
        }
        // else
        // {
        //     if (!mp.count('A') || !mp.count('B'))
        //     {
        //         return false;
        //     }
        // }
    }
    return true;
}

int main()
{
    string S;
    cin >> S;

    cout << (isExtendedABC(S) ? "Yes" : "No") << endl;

    return 0;
}
