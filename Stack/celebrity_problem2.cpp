#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int celebrity(vector<vector<int>> &M, int N)
{
    stack<int> s;

    // Push all people onto the stack
    for (int i = 0; i < N; ++i)
    {
        s.push(i);
    }

    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        // If a knows b, then 'a' cannot be a celebrity, push 'b' back
        if (M[a][b] == 1)
        {
            s.push(b);
        }
        else
        { // If a doesn't know b, 'b' cannot be a celebrity, push 'a' back
            s.push(a);
        }
    }

    int potentialCelebrity = s.top();

    // Check if the potential celebrity knows nobody and everyone knows them
    for (int i = 0; i < N; ++i)
    {
        if (i != potentialCelebrity && (M[potentialCelebrity][i] == 1 || M[i][potentialCelebrity] == 0))
        {
            return -1; // 'potentialCelebrity' is not a celebrity
        }
    }

    return potentialCelebrity;
}

int main()
{
    // Example 1
    int N1 = 3;
    vector<vector<int>> M1 = {{0, 1, 0},
                              {0, 0, 0},
                              {0, 1, 0}};
    cout << "Example 1: " << celebrity(M1, N1) << endl; // Output: 1

    // Example 2
    int N2 = 2;
    vector<vector<int>> M2 = {{0, 1},
                              {1, 0}};
    cout << "Example 2: " << celebrity(M2, N2) << endl; // Output: -1

    return 0;
}
