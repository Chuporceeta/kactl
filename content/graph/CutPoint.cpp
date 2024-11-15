/**
* Author: John Baldwin
* Description: Lowlink dfs to find cut edges in a graph and add
* them to a set. Function takes in a current node v and its
* parent p unless it is the root in which case p = -1.
* Status: Untested
*/
int n; // number of nodes
int timer = 0;
vector<vector<int>> adj;
unordered_set<int> cuts;
vector<bool> visited;
vector<int> preorder(n, -1); 
vector<int> low(n, -1);

void cut(int v, int p = -1) {
    visited[v] = true;
    preorder[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], preorder[to]);
        } else {
            cut(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= preorder[v] && p!=-1)
                cuts.insert(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        cuts.insert(v);
}