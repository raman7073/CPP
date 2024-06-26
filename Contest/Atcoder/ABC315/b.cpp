#include<bits/stdc++.h>
using namespace std;


#define endl "\n" 


int main(){
      ios::sync_with_stdio(false); cin.tie(NULL);
      int m; cin>>m;
      long long int sum=0;
      vector<int> v(m),tot(m);
      for(int i=0;i<m;i++){
        cin>>v[i];
        sum+=v[i];
        tot[i]=sum;
      }
      long long int md = (sum+1)/2;
    //   for(int x: tot){
    //     cout<<x<<" ";
    //   }
    //   cout<<endl;
    //   cout<<md<<endl;
      int b = lower_bound(tot.begin(),tot.end(),md)-tot.begin() +1;
      int a = md;
      if(b-2>=0) a=a-tot[b-2];
      cout<<b<<" "<<a;


      return 0;
}