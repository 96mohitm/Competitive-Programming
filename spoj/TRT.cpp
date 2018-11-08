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
ll dp[2000][2000] = {0};
// top-down approach
// ll wine(int *a, int i, int j, int day){
// 	// base case
// 	if(i>j)
// 		return 0;
// 	if(dp[i][j]!=0)
// 		return dp[i][j];

// 	ll op1 = 1L*a[i]*day + wine(a, i+1, j, day+1);
// 	ll op2 = 1L*a[j]*day + wine(a, i, j-1, day+1);

// 	dp[i][j] = max(op1, op2);

// 	return dp[i][j];
// }
// bottom-up approach
void botupwine(int *a, int i, int j){
	int days = j-i+1;
	for(int m=0;m<days;m++){
		for(int n=0;n<days-m;n++){
			if(m==0){
				dp[n][n+m] = 1L*days*a[n];
				// watch(n);
				// watch(a[n]);
				// watch(dp[n][n+m]);
			}
			else{
				ll mul = days - m;
				// watch(mul);
				dp[n][n+m] = max(1L*mul*a[n] + 1L*dp[n+1][n+m], 1L*mul*a[n+m] +1L*dp[n][n+m-1]);
			}
		}
	}
}

void solve(){
	int n;
	get(n);
	int a[n];
	rep(i,0,n) get(a[i]);
	// rep(i,0,n) pln(a[i]);
	botupwine(a,0,n-1);
	// rep(i,0,n){
	// 	rep(j,0,n)
	// 		pls(dp[i][j]);
	// 	pln("");
	// }
	pln(dp[0][n-1]);
}

int main(){
	fast();
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	solve();

}