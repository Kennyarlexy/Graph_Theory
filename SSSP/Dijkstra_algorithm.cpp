/* 
Dijkstra's Algorithm only works for graph that doesn't contain negative edge weight. Topological sort isn't needed. Time complexity of O(E log(N)) due to the usage of priority_queue
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<int, int>> adj[7];
bool visited[7];
int dist[7];

struct cmp {
    bool operator () (pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

//can return the result array as well, but it has to be declared as vector inside this function
void dijkstra(int start) {
    //create priority_queue in ascending order
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> mypq;
    mypq.emplace(start, 0);
    dist[start] = 0;
    
    while (!mypq.empty()) {
        //min is the minimum previously recorded distance for node current. note that there could be duplicate entries for the same node in priority_queue.
        int current, prevMin;
        tie(current, prevMin) = mypq.top();
        visited[current] = true;
        mypq.pop();
        if (dist[current] < prevMin) continue; //is prevMin outdated?

        for (auto& edgeTo : adj[current]) {
            int nextNode = edgeTo.first, weight = edgeTo.second;
            if (visited[nextNode]) continue;

            int newMin = fmin(dist[nextNode], prevMin + weight);
            dist[nextNode] = newMin;
            //store new minimum distance so that the next iteration will choose this entry in priority_queue as seen in line 32
            mypq.emplace(nextNode, newMin);
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

    fill(dist, dist + 7, INT_MAX);
    int start = 2; //can be anything
    dijkstra(start);
	
    for (int i = 1; i <= 6; i++) {
        cout << "Distance to node " << i << " = " << dist[i] << "\n";
    }

    return 0;
}