#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s, f;
        cin >> s >> f;

        int cs1 = 0, cf1 =0;
        
        for(int i=0;i<n;i++){
            if(s[i]==f[i]) continue;
            if(s[i]=='1'){
                cs1++;
               
            }
            if(f[i]=='1'){
                cf1++;
            }
        }
        
       cout<<max(cs1,cf1)<<endl;
          
    }
    return 0;
}
