#include<bits/stdc++.h>
using namespace std;


#define endl "\n" 


int main(){
      ios::sync_with_stdio(false); cin.tie(NULL);
      int n; cin>>n;
      string ans ="";
      for(int i=0;i<=n;i++){
        if(i==0){
            ans+=to_string(1);
            continue;
        }
        int flag=0;
        for(int j=1;j<=9;j++){
            if(n%j == 0 && i!=0 && i%(n/j)==0){
                 ans+=to_string(j);
                 flag=1;
                 break;
            }
        }
        if(flag==0){
            ans+="-";
        }
      }

      cout<<ans;
      return 0;
}