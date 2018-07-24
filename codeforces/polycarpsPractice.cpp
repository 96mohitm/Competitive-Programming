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

bool sortsec(pii a,pii b){
	return a.second<b.second;
}

int main(void){
	int n,k,i;
	get(n);
	get(k);
	vector<pii> a(n);
	rep(i,0,n){
		get(a[i].first);
		a[i].second = i+1;
	}
	vsort(a);
	int r=0;
	rep(i,n,n-k) r += a[i].first;
	pln(r);
	if(k==1){
		pln(n);
		return 0;
	}
	sort(a.end()-k, a.end(), sortsec);
	int t=0,x;
	rep(i,n-k,n-1){
		x=a[i].second-t;
		pls(x);
		t=a[i].second;
		// watch(a[i].second);
	}
	x=n-a[n-2].second;
	pln(x);
	// pln("");
}