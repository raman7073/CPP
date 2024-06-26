#include<bits/stdc++.h>
using namespace std;


#define endl "\n" 


int main(){
      ios::sync_with_stdio(false); cin.tie(NULL);

     int N, L ,X; cin>>N>>L;
     int ans=0;
     while (N--)
     {
        cin>>X;
        if(X>=L){
            ans++;
        }
     }
     cout<<ans;
      return 0;
}