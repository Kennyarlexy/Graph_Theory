#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//take n, the number of node as 4
//adjacency list
vector<int> adj[1000];

//visited marker
bool visited[1000];

void dfs(int current) {
    if (visited[current]) return;

    cout << "Visited " << current << "\n";

    visited[current] = true;
    for (auto& u : adj[current]) {
        dfs(u);
    }
}

int main() {
    fill(visited, visited + 100001, false);

    /* 
            1
           / \
          4   2
          |
          3
    */
    adj[1].push_back(2);
    adj[1].push_back(4);
    adj[4].push_back(3);
    
    int start = 1;
    dfs(start);

    return 0;
}