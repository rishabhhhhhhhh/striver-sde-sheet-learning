void dfsHelper(
    vector< vector<int> > & graph,
    int node,
    vector<int> & disc,
    vector<int> & low,
    vector< vector<int> > & ans,
    int & timer,
    int parent
) {
    disc[node] = low[node] = timer;
    timer++;

    for(vector<int>::iterator it = graph[node].begin() ; it != graph[node].end() ; it++) {
        int nextNode = (*it);
        if(disc[nextNode] == -1) {
            dfsHelper(graph, nextNode, disc, low, ans, timer, node);
            low[node] = min(low[node], low[nextNode]);

            if(disc[node] < low[nextNode])
                ans.push_back({node, nextNode});
        } else if(nextNode != parent)
            low[node] = min(low[node], disc[nextNode]);
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    //Convert edges to adj list
    vector< vector<int> > graph(v);
    
    for(int i = 0 ; i < e ; i++) {
        vector<int> edge = edges[i];
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    //Find bridges using dfs helper
    vector<int> disc(v, -1), low(v, -1);
    vector< vector<int> > ans;

    int timer = 1, parent = -1;
    for(int i = 0 ; i < v ; i++)
        if(disc[i] == -1)
            dfsHelper(graph, i, disc, low, ans, timer, parent);

    return ans;
}