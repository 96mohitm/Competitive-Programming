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
int f=0;
long double fun(ll n, ll k){
	long double r;
	if(k==0){
		if(n>0){
			r= (long double)((long double)1.0/((long double)n*1.0));
			return r;
		}
		else
			return 1.0;
	}
	if(n==1)
		return 1.0;
	if(n==2){
		return 1.0;
	}
	if(f){
		f=0;
		
		// if(n==3){
		// 	if(k>1)
		// 		return 1.0;
		// 	else
		// 		return 0.5;
		// }
		// if()
		if(n&1L){//odd
			n--;
			n=n/2L;
			n++;
			return fun(n,k-1L);
		}
		else{
			if(n%4L==0L){
				return fun(n/2L,k-1L);
			}
			else{
				n+=2L;
				n=n/2L;
				return fun(n,k-1L);
			}
		}
	}
	else{
		if(n&1L){//odd
			n--;
			n=n/2L;
			n++;
			return fun(n,k-1L);
		}
		else{
			return fun(n/2L,k-1);
		}
	}
}

void solve(){
	int t;
	get(t);
	while(t--){
		ll n,k;
		// get(n);get(k);
		scanf("%lld%lld",&n,&k);
		f=1;
		if(n==2){
			long double r = 0.5;
			printf("%.7Lf\n",r);
			continue;
		}
		printf("%.7Lf\n",fun(n,k));
		// pln(fun(n,k));
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

