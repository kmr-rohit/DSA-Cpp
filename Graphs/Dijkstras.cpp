// We would be using a min-heap and a distance array of size N initialized with infinity 
// (indicating that at present none of the nodes are reachable from the source node) 
// and the distance to source node as 0.
//  We push the source node to the queue.
//  For every node at the top of the queue we pop that element out and look out for its adjacent nodes.
//  If the current reachable distance is better than the previous distance indicated by the distance array, 
//  we update the distance and push it in the queue.
//  A node with a lower distance would be at the top of the priority queue as opposed to a node with a
//  higher distance. By following the steps 3, until our queue becomes empty, 
//  we would get the minimum distance from the source node to all other nodes. 
//  Here’s a quick demonstration of the same.


#include<bits/stdc++.h>
using namespace std;

int main(){
	int n = 5;
	int src;
	cout<<"Please enter the source cell: "<<endl;
	cin>>src;

	//Making of Graph
	vector<pair<int , int>> g[n+1];
	// Constructing the graph 

	g[1].push_back({2,2});
	g[1].push_back({4,1});
	g[2].push_back({1,2});
	g[2].push_back({5,5});
	g[2].push_back({3,4});
	g[3].push_back({2,4});
	g[3].push_back({4,3});
	g[3].push_back({5,1});
	g[4].push_back({1,1});
	g[4].push_back({3,3});
	g[5].push_back({2,5});
	g[5].push_back({3,1});	

	// Djkstra Implementation 

	priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
	vector<int> dist(n+1 , INT_MAX);
	dist[src] = 0;
	// Pair.first = shortestDistance , pair.second = node value
	pq.push(make_pair(0, src));
	while(!pq.empty()){
		int distance = pq.top().first;
		int prev = pq.top().second;
		pq.pop();

		vector<pair<int, int>>::iterator it;
		for(it = g[prev].begin();it!=g[prev].end();it++){
			int next = it->first;
			int nextDist = it->second;
			if(dist[next]>dist[prev] + nextDist){
				dist[next] = dist[prev] + nextDist;
				pq.push(make_pair(dist[next] , next));
			}
		}
	}

	cout<<"The Distance from source "<<src<<"are:" <<endl;
	for(int i = 0;i<=n;i++){
		if(dist[i] != INT_MAX){
		cout<<i<<"->"<<dist[i]<<endl;

		}
		else{
			cout<<i<<"->"<<"Infinity"<<endl;
		}
	}
	return 0;

}