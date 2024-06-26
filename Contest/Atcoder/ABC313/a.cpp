#include<bits/stdc++.h>
using namespace std;


#define endl "\n" 


int main(){
      ios::sync_with_stdio(false); cin.tie(NULL);
      int n; cin>>n;
      vector<int>v(n);
      for(int i=0;i<n;i++){
        cin>>v[i];
      }
      auto mxp = max_element(v.begin()+1,v.end());
      int mx =*mxp;

      if(v[0]>mx){
        cout<<0;
      }else{
        cout<<(mx+1-v[0]);
      }

      return 0;
}