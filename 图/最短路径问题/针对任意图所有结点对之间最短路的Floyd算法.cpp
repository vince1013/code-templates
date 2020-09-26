//图用邻接矩阵存储，若为有权图，graph[i][i]=0,有权的即为权值，其余均为INT_MAX
//若为无权图，若i和j之间有边，graph[i][j]=1；其余均为0
vector<vector<gg>> graph(MAX, vector<gg>(MAX));
// dis存储到达所有结点对之间的最短路径长度
vector<gg> dis(MAX, vector<gg>(MAX));
void floyd() {
    for (gg i = 0; i < ni; ++i) {
        for (gg j = 0; j < ni; ++j) {
            dis[i][j] = graph[i][j];
        }
    }
    for (gg k = 0; k < ni; ++k) {
        for (gg i = 0; i < ni; ++i) {
            for (gg j = 0; j < ni; ++j) {
                dis[i][j] =
                    min(dis[i][j], dis[i][k] + dis[k][j]);  //有权图用这条语句
                dis[i][j] =
                    dis[i][j] || (dis[i][k] && dis[k][j]);  //无权图用这条语句
            }
        }
    }
}
