#include<bits/stdc++.h>
using namespace std;


#define endl "\n" 


int main(){
      ios::sync_with_stdio(false); cin.tie(NULL);

      long long int a,b;
      cin>>a>>b;
      cout<<(long long int)(pow(a,b)+pow(b,a));
      return 0;
}