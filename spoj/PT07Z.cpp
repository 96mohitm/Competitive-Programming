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
vector<bool> v;
vector<vector<int> > g;
vector<int> d;

void edge(int a, int b){
    g[a].push_back(b);
    g[b].push_back(a);
}
void bfs(int u){
    queue<int> q;
    d[u] = 0;
    q.push(u);
    v[u] = 1;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        vector<int>::iterator it;
        for(it = g[f].begin(); it!=g[f].end(); it++){
            if(!v[*it]){
                d[*it] = d[f]+1;
                q.push(*it);
                // q.push(*it);
                v[*it] = 1;
            }
        }
    }
}

void solve(){
	int n,x,y;
    get(n);
    v.assign(n+1,0);
    g.assign(n+1, vector<int>());
    for(int i=1;i<n;i++){
        get(x);get(y);
        edge(x,y);
    }
    d.assign(n+1,0);
    bfs(1);
    int pos = (max_element(d.begin(), d.end()) - d.begin()); 
    v.assign(n+1,0);
    bfs(pos);
    pln(*max_element(d.begin(), d.end()));
}

int main(void){
	fast();
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	solve();
}
