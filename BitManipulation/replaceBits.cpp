#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
/*
   you have  n and m . make m substring of n in range {i to j} in terms of bits . Both n and m are of 32 bits.

*/
void clearBitsInRange(int &n, int i, int j)
{
    int a = (-1 << j);
    int b = (1 << i) - 1;
    int mask = a | b;
    n = n & mask;
}
void rePlaceBits(int &n, int i, int j, int m)
{
    clearBitsInRange(n, i, j);
    int mask = (m << i);
    n = n | mask;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}