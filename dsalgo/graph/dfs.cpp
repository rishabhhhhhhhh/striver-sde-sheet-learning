void dfsHelper(
    vector< vector<int> > & graph,
    int node,
    vector<int> & tempAns,
    vector<bool> & visited
) {
    visited[node] = true;
    tempAns.push_back(node);

    for(vector<int>::iterator it = graph[node].begin() ; it != graph[node].end() ; it++) {

        if(visited[(*it)] == false) {

            dfsHelper(graph, (*it), tempAns, visited);
        }
    }
}
vector<vector<int>> dfs(int V, int E, vector<vector<int>> &edges)
{
    vector< vector<int> > graph(V);

    for(vector< vector<int> >::iterator it = edges.begin() ; it != edges.end() ; it++) {

        vector<int> edge = (*it);
        int node1 = edge[0];
        int node2 = edge[1];

        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    vector<bool> visited(V, false);

    vector< vector<int> > ans;

    for(int i = 0 ; i < V ; i++) {

        if(visited[i] == false) {

            vector<int> tempAns;
            dfsHelper(graph, i, tempAns, visited);
            ans.push_back(tempAns);
        }
    }
    return ans;
}