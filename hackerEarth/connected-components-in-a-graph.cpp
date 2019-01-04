#include <bits/stdc++.h>
using namespace std;
class Graph{
	int V;

	vector<int> *adj;
	void DFS(int v, bool visited[]);
public:
	Graph(int v);
	void addEdge(int v, int u);
	int conCom();
};

Graph::Graph(int V){
	this->V = V;
	adj = new vector<int>[V];
}
void Graph::addEdge(int v, int u){
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void Graph::DFS(int v, bool visited[]){
	visited[v] = true;

	vector<int>::iterator i;
	for(i = adj[v].begin();i!=adj[v].end(); ++i)
		if(!visited[*i])
			DFS(*i, visited);
}

int Graph::conCom(){
	int com=0;
	bool *visited = new	bool[V];
	for(int v=0;v<V;v++)
		visited[v] = false;
	for(int v=0; v<V; v++){
		if(!visited[v]){
			DFS(v,visited);
			com++;
		}
	}
	return com;
}
int main(void){
	int v,e;
	scanf("%d%d",&v,&e);
	Graph g(v);
	for(int i=0; i<e; ++i){
		int x,y;
		scanf("%d%d",&x,&y);
		g.addEdge(x-1,y-1);
	}
	printf("%d\n",g.conCom());
}