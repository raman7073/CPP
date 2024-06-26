#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> per(N);
    unordered_map<int, int> position;

    for (int i = 0; i < N; ++i)
    {

        cin >> per[i];
        position[per[i]] = i;
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i)
    {
        int A, B;
        cin >> A >> B;

        int further_to_front = per[min(position[A], position[B])];

        cout << further_to_front << endl;
    }

    return 0;
}
