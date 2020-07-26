//无权图单源最短路的BFS算法的边除首尾结点外，边不包含其他信息，不需要使用上面的存储结构，graph[i]中存储的直接是i号结点能到达的结点编号
vector<gg> graph[MAX];  // graph[i][j]表示结点i能到达的第j个结点编号
void BFS(gg s) {
    queue<gg> q;
    memset(inQueue, 0, sizeof(inQueue));
    dis[s] = 0;
    q.push(s);
    inQueue[s] = true;
    while (!q.empty()) {
        gg p = q.front();
        q.pop();
        for (gg i : graph[p]) {
            if (!inQueue[i]) {
                q.push(i);
                dis[i] = dis[p] + 1;
                inQueue[i] = true;
            }
        }
    }
}
