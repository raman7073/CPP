#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long int

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    priority_queue<int> pq_max;
    priority_queue<int, vector<int>, greater<int>> pq_min;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pq_max.push(x);
        pq_min.push(x);
    }
    if(n == 1){
        cout<<0;
        return 0;
    }
    int ans = 0;
    while (!(pq_max.top() - pq_min.top() <= 1))
    {
        int mn = pq_min.top();
        pq_min.pop();
        int mx = pq_max.top();
        
        pq_max.pop();
        int x = (mx-mn);
        if(x<=1) break;
    
        pq_max.push(mx-x/2);
        pq_min.push(mn+x/2);
        ans+=(x/2);
        int mni = pq_min.top();
        pq_min.pop();
        int mxi = pq_max.top();
        
        pq_max.pop();
        int xi = (mxi-mni);
        if(xi<=1) break;
        
    }
    // while(pq_max.top()==pq_min.top()){
    //     ans--;
    //     pq_max.pop();
    //     pq_min.pop();
    // }
    
    cout << ans;
    return 0;
}