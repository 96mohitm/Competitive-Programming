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
int k=2;
vvl multiply(vvl a, vvl b){
	vvl r(k,vl(k, 0));
	int i,j,l;
	rep(i,0,k){
		rep(j,0,k){
			rep(l,0,k){
				r[i][j]+=(a[i][l]*b[l][j])%MOD;
				r[i][j]%=MOD;
			}
		}
	}
	return r;
}

vvl pow(vvl a, ll p){
	if(p==1) return a;
	if(p&1) return multiply(a, pow(a,p-1));

	vvl r;
	r=pow(a,p/2);
	return multiply(r,r);
}

int main(void){
	fast();
	ll t,n;
	get(t);
	while(t--){
		vvl m(2,vl(2,1));
		m[0][0]=0;
		get(n);
		if(n==0){
			pln("0");
			continue;
		}
		else if(n==1){
			pln("2");
			continue;
		}
		m = pow(m,n+2);
		ll r = (m[0][0]+m[0][1])%MOD;
		pln(r);
	}
}