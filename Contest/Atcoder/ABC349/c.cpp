#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isAirportCode(const string &S, string &T)
{
    transform(T.begin(), T.end(), T.begin(), ::tolower);
    if (!T.empty() && T.back() == 'x')
    {
        T.pop_back();
    }

    size_t pos = 0;
    for (char c : T)
    {
        pos = S.find(c, pos);
        if (pos == string::npos)
        {
            return false;
        }
        pos++;
    }
    return true;
}

int main()
{
    string S, T;
    cin >> S >> T;

    if (isAirportCode(S, T))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}