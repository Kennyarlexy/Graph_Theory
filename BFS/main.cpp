#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//take n, the number of node as 4
//adjacency list
vector<int> adj[1000];

//visited marker
bool visited[1000];

void bfs(int current) {
    /*
    start by adding start (literally start) node to the queue and set to visited, then for each adj node of current, add them to queue and set them to visited
    on next iteration, move to the next element in queue (poping the queue) and repeat.

    unlike dfs which try to reach the deepest node first then backtrack, bfs traverse a certain number of nodes with the same distance from literal start at the same time
    */
    queue<int> myq;
    myq.push(current);
    visited[current] = true; //in case of a non-recursive function, the visited array can be declared here
    cout << "Visited " << current << "\n";
    while (!myq.empty()) {
        for (auto& next : adj[myq.front()]) {
            if (!visited[next]) {
                cout << "Visited " << next << "\n";
                myq.push(next);
                visited[next] = true;
            }
        }
        myq.pop();
    }
}

int main() {
    fill(visited, visited + 1000, false);

    /* 
          1
         / \
        4   2
        |   | \
        3   5--6
         \ /
          7
    */
    adj[1].push_back(2);
    adj[1].push_back(4);

    adj[2].push_back(5);
    adj[2].push_back(6);
    
    adj[3].push_back(7);
    adj[4].push_back(3);
    adj[5].push_back(7);

    adj[5].push_back(6);
    adj[6].push_back(5);
    
    int start = 1;
    bfs(start);

    return 0;
}