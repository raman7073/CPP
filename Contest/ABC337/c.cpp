#include <iostream>
#include <vector>
#include <map>

using namespace std;

void constructLine(const vector<int>& A) {
    map<int, vector<int>> nextInLine;
    int frontPerson = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] == -1) {
            frontPerson = i + 1;
        } else {
            nextInLine[A[i]].push_back(i + 1);
        }
    }

    int current = frontPerson;
    while (true) {
        cout << current;
        if (nextInLine.find(current) == nextInLine.end()) {
            break;
        }
        current = nextInLine[current][0];
        cout << " ";
    }

    cout << endl;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    constructLine(A);
    return 0;
}
