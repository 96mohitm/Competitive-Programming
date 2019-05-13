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
/*
The theory we are using here is
a graph is bipartite if it's two colourable!
*/
int n;
vvi adj;
void edge(int x, int y){
	adj[x].pb(y);
	adj[y].pb(x);
}
bool bipartite(){
	vi side(n,-1);
	bool is_bipartite = true;
	queue<int> q;
	for(int st = 0; st < n; ++st){
		// watch(st);
		if(side[st] == -1){
			q.push(st);
			side[st] = 0;
			while(!q.empty()){
				int v = q.front();
				// watch(v);
				q.pop();
				for(int u : adj[v]){
					if(side[u] == -1){
						side[u] = side[v]^1;
						q.push(u);
					}
					else if(side[u] == side[v]){
						// watch(is_bipartite);
						// watch(u);
						return false;
					}
				}
			}
		}
	}
	return is_bipartite;
}

void solve(){
	int t;
	get(t);
	int c=1;
	while(t--){
		put("Scenario #");put(c++);pln(":");
		int m,r,x,y;
		get(n);get(m);
		adj.assign(n, vector<int>());
		while(m--){
			get(x);get(y);
			x--;
			y--;
			edge(x,y);
		}
		if(bipartite()){
			pln("No suspicious bugs found!");
		}
		else{
			pln("Suspicious bugs found!");
		}
	}
}

int main(void){
	fast();
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	solve();
}
