#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    
    string S;
    cin >> S;

    // Prefix sum to store the count of consecutive same letters
    vector<int> prefixSum(N, 0);
    for (int i = 1; i < N; ++i) {
        prefixSum[i] = prefixSum[i - 1] + (S[i - 1] == S[i] ? 1 : 0);
    }
    for(int x:prefixSum){
        cout<<x<<" ";
    }
    cout<<endl;
    for (int i = 0; i < Q; ++i) {
        int l, r;
        cin >> l >> r;l--;r--;

        int answer = prefixSum[r] - (l >=0  ? prefixSum[l] : 0);
        if(l>=0 && prefixSum[r]==prefixSum[l]){
            answer =0;
        }
        cout << answer << endl;
    }

    return 0;
}