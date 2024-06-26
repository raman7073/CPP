#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct District {
    int x, y, z;
};

bool sortBySeats(const District& a, const District& b) {
    return a.z < b.z;
}

int main() {
    int N;
    cin >> N;

    vector<District> districts(N);
    for (int i = 0; i < N; ++i) {
        cin >> districts[i].x >> districts[i].y >> districts[i].z;
    }

    sort(districts.begin(), districts.end(), sortBySeats);

    int totalX = 0;
    int totalY = 0;
    for (int i = 0; i < N; ++i) {
        totalX += districts[i].x;
        totalY += districts[i].y;
    }

    int requiredSwitches = 0;
    int remainingSeats = (totalX + totalY) % 2; // Remaining seats need to be won by Takahashi
    for (int i = 0; i < N; ++i) {
        if (remainingSeats <= 0) {
            break;
        }
        if (districts[i].z % 2 == 0) {
            int seatsToWin = districts[i].z - 1;
            int switches = min(districts[i].y, (seatsToWin + 1) / 2);
            requiredSwitches += switches;
            remainingSeats -= switches;
        }
    }

    cout << requiredSwitches << endl;

    return 0;
}
