void bfsHelper(
    vector< vector<int> > & graph,
    int node,
    vector<bool> & visited,
    bool & cycleDetected
) {
    queue< pair<int, int> > bfsQ; //node+parent
    bfsQ.push({node, -1});

    while(!bfsQ.empty()) {
        pair<int, int> front = bfsQ.front();
        bfsQ.pop();

        int currentNode = front.first;
        int parentNode = front.second;

        visited[currentNode] = true;
        for(vector<int>::iterator it = graph[currentNode].begin() ; it != graph[currentNode].end() ; it++) {
            int nextNode = *it;
            if(!visited[nextNode]) {
                bfsQ.push({nextNode, currentNode});
            } else if(nextNode != parentNode) {
                cycleDetected = true;
                return;
            }
        }
    }
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector< vector<int> > graph(n+1);
    for(int i=0;i<m;i++){
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    vector<bool> visited(n+1, false);
    bool cycleDetected = false;

    for(int i=1;i<=n && !cycleDetected;i++){
        if(!visited[i]){
            bfsHelper(graph, i, visited, cycleDetected);
        }
    }
    if(cycleDetected)
        return "Yes";
    return "No\n";
}
