#include<bits/stdc++.h>
using namespace std;


#define endl "\n" 


int main(){
      ios::sync_with_stdio(false); cin.tie(NULL);
      int n,m;
      cin>>n>>m;
      vector<int>v(m);
      for(int i=0;i<m;i++){
        cin>>v[i];
      }
      for(int i =1;i<=n;i++){
        int idx = lower_bound(v.begin(),v.end(),i)-v.begin();
        cout<<v[idx]-i<<endl;
      }


      return 0;
}