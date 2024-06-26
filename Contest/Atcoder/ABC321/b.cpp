#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    vector<int> A(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());


    int min_score = 0;

    for (int i = 1; i <=N - 3; i++) {
        min_score += A[i];
    }
    int ans=-1;
    int min_req_score = X - min_score;
    if(min_req_score<=A[0]){
        ans=0;
    }else if(min_req_score>A[0] &&min_req_score<=A[N-2]){
        ans=min_req_score;
    }else if(min_req_score>A[N-2]){
        ans=-1;
    }

    cout<<ans;

    return 0;
}
