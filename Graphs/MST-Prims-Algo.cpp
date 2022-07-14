// // Procedure : Pick any node then find the minimal wieght edge.
// // pick that edge now again check minimal weight edge for every node present. 


// #include<bits/stdc++.h>
// using namespace std;


// int main(){
// 	int N = 5;
// 	vector<pair<int , int>> adj[N];
// 	adj[0].push_back({1,2});
// 	adj[0].push_back({3,6});
// 	adj[1].push_back({0,2});
// 	adj[1].push_back({2,3});
// 	adj[1].push_back({3,8});
// 	adj[1].push_back({4,5});
// 	adj[2].push_back({1,3});
// 	adj[2].push_back({4,7});
// 	adj[3].push_back({0,6});
// 	adj[3].push_back({1,8});
// 	adj[4].push_back({1,5});
// 	adj[4].push_back({2,7});
// //3arrays are needed to keep track of 
// // Key : This array holds the weight/ cost of the MST(intialized to INT_MAX except the index
// //  0 which is set with value of zero)
// // MST : This is a boolean array which indicates whether a node is 
// // already a part of MST or not(initialized to false except the index 0 which is true)
// // Parent :  This indicates the parent of a particular node in the MST(initialized to -1)

// 	int parent[N];
// 	int key[N];
// 	bool mstset[N];

// 	for(int i = 0;i<N;i++){
// 		key[i] =INT_MAX , mstset[i] = false;
// 	}
// 	key[0] = 0;
// 	parent[0] = -1;
// 	int ansWeight = 0;
// 	for(int count = 0;count<N-1;count++){
// 		int mini = INT_MAX , u;
// 		for(int v = 0;v<N;v++){
// 			if(mstset[v] == false && key[v]<mini){
// 				mini = key[v] , u = v;			}
// 		}

// 		mstset[u] = true;
// 		for(auto it:adj[u]){
// 			int v = it.first;
// 			int weight = it.second;
// 			if(mstset[v] == false && weight<key[v]){
// 				parent[v] = u , key[v] = weight;
// 			}
// 		}

// 	}
// 	for(int i = 1 ;i<N;i++){
// 		cout<<parent[i]<<"-"<<i<<endl;
// 	}
// 	return 0;

// }
// Time Complexity : O(V^2)
// Space Complexity : O(V)


 // OPTIMAL ALGORITHM
// Using  a priority queue to find the minimum weight edge.

#include<bits/stdc++.h>
using namespace std;


int main(){
	int N = 5;
	vector<pair<int , int>> adj[N];
	adj[0].push_back({1,2});
	adj[0].push_back({3,6});
	adj[1].push_back({0,2});
	adj[1].push_back({2,3});
	adj[1].push_back({3,8});
	adj[1].push_back({4,5});
	adj[2].push_back({1,3});
	adj[2].push_back({4,7});
	adj[3].push_back({0,6});
	adj[3].push_back({1,8});
	adj[4].push_back({1,5});
	adj[4].push_back({2,7});

	int parent[N];
	int key[N];
	bool mstset[N];

	for(int i = 0;i<N;i++){
		key[i] =INT_MAX , mstset[i] = false;
	}
		priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> pq;
		key[0] = 0;
		parent[0] = -1;
		pq.push({0,0});

		for(int count = 0;count<N-1 ;count++){
			int  u = pq.top().second;
			pq.pop();

			mstset[u] = true;

			for(auto it:adj[u]){
				int v = it.first;
				int weight = it.second;
				if(mstset[v] == false && weight<key[v]){
					parent[v] = u , key[v] = weight;
					pq.push({key[v],v});
				}

			}
		}
		for(int i = 1 ;i<N;i++){
		cout<<parent[i]<<"-"<<i<<endl;
	}
	return 0;
	
	
}
//  TC - o(N+E) + O(NlogN);
