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
#define vput(v) rep(i, 0, sz(v)) pls(v[i])
#define rep(i, begin, end) \
  for (__typeof(end) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define watch(x) cout << (#x) << " is " << (x) << endl

void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

vector<int> v; //visited vector
vector<vector<int> > g; //adjlist
vi sol;

void edge(int a, int b){
	g[a].push_back(b);
	//for undirected graph
	g[b].push_back(a);
}

struct node{
	int s,d,p;
};

int bfs(int u, int lt){
	int curr = u;
	int result = 1;
	node temp;
	temp.s = u;
	temp.d = lt;
	temp.p = -1;
	queue<node> q;
	q.push(temp);
	while(!q.empty()){
		temp = q.front();
		q.pop();
		v[temp.s]++;
		if(v[temp.s] > 1 && sol[temp.s] != curr){
			result = 0;
			// watch(sol[temp.s]);
		}
		else
			v[temp.s] = 1;
		sol[temp.s] = curr;
		if(temp.d){
			vector<int>::iterator it;
			for(it = g[temp.s].begin(); it != g[temp.s].end(); it++){
				if(*it == temp.p)
					continue;
				node temp1;
				temp1.s = *it;
				temp1.d = temp.d - 1;
				temp1.p = temp.s;
				q.push(temp1);
			}
		}
	}
	return result;
}

/* Main concepts used:
Here we are using bfs in such a way that traversal is being
done only upto that nodes with specific nodes.
*/

void solve(){
	int t;
	get(t);
	while(t--){
		int n,r,m;
		get(n);
		get(r);
		get(m);
		int x, y;
		g.assign(n, vector<int>());

		// sol.assign(n,0);
		vi city(n,0);
		// Taking input of all the edges.
		rep(i,0,r){
			get(x);
			get(y);
			edge(x-1,y-1);
			
		}
		v.assign(n, 0);
		sol.assign(n, -1);
		int rlt = 1;
		// Taking input of all the soldiers.
		rep(i,0,m){
			get(x);
			get(y);
			if(rlt){
				city[x-1] = y;
				rlt = bfs(x-1, y);
				// watch(rlt);
			}
		}
		
		if(rlt){
			if(*max_element(all(v)) == 1 && *min_element(all(v)) == 1 )
				rlt=1;
			else
				rlt=0;
		}
		// watch(rlt);
		// vput(v);
		if(rlt) pln("Yes");
		else pln("No");
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
