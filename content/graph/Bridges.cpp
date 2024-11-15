/**
* Author: John Baldwin
* Description: Lowlink dfs to find cut edges in a graph and add
* them to a set. Function takes in a current node v and its
* parent p unless it is the root in which case p = -1.
* Status: Untested
*/

int n; // number of nodes
int timer = 0; // preorder counter
vector<vector<int>> adj;
unordered_set<pair<int, int>> bridge;
vector<bool> visited(n, false);
vector<int> preorder(n, -1)
vector<int> low(n, -1);

void bridges(int v, int p = -1) {
    visited[v] = true;
    preorder[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], preorder[to]);
        } else {
            bridges(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > preorder[v])
                bridge.insert({v, to});
        }
    }
}