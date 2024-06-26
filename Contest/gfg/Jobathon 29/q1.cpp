#include <iostream>
#include <unordered_map>

std::unordered_map<int, int> memo;

int f(int n) {
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    if (n == 0) {
        return memo[n] = 0;
    } else if (n <= 2) {
        return memo[n] = 1;
    } else {
        return memo[n] = f(n - 1) + f(n - 2) + f(n - 3);
    }
}

int main() {
    std::cout << f(7) << std::endl;
    return 0;
}
