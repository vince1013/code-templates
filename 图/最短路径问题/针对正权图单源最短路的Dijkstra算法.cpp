using agg2 = array<gg, 2>;
struct Edge {
    gg to, cost;
    Edge(gg t, gg c) : to(t), cost(c) {}
};
vector<vector<Edge>> graph(MAX);
vector<gg> dis(MAX, INT_MAX);
void Dijkstra(gg s) {
    priority_queue<agg2, vector<agg2>, greater<agg2>> pq;
    dis[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if (dis[p[1]] != p[0]) {
            continue;
        }
        for (auto& e : graph[p[1]]) {
            if (dis[e.to] > p[0] + e.cost) {
                dis[e.to] = p[0] + e.cost;
                pq.push({dis[e.to], e.to});
            }
        }
    }
}