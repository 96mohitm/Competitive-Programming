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
	int n,m;
	get(n);get(m);
	while(n!=0&&m!=0){
		vpi v(m);
		rep(i,0,m){
			get(v[i].se);
			get(v[i].fi);
		}
		vsort(v);
		reverse(all(v));
		int dp[m+1][n+1];
		rep(i,0,m+1){
			rep(j,0,n+1){
				if(i==0||j==0) dp[i][j]=0;
				else if(v[i-1].se <= j)
					dp[i][j] = max((v[i-1].fi + dp[i-1][j - v[i-1].se]), dp[i-1][j]);
				else
					dp[i][j] = dp[i-1][j];
			}
		}
		int minfee=0;
		rep(i,0,n+1){
			if(dp[m][i] == dp[m][n]){
				minfee = i;
				break;
			}
		}
		pls(minfee);
		pln(dp[m][n]);
		get(n);get(m);
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