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


void solve(){
	int t;
	get(t);
	while(t--){
		ll n,m,cn=0,cm=0,va=0,vb=0;
		get(n);get(m);
		ll a[n],b[m];
		rep(i,0,n){
			get(a[i]);
			if(a[i]){
				va+=a[i];
				cn++;
			}
		}
		rep(i,0,m){
			get(b[i]);
			if(b[i]){
				vb+=b[i];
				cm++;
			}
		}
		int r=0;
		if(cn>=1&&cm>=1&&cn==cm){
			if(va == vb){
				sort(a,a+n);
				sort(b,b+m);
				// int j=0
				r=1;
				rep(i,0,cn){
					if(a[n-1-i]!=b[m-i-1]){
						r=0;
						break;
					}
				}
			}
		}
		else if(cn==0&&cm==0)
			r=1;
		if(r)
			pln("Bob");
		else
			pln("Alice");
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
