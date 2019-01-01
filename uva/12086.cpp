#include <bits/stdc++.h>
#include <sstream>
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

int bit[200001], a[200001],n;

void update(int x, int val){
	for(; x<=n; x+= x&-x)
		bit[x]+=val;
}

int query(int x){
	int sum = 0;
	for(; x>0; x -= x&-x)
		sum +=bit[x];
	return sum;
}

void solve(){
	int t =1;
	// int n;
	get(n);
	while(n != 0){
		rep(i,0,n+1){
			bit[i] =0;
			a[i] =0;
		}
		put("Case ");
		put(t++);pln(":");
		rep(i,1,n+1){
			get(a[i]);
			update(i,a[i]);
		}
		string q;
		get(q);
		int x,y;
		while(q != "END"){
			if(q == "S"){
				get(x);get(y);
				update(x , y-a[x]);
				a[x] = y;
			}
			else if(q == "M"){
				get(x);get(y);
				int r = query(y) - query(x-1);
				pln(r);
			}
			get(q);
		}
		get(n);
		if(n)
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
