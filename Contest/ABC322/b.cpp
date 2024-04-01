#include <iostream>
#include <string>

int main() {
    // Read inputs
    int N,M; std::cin>>N>>M;
    std::string S, T;
    std::cin >> S >> T;


    // Check if S is a prefix of T
    bool isPrefix = true;
    for (int i = 0; i < N; ++i) {
        if (S[i] != T[i]) {
            isPrefix = false;
            break;
        }
    }

    // Check if S is a suffix of T
    bool isSuffix = true;
    for (int i = 0; i < N; ++i) {
        if (S[i] != T[M - N + i]) {
            isSuffix = false;
            break;
        }
    }

    // Output the result
    if (isPrefix && isSuffix) {
        std::cout << "0\n";
    } else if (isPrefix) {
        std::cout << "1\n";
    } else if (isSuffix) {
        std::cout << "2\n";
    } else {
        std::cout << "3\n";
    }

    return 0;
}
