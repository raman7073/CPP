#include <iostream>
#include <vector>
using namespace std;

void reverseSubstring(string &s, int a, int b) {
    while (a <= b) {
        swap(s[a], s[b]);
        a++;
        b--;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int> l(k), r(k);
        for (int i = 0; i < k; i++) {
            cin >> l[i];
        }
        for (int i = 0; i < k; i++) {
            cin >> r[i];
        }

        int q;
        cin >> q;
    
        int x;
        for (int j = 0; j < q; j++) {
            cin>>x;
            int i = lower_bound(l.begin(),l.end(),x)-l.begin();
              if(i!=k){
                int a = min(x ,l[i]+r[i] - x);
                int b = max(x , l[i]+r[i] - x);
                //cout<<"x-->"<<x<<" i-->"<<i<<" a-->"<<a<<" b--> "<<b<<endl;
                --a,--b;
                reverseSubstring(s,a,b);
              }
        
        }

       

        cout << s << endl;
    }

    return 0;
}
