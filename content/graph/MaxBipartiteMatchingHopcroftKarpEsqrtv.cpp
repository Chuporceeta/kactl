/**
* Author: Indy256
* Description: desc
 * Time: O(E * sqrt(V))
*/

void bfs(const vector<vector<int>> &graph, vector<bool> &used, vector<int> &mapping, vector<int> &dist) {
    fill(dist.begin(), dist.end(), -1);
    size_t n1 = graph.size();
    vector<int> Q(n1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u) {
        if (!used[u]) {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++) {
        int u1 = Q[i];
        for (int v : graph[u1]) {
            int u2 = mapping[v];
            if (u2 >= 0 && dist[u2] < 0) {
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}

bool dfs(const vector<vector<int>> &graph, vector<bool> &vis, vector<bool> &used, vector<int> &matching,
         vector<int> &dist, int u1) {
    vis[u1] = true;
    for (int v : graph[u1]) {
        int u2 = matching[v];
        if (u2 < 0 || (!vis[u2] && dist[u2] == dist[u1] + 1 && dfs(graph, vis, used, matching, dist, u2))) {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}

tuple<int, vector<int>> max_matching(const vector<vector<int>> &graph, int n2) {
    vector<int> mapping(n2, -1);
    size_t n1 = graph.size();
    vector<int> dist(n1);
    vector<bool> used(n1);
    for (int res = 0;;) {
        bfs(graph, used, mapping, dist);
        vector<bool> vis(n1);
        int f = 0;
        for (int u = 0; u < n1; ++u)
            if (!used[u] && dfs(graph, vis, used, mapping, dist, u))
                ++f;
        if (f == 0)
            return {res, mapping};
        res += f;
    }
}

// usage example
int main() {
    vector<vector<int>> g(3);
    g[0].push_back(0);
    g[0].push_back(1);
    g[1].push_back(1);
    g[2].push_back(1);

    auto [max_matching_cardinality, mapping] = max_matching(g, 2);

    cout << (2 == max_matching_cardinality) << endl;

    for (int x : mapping)
        cout << x << " ";
    cout << endl;
}