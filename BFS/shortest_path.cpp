#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> adj[1000];
bool visited[1000];

vector<int> shortestPath(int start, int end) {
    queue<int> myq;
    myq.push(start);

    visited[start] = true; //in case of a non-recursive function, the visited array can be declared here
    int prev[1000];
    fill(prev, prev + 1000, 0); //fill with -1 if node numbering starts from 0

    cout << "Visited " << start << "\n";
    while (!myq.empty()) {
        for (auto& next : adj[myq.front()]) {
            if (!visited[next]) {
                cout << "Visited " << next << "\n";
                prev[next] = myq.front();
                if (next == end) goto found;

                visited[next] = true;
                myq.push(next);
            }
        }
        myq.pop();
    }

    found:
    vector<int> path;
    for (int current = end; current != 0; current = prev[current]) {
        path.push_back(current);
    }
    if (path.size() > 1) {
        reverse(path.begin(), path.end());
        return path;
    } else {
        return {};
    }
}

int main() {
    fill(visited, visited + 1000, false);

    /* 
         ---1
        /  / \
       |  4   2
       8  |   | \
       |  3   5--6--10--11--12--13--14
        \  \ /
         ---7
    */
    adj[1].push_back(2);
    adj[1].push_back(4);
    adj[1].push_back(8);

    adj[2].push_back(5);
    adj[2].push_back(6);
    
    adj[3].push_back(7);
    adj[4].push_back(3);
    adj[5].push_back(7);

    adj[5].push_back(6);
    adj[6].push_back(5);

    adj[8].push_back(7);

    int start = 2, end = 7;
    vector<int> path = shortestPath(start, end);
    for (auto& data : path) {
        cout << data << " ";
    }
    cout << "\n";

    return 0;
}