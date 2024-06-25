#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(2 * N);
    for (int i = 0; i < 2 * N; ++i)
    {
        cin >> A[i];
    }

    vector<int> fp(N + 1, -1);
    int vcc = 0;

    for (int i = 0; i < 2 * N; ++i)
    {
        int c = A[i];
        if (fp[c] == -1)
        {
            fp[c] = i;
        }
        else
        {

            if (i - fp[c] == 2)
            {
                vcc++;
            }
        }
    }

    cout << vcc << endl;
    return 0;
}
