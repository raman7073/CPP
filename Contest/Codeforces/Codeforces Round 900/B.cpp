#include<bits/stdc++.h>
using namespace std;


#define endl "\n" 


int main(){
      ios::sync_with_stdio(false); cin.tie(NULL);
      int t; cin>>t;
      while(t--){
        int n; cin>>n;
         int y=1;
         for(int i=1;i<=n;i++){
            cout<<y<<" ";
            y=y+2;
         }
         cout<<endl;


      }

      return 0;
}