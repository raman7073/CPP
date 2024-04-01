#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <unordered_map>

using namespace std;

int minCost(string T, vector<vector<string>> &bags)
{
    int n = T.size();
    unordered_map<string, int> dp;
    dp[""] = 0;

    for (char c : T)
    {
        unordered_map<string, int> new_dp;
        for (auto &kv : dp)
        {
            string s = kv.first;
            int cost = kv.second;

            for (auto &bag : bags)
            {
                for (string &str : bag)
                {
                    if (str[0] == c && s.size() + str.size() <= n && s == T.substr(0, s.size()))
                    {
                        string new_s = s + str;
                        if (!new_dp.count(new_s) || new_dp[new_s] > cost + 1)
                        {
                            new_dp[new_s] = cost + 1;
                        }
                    }
                }
            }
        }
        dp = new_dp;
    }

    int ans = INT_MAX;
    for (auto &kv : dp)
    {
        string s = kv.first;
        int cost = kv.second;
        if (s == T)
        {
            ans = min(ans, cost);
        }
    }

    return (ans == INT_MAX) ? -1 : ans;
}

int main()
{
    string T;
    int N;
    cin >> T >> N;

    vector<vector<string>> bags(N);
    for (int i = 0; i < N; ++i)
    {
        int A;
        cin >> A;
        bags[i].resize(A);
        for (int j = 0; j < A; ++j)
        {
            cin >> bags[i][j];
        }
    }

    int result = minCost(T, bags);
    cout << result << endl;

    return 0;
}
