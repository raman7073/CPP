#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin >> m;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    map<char, int> m1, m2, m3;
    for (int i = 0; i < m; i++)
    {

        m1[s1[i]] = i;
        m2[s2[i]] = i;
        m3[s3[i]] = i;
    }
    int ans = INT_MAX;
    // for (int i = 0; i < m; i++)
    // {
    //     int res = INT_MIN;
    //     if (m1.count(s1[i]) && m2.count(s1[i]) && m3.count(s1[i]))
    //     {
    //         res = max(m1[s1[i]], max(m2[s1[i]], m3[s1[i]]));
    //     }

    //     if (res != INT_MIN)
    //     {
    //         ans = min(ans, res);
    //     }
    // }
    for (auto i : m1)
    {
       
        int res = INT_MIN;
        if (m2.count(i.first) && m3.count(i.first))
        {
            cout << i.second << " "<<m2[i.first]<<" "<<m3[i.first]<<endl;
            res = max(i.second, max(m2[i.first], m3[i.first]));
            cout<<res<<endl;
            ans = min(ans, res);
        }
       

        
    }
    // cout<<endl;
    // for(auto i:m2){
    //     cout<<i.second<<" ";
    // }
    if (ans == INT_MIN)
        ans = -1;
    cout << ans;

    return 0;
}