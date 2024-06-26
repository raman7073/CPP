#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int Q;
    cin >> Q;

    vector<int> A;

    for (int i = 0; i < Q; ++i)
    {
        int query_type;
        cin >> query_type;

        if (query_type == 1)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        else if (query_type == 2)
        {
            int k;
            cin >> k;
            cout << A[A.size() - k] << endl;
        }
    }

    return 0;
}
