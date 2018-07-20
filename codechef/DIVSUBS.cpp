#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
 
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
 
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
 
int main(void){
	fast();
	int t,i;
	ll n;
	get(t);
	while(t--){
		get(n);
		vl a(n),ps(n+1,0),v(n,0);
		rep(i,0,n){
			get(a[i]);
			// a[i]%=n;
			ps[i+1]=(ps[i]+(a[i]%n))%n;
		}
 
		int s,b;
		rep(i,0,n+1){
			if(v[ps[i]]){
				s=v[ps[i]]-1;
				b=i;
				break;
			}
			v[ps[i]]=i+1;
		}
		// pln(s);pln(b);
		int x = b-s;
		pln(x);
		rep(i,s,b) pls(i+1);
		cout<<"\n";	
	}
}
