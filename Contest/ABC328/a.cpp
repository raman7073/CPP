#include<bits/stdc++.h>
using namespace std;


#define endl "\n" 


int main(){
      ios::sync_with_stdio(false); cin.tie(NULL);

      int n,x;cin>>n>>x;
      int sum=0,score;
      for(int i=0;i<n;i++){
          cin>>score;
          if(score<=x){
            sum+=score;
          }
      }
      cout<<sum;
      return 0;
}