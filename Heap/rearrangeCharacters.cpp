//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to rearrange the characters in a string such that 
    //no two adjacent characters are same.
    string rearrangeString(string str)
    {
    	// Your code here
    	vector<int>freq(26,0);
    	for(int i=0;i<str.length();i++){
    	    freq[str[i]-97]++;
    	}
    	priority_queue<pair<int,char>> pq;
    	for(int i=0;i<26;i++){
    	     if(freq[i]>0){
        	    char ch = (i+97);
        	    pq.push({freq[i], ch});
    	    }
    	}
    	string ans = "";
    	while(!pq.empty()){
    	    pair<int,char> p = pq.top();
    	    pq.pop();
    	    ans+=p.second;
    	    if(!pq.empty()){
    	        pair<int,char> q = pq.top();
    	        pq.pop();
    	        ans+=q.second;
    	        if(p.first>1){
    	           pq.push({p.first-1,p.second});
    	        }
    	        if(q.first>1){
    	        pq.push({q.first-1,q.second});
    	      }
    	    
    	    }
    	}
    	return ans;
    }
};


//{ Driver Code Starts.

int checker(string str, string pat)
{
    int freq[26];
    for(int i=0;i<26;i++)
        freq[i]=0;
    if(str.length()!=pat.length())
        return 0;
    for(int i=0;i<str.length();i++)
    {
        freq[str[i]-97]--;
        if(pat[i]<97 || pat[i]>122)
            return 0;
        freq[pat[i]-97]++;
    }
    for(int i=0;i<26;i++)
        if(freq[i]!=0)
            return 0;
    for(int i=0;i<pat.length()-1;i++)
        if(pat[i]==pat[i+1])
            return 0;
    return 1;
}

int main()
{
	int t;
	cin>>t;
	cin.ignore(INT_MAX, '\n');
	while(t--)
	{
	    string str,ret;
	    cin>>str;
	    Solution ob;
	    ret = ob.rearrangeString(str);
	    cout << checker(str, ret) << endl;
	}
    return 0;
}
// } Driver Code Ends