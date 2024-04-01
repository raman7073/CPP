#include<bits/stdc++.h>
using namespace std;


#define endl "\n" 
bool comp(const pair<int, int>& a, const pair<int, int>& b) {
   
   if (a.second*b.first - b.second*a.first>0) {
       return a.second/a.first > b.second/b.first;
   }
    return a.first > b.first;
}

int main(){
      ios::sync_with_stdio(false); cin.tie(NULL);
      //priority_queue<int,vector<int>,greater<int>>pq;
      int n; cin>>n;
      vector<pair<int,int>> vp;
      int ts=0,ws=0;
      for(int i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        ts+=z;
        if(x>y){
            ws+=z;
        }else{
            vp.push_back({(x+y)/2 +1-x,z});
        }
      }
      if(ws> ts/2){
        cout<<0;
      }else{
        sort(vp.begin(),vp.end(),comp);
        for(auto x: vp){
            cout<<x.first<<" "<<x.second<<endl;;
        }
        cout<<endl;
        cout<<ws<<" "<<ts<<endl;
        int i=0,ans=0;
        while(ws<ts/2){
           ws+=vp[i].second;
           ans += vp[i].first;
           i++;

        }
        cout<<ws<<" "<<ans;

      }


      return 0;
}