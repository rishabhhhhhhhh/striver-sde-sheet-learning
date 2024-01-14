void dfsHelper(
    vector<int> graph[],
    int node,
    vector<int> &disc,
    vector<int> &low,
    vector<bool> &isAp,
    int &timer,
    int parent
) {
    disc[node] = low[node] = timer;
    timer++;
    int child = 0;
    
    for(vector<int>::iterator it = graph[node].begin() ; it != graph[node].end() ; it++) {
        int nextNode = (*it);
        if(disc[nextNode] == -1) {
            child++;
            dfsHelper(graph, nextNode, disc, low, isAp, timer, node);
            low[node] = min(low[node], low[nextNode]);
            
            if(parent != -1 && disc[node] <= low[nextNode]) {
                isAp[node] = true;
            }
        } else if(nextNode != parent) {
            low[node] = min(low[node], disc[nextNode]);
        }
    }
    if(parent == -1 && child > 1) {
        isAp[node] = true;
    }
}

vector<int> articulationPoints(int V, vector<int>adj[]) {
    
    vector<int> disc(V, -1), low(V, -1);
    vector<bool> isAp(V, false);
    
    int parent = -1, timer = 1;
    
    for(int i = 0 ; i < V ; i++)
        if(disc[i] == -1)
            dfsHelper(adj, i, disc, low, isAp, timer, parent);
    
    vector<int> ans;
    for(int i = 0 ; i < V ; i++)
        if(isAp[i] == true) 
            ans.push_back(i);
            
    if(ans.empty())
        return {-1};
    return ans;
}