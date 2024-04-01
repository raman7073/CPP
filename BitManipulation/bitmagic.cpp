#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
int getIthBit(int n, int i)
{
    int mask = (1 << i);
    return (n & mask) > 0 ? 1 : 0;
}
void clearIthBit(int &n, int i)
{
    int mask = ~(1 << i);
    n = n & mask;
}
void setIthBit(int &n, int i)
{
    int mask = (1 << i);
    n = n | mask;
}
void updateIthBit(int &n, int i, int v)
{
    clearIthBit(n, i);
    int mask = (v << i);
    n = n | mask;
}
void clearLastIbit(int &n, int i)
{
    int mask = (-1 << i);
    n = n & mask;
}
void clearBitsInRange(int &n, int i, int j)
{
    int a = (-1 << j);
    int b = (1 << i) - 1;
    int mask = a | b;
    n = n & mask;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << getIthBit(3, 1);
    return 0;
}