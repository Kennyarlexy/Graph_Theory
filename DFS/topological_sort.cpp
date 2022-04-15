/*
Topological orders ONLY EXISTS in a DAG (Directed Acyclic Graph) or in other word, DIRECTED tree
Remember that the orders are not unique and there could be more than 1 solution for the same problem
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> adj[7];
bool visited[7];
int	result[7];

int dfs(int i, int current) {
    if (visited[current]) return i;

    visited[current] = true;
    for (auto& next : adj[current]) {
        if (!visited[next]) {
            i = dfs(i, next);
        }
    }
	result[i] = current;

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

int main() {
    //          1
    //         / \ 
    //        2-->3-->4
    //        |    \  |
    //        6     \ |
    //                5
    adj[1].push_back(2);
    adj[1].push_back(3);

    adj[2].push_back(3);
    adj[2].push_back(6);

    adj[3].push_back(4);
    adj[3].push_back(5);

    adj[4].push_back(5);

	topSort();
	for (int i = 1; i <= 6; i++) {
		cout << result[i] << "\n";
	}

    return 0;
}