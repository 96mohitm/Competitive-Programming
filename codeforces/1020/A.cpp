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
	int n,h,a,b,q;
	get(n);get(h);get(a);get(b);get(q);
	while(q--){
		int ta,fa,fb,tb;
		get(ta);get(fa);get(tb);get(fb);
		int rt=0,rf=0,cf;
		if(ta==tb){
			rt+=abs(fa-fb);
		}
		else if(fa>=a&&fa<=b){
			rt += abs(ta-tb);
			cf = fa;
			rt+=abs(cf-fb);
		}
		else{
			// rt = min(abs(fa - a),abs(fa-b));
			if(abs(fa - a)<=abs(fa-b)){
				cf = a;
				rt += abs(fa - a);
				rt += abs(ta-tb);
			}
			else{
				cf = b;
				rt += abs(fa-b);
				rt += abs(ta-tb);
			}
			rt+=abs(cf-fb);
		}
		pln(rt);
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
