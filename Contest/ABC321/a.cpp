#include<bits/stdc++.h>
using namespace std;


#define endl "\n" 


int main(){
      ios::sync_with_stdio(false); cin.tie(NULL);

     map<int,bool> m;
     int n;cin>>n;
     bool ans= true;
     int num = INT_MIN;
     while(n>0){
        int rem = n%10;
        if(rem<=num || m.count(rem)){
            ans=false;
            break;
        }
        m[rem]=true;
        num = rem;
        n=n/10;
     }
     if(ans){
        cout<<"Yes";
     }else{
        cout<<"No";
     }
      return 0;
}