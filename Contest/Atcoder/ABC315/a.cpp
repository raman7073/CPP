#include<bits/stdc++.h>
using namespace std;


#define endl "\n" 


int main(){
      ios::sync_with_stdio(false); cin.tie(NULL);
      string s; cin>>s;
      string ans="";
      for(int i =0;i<s.length();i++){

        if(s[i]=='a' || s[i]=='e'|| s[i]== 'i'|| s[i]== 'o' || s[i]== 'u') continue;
        ans+=s[i];
      }
      cout<<ans;
      return 0;
}