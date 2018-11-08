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

ll strtoll(string s){
	int l = s.length();
	ll x=0;
	rep(i,0,l){
		ll t = (int)(s[i]-'0');
		x=x*10L;
		x+=t;
	}
	return x;
}

void solve(){
	int t;
	get(t);
	string s;
	int x=0;
	while(x++!=t){
		get(s);
		ll r=strtoll(s);
		while(s!="="){
			// watch(s);
			if(s=="+"){
				get(s);
				r+=strtoll(s);
			}
			else if(s=="-"){
				get(s);
				r-=strtoll(s);
			}
			else if(s=="*"){
				get(s);
				r*=strtoll(s);
			}
			else if(s=="/"){
				get(s);
				r/=strtoll(s);
			}
			// watch(s);
			get(s);
			// break;
		}
		pln(r);
		// break;
	}
}
void solve1(){
	string s="2";
	int t=20;
	while(t--){
		get(s);
		watch(s);
	}
}

int main(){
	fast();
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	solve();

}