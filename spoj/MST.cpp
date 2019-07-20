#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii> > Graph;
typedef long long int ll;
Graph g(10000);

void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

ll prim(vector<int> &pred){
    int n = g.size();
    // making the pred vector as the size of vector.
    pred.assign(n, -1);
    // visited vector.
    vector<bool> vis(n, false);
    // this will store the wieght of the valid edeges.
    vector<int> prio(n, INT_MAX);
    // starting from 0 vertex.
    prio[0] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    // inserting first vertex.
    q.push(make_pair(0,0));
    ll res=0;
    // cout << "vectex : weight";
    while(!q.empty()){
        int d = q.top().first;  // weight.
        int u = q.top().second;  // vertex.

        q.pop();
        // cout<< u << " " << prio[u]<< "\n";
        if(vis[u])
            continue;
        vis[u] = true;
        res += 1LL*d;

        for(int i=0; i< (int)g[u].size(); i++){
            int v = g[u][i].first;
            if(vis[v])
                continue;
            int nprio = g[u][i].second;
            if(prio[v] > nprio){
                prio[v] = nprio;
                pred[v] = u;
                q.push(make_pair(nprio, v));
            }
        }
    }
    return res;
}
void edge(int u,int v, int d){
    g[u].push_back(make_pair(v, d));
    g[v].push_back(make_pair(u, d));
}

int main(void){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // vector<int> prio;
    // long long res = prim(g, prio);
    // cout << "Minimum total weight:" << res << "\n";
    // vector<int>::iterator it;
    // cout<< "valid edges:\n";
    // for(it = prio.begin(); it!= prio.end(); it++)
    //     cout<< (it - prio.begin()) << " " << *it << "\n";
    fast();
    int n,m;
    cin>>n>>m;
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        edge(x-1,y-1,z);
    }
    vector<int> pred;
    cout<<prim(pred);
}
