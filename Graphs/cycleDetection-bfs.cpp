class Solution{
  public:
  bool cycleBfs(int s ,int v , vector<int> adj[] , vector<int>& vis){
    // Declaration of a Queue with a pair of int , int one for node val , and one for recording its parent of traversal
    queue<pair<int , int>> q;
    vis[s] = true;
    q.push({s, -1}); // Adding source with its parent -1;

    while(!q.empty()){
      int node = q.front().first;
      int parent = q.front().second;
      q.pop();

      for(auto i : adj[node]){
        if(!vis[i]){
          vis[i] = true;
          q.push({i , node});
         }
         else if(parent != i){ // It means we got an connected node already cheacked and not the parent 
          return true;
         }
      }
    }
    return false;
  }
  bool isCycle(int v , vector<int> ad[]){
    vector<int> vis(v+1 , 0);
    for(int i = 0;i<=v;i++){
      if(!vis[v]){
        if(cycleBfs(i , v, adj , vis)){
          return true;
        }
      }
      return false;
      
    }
  }
};
