

#include <bits/stdc++.h>
using namespace std;
int maximumSkill2(int s, int n, int d, vector<vector<int>> &problems)
{

    sort(problems.begin(), problems.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0]; });
    priority_queue<int> pq;
    int currentSkill = s;
    int j = 0;
    for (int i = 1; i <= d; i++)
    {
        while (j < n && currentSkill >= problems[j][0])
        {
            pq.push(problems[j][1]);
            j++;
        }
        if (!pq.empty())
        {
            currentSkill += pq.top();
            pq.pop();
        }
    }

    return currentSkill;
}
int main()
{
    int s, n, d;
    cin >> s >> n >> d;
    vector<vector<int>> problems(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> problems[i][0] >> problems[i][1];
    }
    cout << maximumSkill2(s, n, d, problems) << endl;
    return 0;
}