#include<bits/stdc++.h>
using namespace std;


#define endl "\n" 


int main(){
      ios::sync_with_stdio(false); cin.tie(NULL);
      int t; cin>>t;
      while(t--){
        int n,k;cin>>n>>k;
        bool ans = false;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            if(x==k){
                ans=true;
            }
        }
        if(ans) cout<<"Yes\n";
        else cout<<"No\n";
      }


      return 0;
}