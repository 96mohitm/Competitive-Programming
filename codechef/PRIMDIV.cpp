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
#define mx 1000001

vector<int> a(1000001,1), s(1000001,0);

void seive(){
	a[0]=0;a[1]=0;
	int i,j;
	for(i=4;i<mx;i+=2) a[i]=0;
	int q = sqrt(mx);
	for(i=3;i<q;i+=2){
	// watch(q);
		if(a[i]){
			// watch(i);
			for(j=i*i;j<mx;j=j+(2*i))
				a[j]=0;
		}
	}
	for(i=0;i<mx;i++){
		if(a[i]){
			for(j=i;j<mx;j+=i){
				s[j]+=i;
			}
		}
	}
}

int main(void){
	fast();
	// pln("OK");
	seive();
	ll i,j;
	// rep(i,0,mx) watch(s[i]);
	ll t,n,x;
	get(t);
	while(t--){
		get(n);
		vl a(mx,0);
		rep(i,0,n){
			get(x);
			a[x]++;
		}
		ll r=0;
		rep(i,2,mx){
			if(a[i]){
				r+=(a[i]*(a[i]-1));
				for(j=2*i;j<mx;j+=i){
					if(a[j]&&s[j]%s[i]==0){
						r+=(a[i]*a[j]);
					}
				}
			}
		}
		pln(r);
	}
}