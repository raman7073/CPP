#include <iostream>
#include <string>

using namespace std;

// Function to check if all digits of the number are even
bool areAllDigitsEven(long long n) {
    string numStr = to_string(n);
    for (char digit : numStr) {
        if ((digit - '0') % 2 != 0) { // Check if digit is odd
            return false;
        }
    }
    return true;
}

// Function to find the N-th number whose all digits are even
long long findNthEvenDigitNumber(long long N) {
    long long count = 0;
    for (long long i = 0; ; i += 2) { // Iterate through even numbers
        if (areAllDigitsEven(i)) {
            count++;
            if (count == N) {
                return i;
            }
        }
    }
}

int main() {
    long long N;
    cin >> N;
    cout << findNthEvenDigitNumber(N) << endl;
    return 0;
}
