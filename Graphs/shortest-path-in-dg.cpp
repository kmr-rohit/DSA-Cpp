// First of all we have to find topplogical sorting
// We will go with dfs
#include<bits/stdc++.h> 
#define INF INT_MAX
using namespace std;


class AdjListNode
{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w)  { v = _v;  weight = _w;}
    int getV()       {  return v;  }
    int getWeight()  {  return weight; }
};

class Graph{
    int V;
    list<AdjListNode> *adj;
    void topologicalsortUtill(int v , bool visited[] , stack<int> &stack );
    public:
    Graph(int V);
    void addEdge(int u , int v , int weight);
    void shortestPath(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<AdjListNode>[V];
}


void Graph::addEdge(int u , int v , int weight){
    AdjListNode node(v , weight);
    adj[u].push_back(node);
}

void Graph::topologicalsortUtill(int v , bool visited[]  , stack<int> &s){
    visited[v] = true;
    
    list<AdjListNode>::iterator i;
    for(i = adj[v].begin() ; i!= adj[v].end();i++){
        AdjListNode node  = *i;
        if(!visited[node.getV()]){
            topologicalsortUtill(node.getV() , visited , s);
        }
    }
    s.push(v);
}

void Graph :: shortestPath(int s){
    stack<int> st;
    int dist[V];
     bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
    for(int i = 0;i<V;i++){
        if(visited[i] == false){
            topologicalsortUtill(i , visited , st);
        }
    }
    
    for(int i = 0;i<V;i++){
        dist[i] = INF;
    }
    dist[s] = 0;
    
    while(st.empty() == false){
        int u = st.top();
        st.pop();
        
        list<AdjListNode>::iterator i;
        
        if(dist[u] != INF){
            for(i=adj[u].begin() ;i != adj[u].end();i++ ){
                if(dist[i->getV()]>dist[u] + i->getWeight()){
                    dist[i->getV()] = dist[u] + i->getWeight();
                }
            }
            
        }
        
    }
    for(int i = 0;i<V;i++){
        (dist[i] == INF)?cout<<"INF"<<" " : cout<<dist[i]<<" ";
    }
}

int main(){
    Graph g(8);
    g.addEdge(0 , 6 ,2);
    g.addEdge(1 , 6 , 8);
    g.addEdge(1 ,4,1);
    g.addEdge(1 , 2 , -4);
    g.addEdge(3 , 0 , 3);
    g.addEdge(3 , 4 , 5);
    g.addEdge(5 , 1 ,2);
    g.addEdge(7 , 5 ,-4);
    g.addEdge(7 , 3 , 4);
    g.addEdge(7 , 1 , -1);
    g.addEdge(7 , 0 ,6);
    
    int s;
    cout<<"Enter The Source for finding all shortestPath: "<<endl;
    cin>>s;
    g.shortestPath(s);
    return 0;
}

#include<bits/stdc++.h> 
#define INF INT_MAX
using namespace std;


class AdjListNode
{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w)  { v = _v;  weight = _w;}
    int getV()       {  return v;  }
    int getWeight()  {  return weight; }
};

class Graph{
    int V;
    list<AdjListNode> *adj;
    void topologicalsortUtill(int v , bool visited[] , stack<int> &stack );
    public:
    Graph(int V);
    void addEdge(int u , int v , int weight);
    void shortestPath(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<AdjListNode>[V];
}


void Graph::addEdge(int u , int v , int weight){
    AdjListNode node(v , weight);
    adj[u].push_back(node);
}

void Graph::topologicalsortUtill(int v , bool visited[]  , stack<int> &s){
    visited[v] = true;
    
    list<AdjListNode>::iterator i;
    for(i = adj[v].begin() ; i!= adj[v].end();i++){
        AdjListNode node  = *i;
        if(!visited[node.getV()]){
            topologicalsortUtill(node.getV() , visited , s);
        }
    }
    s.push(v);
}

void Graph :: shortestPath(int s){
    stack<int> st;
    int dist[V];
     bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
    for(int i = 0;i<V;i++){
        if(visited[i] == false){
            topologicalsortUtill(i , visited , st);
        }
    }
    
    for(int i = 0;i<V;i++){
        dist[i] = INF;
    }
    dist[s] = 0;
    
    while(st.empty() == false){
        int u = st.top();
        st.pop();
        
        list<AdjListNode>::iterator i;
        
        if(dist[u] != INF){
            for(i=adj[u].begin() ;i != adj[u].end();i++ ){
                if(dist[i->getV()]>dist[u] + i->getWeight()){
                    dist[i->getV()] = dist[u] + i->getWeight();
                }
            }
            
        }
        
    }
    for(int i = 0;i<V;i++){
        (dist[i] == INF)?cout<<"INF"<<" " : cout<<dist[i]<<" ";
    }
}

int main(){
    Graph g(8);
    g.addEdge(0 , 6 ,2);
    g.addEdge(1 , 6 , 8);
    g.addEdge(1 ,4,1);
    g.addEdge(1 , 2 , -4);
    g.addEdge(3 , 0 , 3);
    g.addEdge(3 , 4 , 5);
    g.addEdge(5 , 1 ,2);
    g.addEdge(7 , 5 ,-4);
    g.addEdge(7 , 3 , 4);
    g.addEdge(7 , 1 , -1);
    g.addEdge(7 , 0 ,6);
    
    int s;
    cout<<"Enter The Source for finding all shortestPath: "<<endl;
    cin>>s;
    g.shortestPath(s);
    return 0;
}