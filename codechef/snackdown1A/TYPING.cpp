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
		int d,f,j,k;
		d=f=j=k=0;
		int n;
		get(n);
		int r=0;
		set<string> st;
		while(n--){
			int temp=0;
			string s;
			get(s);
			// watch(s);
			int l = s.length();
			temp+=2;
			int prev;
			if(s[0]=='d'){
				d=1;
				prev=0;
			}
			else if(s[0]=='f'){
				f=1;
				prev=0;
			}
			else if(s[0]=='j'){
				j=1;
				prev=1;
			}
			else if(s[0]=='k'){
				k=1;
				prev=1;
			}
			for(int i=1;i<l;i++){
				if(s[i]=='d'||s[i]=='f'){
					if(prev==0)
						temp+=4;
					else
						temp+=2;
					prev = 0;
				}
				else{
					if(prev==1)
						temp+=4;
					else
						temp+=2;
					prev=1;
				}
			}
			if(st.find(s)==st.end()){
				r+=temp;
				st.insert(s);
			}
			else{
				temp/=2;
				r+=temp;
			}
			// watch(temp);
		}
		pln(r);
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
