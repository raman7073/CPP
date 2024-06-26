#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct Player {
    int x, y;
};

bool operator==(const Player& p1, const Player& p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

int min_moves_to_same_cell(int N, vector<string>& grid) {
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  // right, left, down, up

    // Find the positions of the two players
    Player player1, player2;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] == 'P') {
                if (player1.x == 0)
                    player1 = {i, j};
                else
                    player2 = {i, j};
            }
        }
    }

    // Perform BFS to find the minimum moves
    queue<pair<Player, Player>> q;
    set<pair<Player, Player>> visited;
    q.push({player1, player2});
    visited.insert({player1, player2});

    int moves = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [curr_player1, curr_player2] = q.front();
            q.pop();

            if (curr_player1 == curr_player2) {
                return moves;
            }

            for (const auto& dir : directions) {
                Player new_player1 = {curr_player1.x + dir.first, curr_player1.y + dir.second};
                Player new_player2 = {curr_player2.x + dir.first, curr_player2.y + dir.second};

                if (new_player1.x >= 0 && new_player1.x < N && new_player1.y >= 0 && new_player1.y < N &&
                    new_player2.x >= 0 && new_player2.x < N && new_player2.y >= 0 && new_player2.y < N &&
                    grid[new_player1.x][new_player1.y] != '#' &&
                    grid[new_player2.x][new_player2.y] != '#' &&
                    visited.find({new_player1, new_player2}) == visited.end()) {
                    q.push({new_player1, new_player2});
                    visited.insert({new_player1, new_player2});
                }
            }
        }
        moves++;
    }

    return -1;
}

int main() {
    int N;
    cin >> N;

    vector<string> grid(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }

    // Find and print the minimum moves
    int result = min_moves_to_same_cell(N, grid);
    cout << result << endl;

    return 0;
}
