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
	int no[1000001];
	no[2]=1;
	for(int i=2;2*i<1000001;i++){
		ll x = 2L*i - 1L;
		// watch(x);
		no[i*2] = (1L*no[(i-1)*2L]*(x))%MOD;
		// no[i*2]%=MOD;
		// watch((i*2));
		// watch(no[2*i]);
	}
	no[0]=no[1]=1;
	get(t);
	while(t--){
		int n,x;
		get(n);
		int a[1000001];
		rep(i,0,1000001) a[i]=0;
		for(int i=0;i<n;i++){
			get(x);
			a[x]++;
		}
		vl ct;
		// ct.pb(0);
		rep(i,1,1000001){
			if(a[i]){
				ct.pb(a[i]);
			}
		}
		int l = sz(ct);
		ll r =1;
		ll c =0;
		for(int i =l-1;i>=0;i--){
			ll tt = c+ct[i];
			if(tt&1){//odd
				c=1;
				if(tt==1)
					continue;
				else{
					ll y = (1L*ct[i]*no[tt-1])%MOD;
					r=(r*y)%MOD;
				}
			}
			else{//even
				c=0;
				r=(1L*r*no[tt])%MOD;
			}
		}
		pln(r);
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
