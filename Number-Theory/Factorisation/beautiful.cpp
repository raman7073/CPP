/* Problem Code -BDOI16B Platform -SPOJ Solution by-Raman Mehta*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void FIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    FIO();
    int t;
    cin >> t;
    ll ct = 0;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll ans = LONG_MAX;

        ll k_copy = k;  // Use a copy of k to avoid modifying the original k

        for (int i = 2; i * i <= k_copy; ++i) {
            ll a1 = 0;
            while (k_copy % i == 0) {
                a1++;
                k_copy /= i;
            }
            if (a1 == 0) continue;
            ll b1 = 0;
            ll prime = i;
            while (prime <= n) {
                b1 += (n / prime);
                prime *= i;
            }
            ans = min(ans, b1 / a1);
        }

        if (k_copy > 1) {  // If k_copy is still greater than 1, then it is prime
            ll b1 = 0;
            ll prime = k_copy;
            while (prime <= n) {
                b1 += (n / prime);
                prime *= k_copy;
            }
            ans = min(ans, b1);
        }

        if (ans == LONG_MAX) {
            ans = 0;
        }

        ct++;
        cout << "Case " << ct << ": " << ans << "\n";
    }
    return 0;
}
