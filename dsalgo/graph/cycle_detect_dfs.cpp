void dfsHelper(
    vector< vector<int> > & graph,
    int node,
    vector<bool> & visited,
    int parent,
    bool & cycleDetected
) {
    if(cycleDetected == true)
        return;
    visited[node] = true;
    for(vector<int>::iterator it = graph[node].begin() ; it != graph[node].end() ; it++) {
        int nextNode = *it;
        if(visited[nextNode] == false) {
            dfsHelper(graph, nextNode, visited, node, cycleDetected);
        } else if(parent != nextNode){
            cycleDetected = true;
            return;
        }
    }
}

string cycleDetection (vector<vector<int>>& edges, int n, int m){
    vector< vector<int> > graph(n + 1);

    for(int i = 0 ; i < m ; i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    vector<bool> visited(n+1, false);
    bool cycleDetected = false;

    for(int i=1;i<=n && cycleDetected == false;i++){
        if(visited[i] == false) {
            dfsHelper(graph, i, visited, -1, cycleDetected);
        }
    }

    if(cycleDetected)
        return "Yes";
    return "No";
}