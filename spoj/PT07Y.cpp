#include <bits/stdc++.h>
using namespace std;
 
typedef long long 		ll;
typedef long double 	ld;
typedef vector<int> 	vi;
typedef vector<ll> 		vl;
typedef vector<vi> 		vvi;
typedef vector<ll> 		vl;
typedef vector<vl> 		vvl;
typedef pair<int, int> 	pii;

typedef unsigned long long int 	ul;

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

vvi adj;
vector<bool> v;

void addEdge(int u, int v){
	adj[u].push_back(v);
	//its a undirected graph
	adj[v].push_back(u);
}
//initializing the visited array to false.
void intialize(){
	for(int i=0;i<10;++i)
		v[i] = 0;
}
//recursive function.
void dfs(int s){
	v[s] = 1;
	// printf("%d\n",s );
	for(int i=0;i<adj[s].size(); ++i){
		if(!v[adj[s][i]])	//if not visited.
			dfs(adj[s][i]);
	}
}

int main(void){
	fast();
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	int n,m,x,y;
	get(n);get(m);
	int r=0;
	if(n==1) r=0;
	else if(m==n-1){
		adj.assign(n+1,vector<int>());
		v.assign(n+1,0);
		rep(i,0,m){
			get(x);get(y);
			addEdge(x,y);
		}
		dfs(1);
		r=1;
		rep(i,1,n+1){
			if(!v[i]){
				r=0;
				// pln("h");
				break;
			}
		}
	}
	else{
		r=0;
	}
	if(r)
		pln("YES");
	else
		pln("NO");
}
