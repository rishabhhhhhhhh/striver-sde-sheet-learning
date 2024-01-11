void bfsHelper(
    vector< vector<int> > & graph,
    int src,
    vector<bool> & visited,
    vector<int> & ans
) {

    queue<int> q;
    q.push(src);

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        if(visited[node] == false) {
            visited[node] = true;
            ans.push_back(node);
        }

        for(vector<int>::iterator it = graph[node].begin() ; it != graph[node].end() ; it++) {
            
            if(visited[(*it)] == false) {

                q.push((*it));
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    
    vector<int> ans;
    vector<bool> visited(n, false);

    bfsHelper(adj, 0, visited, ans); //req was to only show nodes with 0 as src otherwise for loop is preferred
    // for(int i = 0 ; i < n ; i++) { // start from 0

    //     if(visited[i] == false) {

    //         bfsHelper(adj, i, visited, ans);
    //     }
    // }

    return ans;
}