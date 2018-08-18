#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef unsigned long long int ul;

#define MOD 98765431
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

vector<vector<ll> > multiply(vector<vector<ll> > a, vector<vector<ll> > b){
	vector<vector<ll> > r(3, vector<ll>(3,0));
	int i,j,k;
	rep(i,1,3){
		rep(j,1,3){
			rep(k,1,3){
				r[i][j] += (a[i][k]*b[k][j])%MOD;
				r[i][j]%= MOD;
			}
		}
	}
	return r;
}

// vector<vector<ll> > pow(vector<vector<ll> > a, int  n){
// 	if(n==1){
// 		return a;
// 	}
// 	if(n&1)
// 		return multiply(a, pow(a,n-1));
// 	else{
// 		vector<vector<ll> > r = pow(a,n/2);
// 		return multiply(r,r);
// 	}

// }

vector<vector<ll> > pow(vector<vector<ll> > m, ll n){
	if(n==1) return m;
	if(n&1){
		return multiply(m, pow(m,n-1));
	}
	else{
		vector<vector<ll> > x = pow(m, n/2);
		return multiply(x,x);
	}
}


int main(void){
	fast();
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	ll n,p,i,j;
	get(n);get(p);
	vl a(n);
	rep(i,0,n) get(a[i]);
	vector<vector<ll> > t(3, vector<ll>(3,0));
	t[1][1] = n-2;
	t[1][2] = 1;
	t[2][1] = n-1;
	t[2][2] = 0;
	vector<vector<ll> > r = pow(t, p-1);
	vl f(3);
	f[1] = (ll)1; f[2] = (ll)0;
	ll a2 = (f[1]*r[1][1])%MOD;
	ll a1 = ((r[2][1]*f[1])%MOD + (r[2][2]*f[2])%MOD)%MOD;
	ll sum = accumulate(all(a), (ll)0);
	rep(i,0,n){
		ll x = (sum - a[i]) % MOD;
		a[i] = (a1*a[i])%MOD + (a2*x)%MOD;
		a[i]%=MOD;
		pln(a[i]);
	}
}
