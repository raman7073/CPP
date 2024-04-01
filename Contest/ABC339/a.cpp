#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string S;
    cin >> S;

    size_t lastDot = S.find_last_of('.');
    cout << S.substr(lastDot + 1) << endl;

    return 0;
}
