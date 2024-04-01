#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    string S;
    cin >> S;
    map<char, int> mp;
    for (char c : S)
    {
        mp[c]++;
    }

    int position = 0;
    for (int i = 0; i < S.size(); ++i)
    {
        if (mp[S[i]] == 1)
        {
            position = i + 1;
            break;
        }
    }

    cout << position << endl;

    return 0;
}
