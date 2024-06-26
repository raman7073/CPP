#include <iostream>
#include <vector>

using namespace std;

int countRepdigitDates(int N, const vector<int>& days) {
    int repdigitCount = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= days[i - 1]; ++j) {
        
            string monthStr = to_string(i);
            string dayStr = to_string(j);
            string all = monthStr+dayStr;
             
            char c =all[0];
            int flag = 0;
            for(int i=1;i<all.size();i++){
              if(all[i]!=c){
                flag=1;
                break;
              }
            }
            if(flag==0){
                repdigitCount++;
            }
        }
    }

    return repdigitCount;
}

int main() {
    int N;
    cin >> N;

    vector<int> days(N);
    for (int i = 0; i < N; ++i) {
        cin >> days[i];
    }

    int result = countRepdigitDates(N, days);
    cout << result << endl;

    return 0;
}
