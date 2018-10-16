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

// void resultprint(map<string, int>::const_iterator it, int i){
// 	if(i == 8)
// 		return;
// 	resultprint(it++, i++);
// 	pls(it->se);
// }

void solve(){
	int t;
	get(t);
	while(t--){
		int n;
		get(n);
		string m,s;
		get(m);
		map<string, int> r;
		for(int i=0;i<8;i++){
			string temp="";
			int k =i;
			for(int j=0;j<3;j++){
				// watch(k);
				if(k&1){
					temp.insert(0,"H");
				}
				else
					temp.insert(0,"T");
				k = k>>1;
				// watch(k);
			}
			// pln(temp);
			r[temp] = i;
		}
		int result[8];
		rep(i,0,8){
			result[i] =0 ;	
		}
		s = m.substr(0,3);
		// pln(s);
		// for(auto it = r.begin(); it!=r.end(); it++){
		// 	pln(it->fi);
		// 	pln(it->se);
		// }
		result[r[s]]++;
		rep(i,3,40){
			s = s.substr(1,2);
			s.pb(m[i]);
			// watch(s);
			result[r[s]]++;
		}
		pls(n);
		auto it = r.begin();
		// it--;
		rep(i,0,8){
			pls(result[i]);
			
		}
		// resultprint(it,0);
		pln("");
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
