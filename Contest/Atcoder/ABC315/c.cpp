#include<bits/stdc++.h>
using namespace std;


#define endl "\n" 


int main(){
      ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin>>n;
    priority_queue<pair<int,int>> pq;
    for(int i = 0;i<n;i++){
        int f,s; cin>>f>>s;
        pq.push({s,f});
    }
    int x = pq.top().second;
    int ps = pq.top().first;
   // cout<<x<<ps<<endl;
    int ans = 0;
    pq.pop();
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        if(p.second == x && ps+p.first/2 > ans){
            ans = ps+p.first/2;
        }else if(p.second!=x && ps + p.first > ans){
            ans = ps+p.first;
        }
    }
    cout<<ans;
      return 0;
}