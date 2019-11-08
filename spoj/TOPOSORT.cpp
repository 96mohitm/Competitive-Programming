#include <bits/stdc++.h>
using namespace std;
 
typedef long long 		ll;
typedef long double 	ld;

typedef pair<int, int> 	pii;
typedef vector<int> 	vi;
typedef vector<pii>		vpi;
typedef vector<ll> 		vl;
typedef vector<vi> 		vvi;
typedef vector<ll> 		vl;
typedef vector<vl> 		vvl;

typedef unsigned long long int 	ul;

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define MOD 1000000007
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define vget(v) rep(i, 0, v.z) get(v[i]);
#define vsort(v) sort(v.begin(), v.end())
#define get(x) cin >> x
#define put(x) cout << x
#define pls(x) cout << x << ' '
#define pln(x) cout << x << "\n"
#define vget(v) rep(i, 0, v.z) get(v[i]);
#define rep(i, begin, end) \
  for (__typeof(end) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define watch(x) cout << (#x) << " is " << (x) << endl

void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
// typedef vector<int> graph;
vector<vector<int>> adj;
int n;
void addedge(int x, int y){
    adj[x].push_back(y);
}

void topologicalSort(){
    // stores indegrees of all the vertices.
    vector<int> in_degree(n, 0);

    // fill indegree.
    for(int i=0; i<n; i++){
        for(auto i: adj[i])
            in_degree[i]++;
    }

    // enqueue all the verteces with indegree 0.
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0; i<n; ++i)
        if(in_degree[i]==0)
            q.push(i);
    
    // count of visited vertices.
    int cnt = 0;

    // store the topological order.
    vector<int> top_order;

    while(!q.empty()){
        int u = q.top();
        q.pop();
        top_order.push_back(u);

        // iterate through all the members.
        for(auto i: adj[u])
            if(--in_degree[i]==0)
                q.push(i);

        cnt++;
    }

    // checking if there was a cycle.
    if(cnt!=n){
        cout<<"Sandro fails.\n";
        return;
    }
    for(auto i: top_order)
        cout<<i+1<<" ";
    cout<<"\n";
}



void solve(){
    int m;
    cin>>n>>m;
    // graph g[n];
    adj.assign(n, vector<int>());
    rep(i, 0, m){
        int x, y;
        cin>>x>>y;
        addedge(x-1, y-1);
    }
    topologicalSort();
}

int main(void){
	fast();
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	solve();
}
