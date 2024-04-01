
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool comp(pair<int,int>p1,pair<int,int>p2){
           if(p1.second==p2.second)  return p1.first<=p2.first;
           else return p1.second<=p2.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
               vp.push_back({start[i],end[i]});
        }
        sort(vp.begin(),vp.end(),comp);
       // for(auto x:vp) cout<<x.first<<" "<<x.second<<endl;;
        int ct=0;
        int cur_strt=0,las_end=0;
        for(int i=0;i<vp.size();i++){
            int cur_id=vp[i].first;
            if(cur_id>las_end){ ct++;las_end=vp[i].second;}
        }
        
        return ct;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends