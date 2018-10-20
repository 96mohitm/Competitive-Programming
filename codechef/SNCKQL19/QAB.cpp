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
	get(t);
	while(t--){
		ll n,m;
		get(n);
		ll a[n],b[n];
		rep(i,0,n)
			get(a[i]);
		rep(i,0,n)
			get(b[i]);
		int r=1;
		if(n<3){
			rep(i,0,n){
				if(a[i]!=b[i])
					r=0;
			}
		}
		else{
			for(int i =0;i<n-2;i++){
				if(r==0)
					break;
				if(a[i]>b[i])
					r=0;
				else{
					ll x = b[i]-a[i];
					a[i] +=x;
					ll y = 2L*x;
					a[i+1]+=y;
					y = 3L*x;
					a[i+2] +=y;
				}
			}
			for(int i =n-1;i>n-3;i--){
				if(a[i]!=b[i])
					r=0;
			}
		}
		if(r)
			pln("TAK");
		else
			pln("NIE");
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
