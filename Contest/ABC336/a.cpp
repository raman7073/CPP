#include<bits/stdc++.h>
using namespace std;


#define endl "\n" 


int main(){
      ios::sync_with_stdio(false); cin.tie(NULL);

      int n; cin>>n;
      string ans = "L";
      while(n--){
        ans += "o";
      }
      ans += "ng";
      cout<<ans;
      return 0;
}