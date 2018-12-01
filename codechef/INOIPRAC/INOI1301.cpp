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

ll b[1000000],f[1000000];


void solve(){
	int n,k;
	get(n);get(k);
	k--;
	ll a[n];
	rep(i,0,n) get(a[i]);
	//backward array
	b[0]=a[0];
	if(n>1)
		b[1]=b[0]+a[1];
	for(int i=2;i<n;i++){
		b[i] = max(b[i-1] + a[i], b[i-2] + a[i]);
		// watch(a[i]);
		// watch(b[i]);
	}
	//foeword array
	for(int i=0;i<n;i++){
		if(i<=k)
			f[i] = 0;
		else{
			if(i-k>1){
				f[i] = a[i] + max(f[i-1],f[i-2]);
			}
			if(i-k==1){
				f[i] = a[i];
			}
		}
		// watch(f[i]);
	}
	ll r = INT_MIN;
	for(int i=k;i<n;i++){
		r = max(r, f[i]+b[i]-a[i]);
	}
	pln(r);
}

int main(void){
	fast();
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	solve();
}
