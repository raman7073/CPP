#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solve_balls_and_boxes(int N, int M, int K, const vector<int>& colors) {
    vector<int> answers;
    unordered_map<int, int> box_contents;  // Maps color to count in boxes
    int total_balls_in_boxes = 0;
    int eaten_balls = 0;

    for (int r = 0; r < N; ++r) {
        int index = r % N;
        int color = colors[index];

        if (box_contents.find(color) != box_contents.end() && box_contents[color] < K) {
            // Add to existing box
            box_contents[color]++;
            total_balls_in_boxes++;
        } else if (box_contents.size() - eaten_balls < M) {
            // Add to a new box
            box_contents[color] = 1;
            total_balls_in_boxes++;
        } else {
            // Ball is eaten
            eaten_balls++;
        }

        // Update the answer for this r
        answers.push_back(total_balls_in_boxes);

        // Undo the first ball's effect for the next iteration
        int first_color = colors[r];
        if (box_contents[first_color] <= K) {
            if (box_contents[first_color] == 1) {
                box_contents.erase(first_color);
            } else {
                box_contents[first_color]--;
            }
            total_balls_in_boxes--;
        } else {
            eaten_balls--;
        }
    }

    return answers;
}

int main() {
    // Sample Input
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> colors(N);
    for (int i = 0; i < N; ++i) {
        cin >> colors[i];
    }

    // Solving
    vector<int> result = solve_balls_and_boxes(N, M, K, colors);

    // Output
    for (int ans : result) {
        cout << ans << endl;
    }

    return 0;
}
