#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S, T;
    cin >> S >> T;

    int n = S.size();
    int m = T.size();

    for (int w = 1; w < n; ++w)
    {
        for (int c = 1; c <= w; ++c)
        {
            string concatenated;
            for (int i = c - 1; i < n; i += w)
            {
                concatenated += S[i];
            }
            cout << concatenated << " " << T << " " << endl;
            if (concatenated == T)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
