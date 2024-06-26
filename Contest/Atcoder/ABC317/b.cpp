#include<bits/stdc++.h>
using namespace std;


#define endl "\n" 


int main(){
      ios::sync_with_stdio(false); cin.tie(NULL);
      int n; cin>>n;
      int sum=0,fn=INT_MAX,ln=INT_MIN;
      for(int i=0;i<n;i++){
        int x;cin>>x;
        sum+=x;
         if(x<fn){
            fn=x;
         }
         if(x>ln){
            ln=x;
         }
      }
      cout<<fn<<" "<<ln<<endl;
         cout<<(ln*(ln+1)/2 - (fn-1)*(fn)/2 - sum);
      


      return 0;
}