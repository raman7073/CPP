#include<bits/stdc++.h>
using namespace std;


#define endl "\n" 


int main(){
      ios::sync_with_stdio(false); cin.tie(NULL);
      int n;
      string s;
      cin>>n>>s;
      int ans=-1;
      ans = s.find("ABC");
      if(ans!=-1) cout<<ans+1;
      else cout<<-1;


      return 0;
}