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
vi pri;
void prime(){
	int a[201];
	rep(i,0,201) a[i]=1;
	pri.pb(2);
	for(int i=3;i<201;i+=2){
		if(a[i]){
			for(int j = i*i;j<201;j+=i){
				a[j]=0;
			}
		}
	}
	for(int i =3;i<201;i+=2){
		if(a[i])
			pri.pb(i);
	}
}



void solve(){
	prime();
	int t;
	get(t);
	vi lp;
	int m = sz(pri);
	rep(i,0,m-1){
		rep(j,i+1,m){
			lp.pb(pri[i]*pri[j]);
		}
	}
	vsort(lp);
	m = sz(lp);
	vi r;
	rep(i,0,m){
		rep(j,0,m)
			r.pb(lp[i]+lp[j]);
	}
	vsort(r);
	while(t--){
		ll n;
		get(n);
		if(binary_search(all(r), n))
			pln("YES");
		else
			pln("NO");
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
