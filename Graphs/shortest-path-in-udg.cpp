
void bfs(vector<int> adj[] , int N , int src){
	int dist[N];// Recording The distance of N nodes from Src 
	for(int i = 0;i<N;i++){
		dist[i] = INT_MAX;
	}
	// Initialised all Distance to a Max Value

	queue<int> q;
	// Distance of src from src itself is zero 
	dist[src] = 0;
	q.push(src);
	// BFS FROM EACH VALUE IN QUEUE 	
	while(q.empty() == false){
		int node = q.front;
		q.pop();

		for(auto it : adj[node]){
			if(dist[node] + 1 < dist[it]){
				dist[it] = dist[node] + 1;
				q.push(it);
			}
		}
	}

	for(int i = 0;i<N;i++){
		cout<<dist[i]<<" ";
	}
}