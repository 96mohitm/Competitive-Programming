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
const int N = 1001; 
ll fastexpo(ll x, ll y){
	ll res =1;
	x = x % MOD;
	while(y>0){
		if(y&1)
			res = (res*x)%MOD;
		y = y>>1;
		x = (x*x) % MOD;
	}
	return res;
}

ll factorialNumInverse[N + 1]; 
  
ll naturalNumInverse[N + 1]; 
  
ll fact[N + 1]; 
  
void InverseofNumber(ll p) 
{ 
    naturalNumInverse[0] = naturalNumInverse[1] = 1; 
    for (int i = 2; i <= N; i++) 
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p; 
} 
void InverseofFactorial(ll p) 
{ 
    factorialNumInverse[0] = factorialNumInverse[1] = 1; 
  
    for (int i = 2; i <= N; i++) 
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p; 
} 
  
void factorial(ll p) 
{ 
    fact[0] = 1; 
  
    for (int i = 1; i <= N; i++) { 
        fact[i] = (fact[i - 1] * i) % p; 
    } 
} 
  
ll Binomial(ll N, ll R, ll p) 
{ 
    ll ans = ((fact[N] * factorialNumInverse[R]) 
              % p * factorialNumInverse[N - R]) 
             % p; 
    return ans; 
} 

void solve(){
	ll p = MOD;
    InverseofNumber(p); 
    InverseofFactorial(p); 
    factorial(p); 
	int t;
	get(t);
	// pln(Binomial(1000,533,MOD));
	while(t--){
		int n,m;
		get(n);
		int a[n+1];
		vi ha(2*n+1,0);
		rep(i,1,n+1){
			get(a[i]);
			ha[a[i]]++;
		}
		ll r =0;
		r = fastexpo(2L , (ll)(n));
		r--;
		// watch(r);
		vl v;
		rep(i,1,2*n+1){
			if(ha[i])
				v.pb(ha[i]);
		}
		ll s = sz(v);
		if(s == n){
			// watch(s);
			r = fastexpo(2L , (ll)(n-1));
			pln(r);
			continue;
			// watch(r1);
		}
		// watch(s);
		ll ls =0;
		ll sub=0;
		rep(i,0,s){
			ls +=v[i];
			// ll cs = v[i];
			// break;

			ll rs = 0;
			for(int j=s-1;j>i;j--){
				rs +=v[j];
				// watch(v[j]);
				ll mx = min(rs,ls);
				while(mx!=0){
					// watch(ls);
					// watch(rs);
					// watch(mx);
					ll cl = Binomial(ls,mx,MOD);
					if(ls - v[i] >= mx){
						ll temp = Binomial(ls - v[i], mx,MOD);
						cl = (cl - temp + MOD)%MOD;
					}
					ll cr = Binomial(rs,mx,MOD);
					if(rs - v[j] >= mx){
						ll temp = Binomial(rs - v[j],mx,MOD);
						cr = (cr - temp + MOD)%MOD;
					}
					sub = (sub + (1L * cr * cl)%MOD) %MOD;
					// watch(cl);
					// watch(cr);
					// watch(sub);
					mx--;
				}
			}
		}
		r = (r - sub + MOD)%MOD;
		pln(r);
		watch(Binomial(1000, 500, MOD));
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
