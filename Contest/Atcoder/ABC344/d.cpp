#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int miniCost(vector<vector<string>> &bags, string &T, int pos)
{
    int n = T.length();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    vector<string> bag;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] != INT_MAX)
        {
            for (int j = 0; j < bags.size(); j++)
            {
                for (int k = 0; k < bags[j].size(); k++)
                {
                    if (T.includes(bags[j][k]))
                    {
                        bag.push_back(bags[j][k]);
                    }
                    if (i + bags[j][k].length() <= n && T.substr(i, bags[j][k].length()) == bags[j][k])
                    {
                        dp[i + bags[j][k].length()] = min(dp[i + bags[j][k].length()], dp[i] + 1);
                    }
                }
            }
        }
    }

    return dp[n] == INT_MAX ? -1 : dp[n];
}

int main()
{
    string T;
    int N;
    cin >> T >> N;

    vector<vector<string>> bags(N);
    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;
        bags[i].resize(A);
        for (int j = 0; j < A; j++)
        {
            cin >> bags[i][j];
        }
    }

    int cost = miniCost(bags, T, 0);

    cout << cost << endl;

    return 0;
}