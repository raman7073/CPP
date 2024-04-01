#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long maxDifference(vector<int> &a, vector<int> &b, int n)
{
    long long totalDifference = 0;
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    int m = b.size();
    vector<int>c(b.begin(),b.begin()+n);
    for(int i= m-1;i>=m-n;i--){
      if(abs(a[n-1]-b[m-1])>abs(a[n-1]-b[n-1])){
        
      }
    }
    
    return totalDifference;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i)
        {
            cin >> b[i];
        }

        cout << "ans-->" << maxDifference(a, b, n) << endl;
    }

    return 0;
}
