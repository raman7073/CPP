#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_possible(const vector<ll>& words, int M, ll max_width) {
    int lines = 1;
    ll current_width = 0;

    for (int i = 0; i < words.size(); ++i) {
        if (current_width + words[i] <= max_width) {
            current_width += words[i];
        } else {
            // Start a new line with the current word
            ++lines;
            current_width = words[i];

            // If we exceed the allowed number of lines, it's not possible
            if (lines > M) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<ll> words(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }

    ll left = *max_element(words.begin(), words.end());
    ll right = accumulate(words.begin(), words.end(), 0LL);
    ll result = right;

    while (left <= right) {
        ll mid = (left + right) / 2;

        if (is_possible(words, M, mid)) {
            result = min(result, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << endl;

    return 0;
}
