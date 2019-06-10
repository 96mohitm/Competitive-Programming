#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int nodes, compo;
vector<int> cn;
// here the nodes in graph will be of 1-based indexing.
class Graph{
    int V;

    list<int> *adj;

    void DFS(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int u);
    void connectedComponents();
};
// constructor
Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V+1];
}

void Graph::addEdge(int v, int u){
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void Graph::DFS(int v, bool visited[]){
    visited[v] = true;
    // cout<<v<<" ";
    nodes++;

    list<int>::iterator it;
    for(it = adj[v].begin(); it!= adj[v].end(); it++){
        if(!visited[*it]){
            DFS(*it, visited);
        }
    }
}

void Graph::connectedComponents(){
    bool *visited = new bool[V];
    for(int v = 1; v<=V; v++)
        visited[v] = false;
    for(int v=1; v<=V; v++){
        if(!visited[v]){
            compo++;
            DFS(v, visited);
            // cout<<"\n";
            cn.push_back(nodes);
            nodes=0;
        }
    }
}


int main(void){
    fast();
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif

    int t;
    cin>>t;
    while(t--){
        cn.clear();
        int v,e,x,y;
        cin>>v>>e;
        Graph g(v);
        for(int i=0; i<e; i++){
            cin>>x>>y;
            g.addEdge(x,y);
        }
        // we need to have two things
        // 1. the number of connected components and 
        // 2. the number of nodes in each connected component
        nodes = compo = 0;
        g.connectedComponents();
        long long int r=1;
        for(int i=0; i<compo; i++)
            r = (1L*(r*(cn[i]*1L)))%MOD;
        cout<<compo<<" "<<r <<"\n";
    }
}