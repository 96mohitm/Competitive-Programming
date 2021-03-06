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
	int t;
	// get(t);
	scanf("%d",&t);
	while(t--){
		int n;//,m,r;
		// get(n);get(m);
		scanf("%d",&n);
		int a[n];
		rep(i,0,n){
			scanf("%d",&a[i]);
		}
		int r=1;
		if(n&1){
			r=0;
		}
		else{
			int m= n/2;
			rep(i,0,m){
				if(a[i]==-1&&a[i+m]==-1){
					// pln('1');
					// watch(i);
					a[i]=a[i+m]=1;
				}
				else if(a[i]==-1)
					a[i]=a[i+m];
				else if(a[m+i]==-1)
					a[i+m]=a[i];
				else {
					// watch(i);/
					if(a[i]!=a[i+m]){					
						r=0;
						break;
					}
				}
			}
		}
		if(r){
			printf("YES\n");
			rep(i,0,n)
				printf("%d ",a[i]);
			printf("\n");
		}
		else
			printf("NO\n");
	}
}

int main(void){
	// fast();
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	solve();
}
