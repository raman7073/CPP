#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<unsigned long long> a009995_list;

unsigned long long a009995(unsigned long long n) {
    return a009995_list[n];
}

int main() {
    a009995_list.push_back(0ULL);
    
    set<unsigned long long> s;
    for (unsigned long long i = 1; i <= 9; i++) {
        s.insert(i);
    }

    while (!s.empty()) {
        unsigned long long m = *s.begin();
        s.erase(s.begin());
        a009995_list.push_back(m);

        for (unsigned long long i = 0; i < m % 10; i++) {
            s.insert(10 * m + i);
        }
    }
    cout<<a009995_list.size()<<endl;
    unsigned long long n;
    cin >> n;
    
    cout << a009995(n) << endl;

    return 0;
}
