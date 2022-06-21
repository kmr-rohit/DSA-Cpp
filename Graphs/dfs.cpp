// Template for DFS traversal 

void dfs(vector<vector<int>> &graph , int src )
vector<bool> visited(graph.size(),false);
stack<int> st;
st.push(src);
visited[src] = true;

while(!st.empty()){
    int cur = st.top();
    st.pop();
    for(int nextnode=0;nextnode<n;i++){
        if(!visited[curr] && adjacency[curr][nextnode]){
            st.push(nextnode);
            visited[nextnode] = true;
        }
    }
}

}