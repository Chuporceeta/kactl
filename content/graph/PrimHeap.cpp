/**
* Author: Indy256
* Description: Prims algorithm for minimum spanning tree that returns
* a predecessor array of all nodes in the MST
*/
using edge = pair<int, int>;  // (v, cost)
using item = pair<int, int>;  // (cost, v)

tuple<long long, vector<int>> prim_mst(const vector<vector<edge>> &g) {
    size_t n = g.size();
    vector<int> pred(n, -1);
    vector<int> prio(n, numeric_limits<int>::max());
    priority_queue<item, vector<item>, greater<>> q;
    q.emplace(prio[0] = 0, 0);
    long long tree_cost = 0;

    while (!q.empty()) {
        auto [c, u] = q.top();
        q.pop();

        if (prio[u] != c)
            continue;
        tree_cost += c;

        for (auto [v, cost] : g[u]) {
            if (prio[v] > cost) {
                prio[v] = cost;
                pred[v] = u;
                q.emplace(cost, v);
            }
        }
    }
    return {tree_cost, pred};
}