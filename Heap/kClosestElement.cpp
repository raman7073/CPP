class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        if(n<k) return {};
        
        int lb=lower_bound(arr.begin(),arr.end(),x)-arr.begin(); 
        vector<int > ans;
        if(arr[0]>x){ 
           for(int i=0;i<k;i++)
               ans.push_back(arr[i]);
            }
        else if(arr[n-1]<x){
            for(int i=n-k;i<=n-1;i++) 
                 ans.push_back(arr[i]);
        }
        else{
            int l=lb-1,r=lb;
           // if(arr[lb]==x) ans.push_back(arr[lb]);
            while(l>=0&&r<=n-1&&ans.size()!=k){
                if(abs(x-arr[l])<abs(x-arr[r])){ ans.push_back(arr[l]); l--;}
                else if(abs(x-arr[l])>abs(x-arr[r])) {ans.push_back(arr[r]); r++;}
                else if(abs(x-arr[l])==abs(x-arr[r])){
                     if(arr[l]<arr[r]){ans.push_back(arr[l]); l--; }
                     else { ans.push_back(arr[r]); r++;}
                }
            }
            if(ans.size()!=k){
                if(l>=0){
                    while(ans.size()!=k&&l>=0){
                        ans.push_back(arr[l]);
                        l--;
                    }
                }
                else{
                     while(ans.size()!=k&&r<=n-1){
                        ans.push_back(arr[r]);
                        r++;
                    }
                }
            
            }
            sort(ans.begin(),ans.end());
        }
        return ans;
    }
};