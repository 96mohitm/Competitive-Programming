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
	int n;
	get(n);
	int a[n+1],r[n+1];
	// memset(r,-1,sizeof(r));
	rep(i,1,n+1) r[i]=-1;
	set <int> s;
	rep(i,1,n+1){
		get(a[i]);
		if(a[i]==i)
			r[i]=i;
	}
	// rep(i,1,n+1)
	// 	pls(r[i]);
	rep(i,1,n+1){
		if(r[i]==-1){
			s.clear();
			int j=i;
			s.insert(j);
			while(s.find(a[j])==s.end()){
				j = a[j];
				// watch(j);
				s.insert(j);
			}
			// watch(i);
			r[i]=a[j];
			// watch(r[i]);
		}
	}
	rep(i,1,n+1)
	pls(r[i]);
}

int main(void){
	fast();
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	solve();
}
