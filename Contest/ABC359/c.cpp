#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long Sx, Sy, Tx, Ty;
    cin >> Sx >> Sy >> Tx >> Ty;

    // Calculate parity of (Sx, Sy) and (Tx, Ty)
    int parityS = (Sx + Sy) % 2;
    int parityT = (Tx + Ty) % 2;

    // Direct distance
    long long toll = abs(Sx - Tx) + abs(Sy - Ty);

    // If both points are on the same parity
    if (parityS == parityT)
    {
        cout << toll << endl;
    }
    else
    {
        // Calculate distance to the nearest corner of the target tile
        long long minDistToCorner = min(abs(Sx - Tx) + abs(Sy - Ty),
                                        abs(Sx - (Tx + 1)) + abs(Sy - (Ty + 1)));
        cout << minDistToCorner + 1 << endl; // Additional 1 toll to move to the corner
    }

    return 0;
}
