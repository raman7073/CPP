//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution
{
    int minEle;
    stack<int> s, minStack;

public:
    /*returns min element from stack*/
    int getMin()
    {

        // Write your code here
        if (minStack.empty())
            return -1;
        return minStack.top();
    }

    /*returns poped element from stack*/
    int pop()
    {

        // Write your code here
        if (s.empty())
            return -1;
        int topElement = s.top();
        s.pop();
        // If the popped element is the minimum element, pop it from minStack too
        if (topElement == minStack.top())
        {
            minStack.pop();
        }
        return topElement;
    }

    /*push element x into the stack*/
    void push(int x)
    {

        // Write your code here
        s.push(x);
        // If minStack is empty or new element is smaller than or equal to the top of minStack
        if (minStack.empty() || x <= minStack.top())
        {
            minStack.push(x);
        }
    }
};

//{ Driver Code Starts.

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        Solution ob;
        while (q--)
        {
            int qt;
            cin >> qt;
            if (qt == 1)
            {
                // push
                int att;
                cin >> att;
                ob.push(att);
            }
            else if (qt == 2)
            {
                // pop
                cout << ob.pop() << " ";
            }
            else if (qt == 3)
            {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends