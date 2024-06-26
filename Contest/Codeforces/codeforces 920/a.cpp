#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector<int> x(4), y(4);
        for (int i = 0; i < 4; ++i) {
            cin >> x[i] >> y[i];
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        int side = max(x[3] - x[0], y[3] - y[0]);

        int area = side * side;

        cout << area << endl;
    }

    return 0;
}
