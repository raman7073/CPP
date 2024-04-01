// #include <iostream>

// using namespace std;

// int main() {
//     string S;
//     cin >> S;
//     size_t pos = S.find("ABC");
//     while (pos!= string::npos) {
//             if(S.size()<3) break;
//             S.erase(pos, 3);
//             cout<<S<<endl;
//             pos = S.find("ABC");
//     }

//     cout << S << endl;

//     return 0;
// }
#include <iostream>

using namespace std;

int main() {
    string S;
    cin >> S;

    string result;
    for (char c : S) {
        result.push_back(c);
        // Check if the last three characters in result form "ABC" and remove them
        if (result.size() >= 3 && result[result.size() - 3] == 'A' && result[result.size() - 2] == 'B' && result[result.size() - 1] == 'C') {
            result.pop_back();
            result.pop_back();
            result.pop_back();
        }
    }

    cout << result << endl;

    return 0;
}
