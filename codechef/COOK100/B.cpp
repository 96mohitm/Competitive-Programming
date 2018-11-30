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
		string s;
		get(s);
		int a,b;
		a=b=0;
		int l = s.length();
		int i=0;
		while(s[i]=='.')
			i++;
		int pre=0, cnt=0,c=0;
		vi nim;
		int ra=0,rb=0;
		while(i<l){
			if(s[i]=='A'){
				c++;
				if(pre == 1){
					ra+=cnt;
				}
				else if(pre == 2){
					nim.pb(cnt);
				}

				cnt=0;
				if(c&1)	pre=1;
				else	pre=0;
			}
			else if(s[i]=='B'){
				c++;
				if(pre == 2){
					rb+=cnt;
				}
				else if(pre == 1){
					nim.pb(cnt);
				}
				cnt=0;
				if(c&1) pre=2;
				else	pre=0;
			}
			else if(s[i]=='.'){
				cnt++;
			}
			i++;
		}
		if(c&1){
			if(pre==1){
				ra+=cnt;
			}
			else if(pre==2){
				rb+=cnt;
			}
		}
		int r=0;
		if(ra>rb){
			r=1;
		}
		else if(rb>ra){
			r=0;
		}
		else{
			int len = nim.size();
			if(len==0){
				r=0;
			}
			else{
				int x=nim[0];
				rep(i,1,len){
					x = x^nim[i];
				}
				if(x){
					r=1;
				}
				else{
					r=0;
				}
			}
		}
		if(r)
			pln("A");
		else
			pln("B");
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
