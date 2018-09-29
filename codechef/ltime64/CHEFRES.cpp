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


void solve(){
	int t;
	// get(t);
	scanf("%d",&t);
	while(t--){
		int n,m,r;
		// get(n);get(m);
		scanf("%d%d",&n,&m);
		vpi p(n);
		rep(i,0,n){
			// get(p[i].fi);
			// get(p[i].se);
			scanf("%d%d",&p[i].fi,&p[i].se);
		}
		vsort(p);
		vi v(n);
		rep(i,0,n){
			v[i] = p[i].se;
			// watch(v[i]);
		}
		while(m--){
			int x;
			// get(x);
			scanf("%d",&x);
			int pos = lower_bound(all(v), x) - v.begin();
			// watch(pos);
			// pln(v[pos]);
			int r=-1;
			if(pos!=n){
				if(p[pos].fi<=x&&p[pos].se>x)
					r=0;
				else if(p[pos].se==x){
					if(pos==n-1)
						r=-1;
					else
						r=p[pos+1].fi-x;
				}
				else{
					r = p[pos].fi-x;
				}
			}
			pln(r);
		}
	}
}

int main(void){
	// fast();
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	solve();
}
