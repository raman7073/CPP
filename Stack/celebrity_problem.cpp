//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int N) 
    {
        // code here
        int a = 0, b = 1;

        while (b < N) {
        if (M[a][b] == 1) {
            a = b; // 'a' cannot be a celebrity, so update 'a'
           }
          b = b + 1;
        }

    // Check if 'a' is a potential celebrity
    for (int i = 0; i < N; i++) {
        if (i != a && (M[a][i] == 1 || M[i][a] == 0)) {
            return -1; // 'a' is not a celebrity
        }
    }

    return a;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends