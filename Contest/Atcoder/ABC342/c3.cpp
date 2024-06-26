#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int N, Q;
    string S;
    cin >> N >> S >> Q;

    // Create a vector to store positions of characters
    vector<string> positions(26, ""); // 'a' to 'z'

    // Initialize positions
    for (int i = 0; i < N; ++i)
    {
        positions[S[i] - 'a'] += to_string(i) + " ";
    }

    // Process the queries
    char c, d;
    for (int i = 0; i < Q; ++i)
    {
        cin >> c >> d;
        int from = c - 'a';
        int to = d - 'a';

        // Update positions
        positions[to] += positions[from];
        positions[from] = "";
    }

    // Construct the modified string
    string result(N, ' ');
    for (int i = 0; i < 26; ++i)
    {
        if (!positions[i].empty())
        {
            int pos;
            size_t found = 0;
            while ((found = positions[i].find(" ", found)) != string::npos)
            {
                pos = stoi(positions[i].substr(0, found));
                result[pos] = 'a' + i;
                found++;
            }
        }
    }

    // Output the modified string
    cout << result << endl;

    return 0;
}
