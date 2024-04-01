#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long convertToDoubleBase5(long long n) {
    vector<long long> digits;
    while (n > 0) {
        digits.push_back(2 * (n % 5));
        n /= 5;
    }
    reverse(digits.begin(), digits.end());

    long long result = 0;
    for (long long digit : digits) {
        result = result * 10 + digit;
    }
    return result;
}

int main() {
    long long n; cin>>n;
    cout << convertToDoubleBase5(n-1);
    return 0;
}
