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

#define lim 10000000
vector <bool> mark(lim+2, 1);
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
	// rep(i,0,sz(primes)) pln(primes[i]);
	ll t;
	get(t);
	ll n =t;
	ll r=1;
	ll po=0;
	int i=0;
	while(primes[i]<=(t)){

		po=0;
		while(t%primes[i] == 0){
			po++;
			t /=primes[i];
		}
		// watch(po);
		r=1L*r*(po+1);
		// watch(r);
		i++;
		if(i==sz(primes))
			break;
	}
	if(t>1)
		r=r*2;
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
