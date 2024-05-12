#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> findCorrectlyTypedPositions(const string &S, const string &T)
{
    vector<int> positions;
    int j = 0;
    for (int i = 0; i < S.length(); i++)
    {
        while (j < T.length() && T[j] != S[i])
        {
            j++;
        }
        if (j < T.length())
        {
            positions.push_back(j + 1);
            j++;
        }
    }
    return positions;
}

int main()
{
    string S, T;
    cin >> S >> T;
    vector<int> positions = findCorrectlyTypedPositions(S, T);
    for (int i = 0; i < positions.size(); i++)
    {
        cout << positions[i];
        if (i < positions.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}