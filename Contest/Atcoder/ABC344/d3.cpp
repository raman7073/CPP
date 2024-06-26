#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int minCost(const string &T, const vector<string> &bag)
{
    int n = T.size();
    // int m = bag.size();

    // Initializing a vector to store costs for each prefix of T
    vector<int> dp(n + 1, -1); // dp[i] stores the minimum cost to make the prefix T[0..i-1] equal to some prefix of S

    // Base case: empty prefix of T can be made with 0 cost
    dp[0] = 0;

    // Iterate over each bag
    for (const string &s : bag)
    {
        // Iterate over each character of T
        for (int i = 0; i <= n; ++i)
        {
            // Check if the current prefix of T matches some prefix of s
            if (dp[i] != -1 && i + s.size() <= n && s.substr(0, min((int)s.size(), n - i)) == T.substr(i, min((int)s.size(), n - i)))
            {
                // Update dp[i + s.size()] if it's not updated yet or the new cost is less
                if (dp[i + s.size()] == -1 || dp[i + s.size()] > dp[i] + 1)
                {
                    dp[i + s.size()] = dp[i] + 1;
                }
            }
        }
    }

    return dp[n]; // Return the cost to make the entire T equal to some prefix of S
}

int main()
{
    string T;
    int N;
    cin >> T >> N;

    vector<vector<string>> bags(N);
    vector<string> bag;
    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;
        bags[i].resize(A);
        for (int j = 0; j < A; j++)
        {
            cin >> bags[i][j];
            if (T.find(bags[i][j]) != string::npos)
                bag.push_back(bags[i][j]);
        }
    }

    int cost = minCost(T, bag);

    cout << cost << endl;

    return 0;
}
