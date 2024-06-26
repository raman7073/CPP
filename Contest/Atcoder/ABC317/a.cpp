#include<bits/stdc++.h>
using namespace std;


#define endl "\n" 


int main(){
      ios::sync_with_stdio(false); cin.tie(NULL);
      int n,h,x;
      cin>>n>>h>>x;
      vector<int>p(n);
      for(int i=0;i<n;i++){
        cin>>p[i];
      }
      int req = x-h;
      int idx = lower_bound(p.begin(),p.end(),req)-p.begin();
      cout<<(idx+1);


      return 0;
}