/* 
Single Source Shortest Path (SSSP) is used to find the shortest distance of all other nodes from node x
To do this, we need to do topological sort first to determine the order of graph traversal.
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<int, int>> adj[7];
bool visited[7];
int	order[7];
int dist[7];

int dfs(int i, int current) {
    if (visited[current]) return i;

    visited[current] = true;
    for (auto& next : adj[current]) {
        if (!visited[next.first]) {
            i = dfs(i, next.first);
        }
    }
	order[i] = current;

    return i - 1;
}

//can return the result array as well, but it has to be declared as vector inside this function
void topSort() {
	int i = 6;
    for (int node = 1; node <= 6; node++) {
        if (!visited[node]) {
            i = dfs(i, node);
        }
    }
}

void sssp() {
    for (int i = 1; i <= 6; i++) {
        int current = order[i];
        for (auto& edgeTo : adj[current]) {
            int nextNode = edgeTo.first;
            int weight = edgeTo.second;
            dist[nextNode] = fmin(dist[nextNode], dist[current] + weight);
        }
    }
}

int main() {
    //          1
    //        1/ \4 3
    //        2-->3-->4
    //       7| 8  \3 |5
    //        6     \3|5
    //                5
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 4});

    adj[2].push_back({3, 8});
    adj[2].push_back({6, 7});

    adj[3].push_back({4, 3});
    adj[3].push_back({5, 6});

    adj[4].push_back({5, 10});


	topSort();
    fill(dist, dist + 7, INT_MAX);
    int root = order[1];
    dist[root] = 0;
	
    sssp();
    for (int i = 1; i <= 6; i++) {
        cout << "Distance to node " << i << " = " << dist[i] << "\n";
    }

    return 0;
}