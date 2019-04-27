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
        int n;
        get(n);
        string s[n];
        int a[6] = {0};
        rep(i,0,n){
            get(s[i]);
            int l = s[i].length();
            rep(j,0,l){
                if(s[i][j] == 'c')
                    a[0]++;
                else if(s[i][j] == 'o')
                    a[1]++;
                else if(s[i][j] == 'd')
                    a[2]++;
                else if(s[i][j] == 'e')
                    a[3]++;
                else if(s[i][j] == 'h')
                    a[4]++;
                else if(s[i][j] == 'f')
                    a[5]++;
            }
        }
        a[0] = a[0]/2;
        a[3] = a[3]/2;
        pln(*min_element(a,a+6));
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
