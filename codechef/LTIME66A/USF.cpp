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

#define lim 100001
vector <bool> mark(lim+2, 1);
vector <int> fact(lim+2, 0);
vector <ll> primes;
void sieve(){
	for(ll i=3; i<=lim;i+=2){
		if(mark[i]==1){
			for(ll j=i*i; j<=lim; j+=2*i){
				mark[j]=0;
			}
		}
	}
	primes.pb(2);
	for(ll i=3;i<=lim;i+=2){
		if(mark[i])
			primes.pb(i);
	}
}



void solve(){
	sieve();
	mark[0]=mark[1]=0;
	mark[2]=1;
	for(int i=4;i<100001;i+=2){
		mark[i]=0;
	}
	for(int i=2;i<lim;i++){
		if(mark[i]){
			fact[i]=1;
			for(int j=i*2;j<lim;j+=i)
				fact[j]++;
		}
	}
	int t;
	get(t);
	while(t--){
		int n,m;
		get(n);
		int a[n],h[100001];
		rep(i,0,100001) h[i]=0;
		rep(i,0,n){
			get(a[i]);
			h[a[i]]++;
		}
		vi v;
		rep(i,0,100001){
			if(h[i]){
				v.pb(i);
			}
		}
		ll r=0;
		int l = sz(v);
		rep(i,2,v[l-1]+1){
			ll tm=0;
			for(int j=i;j<v[l-1]+1;j+=i){
				if(h[j]){
					// watch(j);
					// watch(h[j]);
					tm+=h[j];
					// watch(tm);
				}
			}
			// watch(tm);
			tm = 1LL*tm*fact[i];
			if(tm>r)
				r=tm;
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
