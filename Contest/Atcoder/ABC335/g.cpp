#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to compute the greatest common divisor (gcd)
long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int N;
    long long P;
    cin >> N >> P;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    unordered_map<long long, int> gcdCount;

    // Count occurrences of gcd for all pairs
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            long long diff = (A[i] - A[j] + P) % P;
            long long commonDivisor = gcd(A[i], A[j]);
            if (commonDivisor != 1)
            {
                diff /= commonDivisor; // Divide by the common divisor to reduce the value
            }
            ++gcdCount[diff];
        }
    }

    long long pairs = 0;

    // Count the number of valid pairs for each gcd
    for (auto &pair : gcdCount)
    {
        pairs += (long long)pair.second * (pair.second - 1) / 2; // Combination formula: nC2
    }

    cout << pairs << endl;

    return 0;
}
