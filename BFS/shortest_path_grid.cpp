#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//definitely can also use char array
string grid[] = {
    ".....",
    "#..#.",
    "..#..",
    "..#.#",
    "S.#E."
};

const int R = 5, C = 5;

//don't worry, bool array has the default value of false (tested)
bool visited[R][C];
pair<int, int> previous[R][C];
vector<pair<int, int>> path;
queue<int> rq; //row queue
queue<int> cq; //column queue


int exploreNeighbours(int cr, int cc, bool &found /* optional */) {
    if (found) return 0; //optional

    int dr[] = {0, 1, 0, -1}; //delta r
    int dc[] = {1, 0, -1, 0}; //delta c
    int nextNeighbours = 0;

    //check all directions to find the number of valid neighbour
    for (int i = 0; i < 4; i++) {
        int next_r = cr + dr[i];
        int next_c = cc + dc[i];

        //if (not visited and valid row and valid column and not '#') process
        //can also negate this statement and use continue (probably easier to read)
        if (!visited[next_r][next_c] && 
            (next_r >= 0 && next_r < R) && 
            (next_c >= 0 && next_c < C) &&
            grid[next_r][next_c] != '#'
        ) {
            nextNeighbours++;
            rq.push(next_r);
            cq.push(next_c);

            visited[next_r][next_c] = true;
            //keep track of previous if you need to record the path (optional)
            previous[next_r][next_c] = make_pair(cr, cc);

            //optional
            if (grid[next_r][next_c] == 'E') {
                found = true;
                break;
            }
        }
    }

    return nextNeighbours;
}

//record the path if needed (optional)
void getPath(pair<int, int> start, pair<int, int> end) {
    auto current = end;
    while (true) {
        path.push_back(current);
        if (current == start) break;
        current = previous[current.first][current.second];
    }
    reverse(path.begin(), path.end());
}


int fewestMove(int sr, int sc) {
    rq.push(sr);
    cq.push(sc);
    visited[sr][sc] = true;

    int neighbours = 0, nextNeighbours = 0;
    int moves = 0;
    bool found = false;
    while(!rq.empty()) {
        int cr = rq.front(); //current row
        int cc = cq.front(); //current column
        if (grid[cr][cc] == 'E') {
            pair<int, int> start = make_pair(sr, sc);
            pair<int, int> end = make_pair(cr, cc);
            getPath(start, end);
            return moves;
        }

        nextNeighbours += exploreNeighbours(cr, cc, found);
        if (neighbours == 0) {
            neighbours = nextNeighbours;
            nextNeighbours = 0;
            moves++;
        }
        neighbours--;
        rq.pop();
        cq.pop();
    }

    return -1;
}

int main() {
    int moves = fewestMove(4, 0);
    cout << "Min moves = " <<  moves << "\n";
    int count = 0;

    for (auto& data : path) {
        cout << "#" << count << ": ";
        cout << "(" << data.first << ", " << data.second << ")\n";
        if (count > 0 && count < path.size() - 1) {
            grid[data.first][data.second] = 'O';
        }
        count++;
    }

    cout << "\nPath: \n";
    for (auto& row : grid) {
        for (auto& col : row) {
            cout << col << " ";
        }
        cout << "\n";
    }

    return 0;
}