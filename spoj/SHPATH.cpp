#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}


typedef pair<int, int> pii;
typedef vector<vector<pii>> Graph;
typedef long long int ll;

void edge(Graph &g, int u, int v, int w){
    g[u].push_back({v,w});
}

void dijkstra(Graph &g, int s, vector<int> &prio, vector<int> &pred){
    int n = g.size();
    prio.assign(n, INT_MAX);
    prio[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push({0,s});

    while(!q.empty()){
        int d = q.top().first;
        int u = q.top().second;
        q.pop();
        if(d != prio[u])
            continue;
        for(int i=0; i<(int)g[u].size(); i++){
            int v = g[u][i].first;
            int nprio = prio[u] + g[u][i].second;
            if(prio[v] > nprio){
                prio[v] = nprio;
                q.push({nprio, v});
            }
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
        int n;
        cin >>n;
        Graph g(n, vector<pii>());
        // The first most important work is to make a graph.
        unordered_map<string, int> m;
        for(int i=0; i<n; i++){
            string s;
            cin>>s;
            // watch(s);
            m[s] = i;
            int e;
            cin>>e;
            for(int j=0; j<e; j++){
                int v, w;
                cin>>v>>w;
                // watch(v);
                edge(g, i, v-1, w);
                // watch(g[i][j].first);
            }
        }
        for(int i=0; i<g.size(); i++){
            for(int j=0; j<g[i].size(); j++){
                // cout<<g[i][j].first;
            }
        }
        int q;
        cin>>q;
        while(q--){
            string s1,s2;
            cin>>s1>>s2;
            // watch(s1);
            // watch(s2);
            int u, v;
            u = m[s1];
            v = m[s2];
            vector<int> prio, pred;
            dijkstra(g, u, prio, pred);
        //         for (int i = 0; i < prio.size(); i++)
        // cout << prio[i] << endl;

            cout<< prio[v]<<"\n";
        }
    }
}