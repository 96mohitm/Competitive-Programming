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
	get(t);
	while(t--){
		int n,m;
		get(n);
		get(m);
		int a[n][m];
		rep(i,0,n){
			rep(j,0,m)
				a[i][j]=0;
		}
		int px[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
		int py[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
		string s[n];
		rep(i,0,n) get(s[i]);
		int r=1;
		rep(i,0,n){
			rep(j,0,m){
				if(s[i][j]=='#')
					continue;
				if(!a[i][j]){
					if(i+px[0]>-1&&j+py[0]>-1){
						if(s[i+px[0]][j+py[0]] =='.'&&s[i][j+py[0]] =='.'&&s[i+px[0]][j] =='.'){
							a[i][j]=1;
							a[i-1][j-1]=1;
							a[i-1][j]=1;
							a[i][j-1]=1;
						}
					}
				}
				if(!a[i][j]){
					if(i-1>-1&&j+1<m){
						if(s[i-1][j] =='.'&&s[i-1][j+1] =='.'&&s[i][j+1] =='.'){
							a[i-1][j]=1;
							a[i-1][j+1]=1;
							a[i][j]=1;
							a[i][j+1]=1;
						}
					}
				}
				if(!a[i][j]){
					if(i+1<n&&j-1>-1){
						if(s[i][j-1] =='.'&&s[i+1][j-1] =='.'&&s[i+1][j] =='.'){
							a[i][j]=1;
							a[i][j-1]=1;
							a[i+1][j-1]=1;
							a[i+1][j]=1;
						}
					}
				}
				if(!a[i][j]){
					if(i+1<n&&j+1<m){
						if(s[i][j+1] =='.'&&s[i+1][j] =='.'&&s[i+1][j+1] =='.'){
							a[i][j]=1;
							a[i][j+1]=1;
							a[i+1][j]=1;
							a[i+1][j+1]=1;
						}
					}
				}
				if(a[i][j]==0){
					r=0;
					break;
				}
			}
		}
		if(r)
			pln("YES");
		else
			pln("NO");
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
