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
		int k;
		get(k);
		string s;
		get(s);
		int l = s.length();
		//if stirng lenght is just 1.
		if(l==1){
			if(s[0]=='?')
				s[0]='0';
			pln(s);
			continue;
		}
		//if k = 2;
		if(k==2){
			int f=1,sc=1,re=1;
			if(l&1){//l is odd
				pln("NO");
				continue;
			}
			else{
				rep(i,0,l){
					if(!f)
						break;
					if(i&1){
						if(s[i]=='0'){
							f=0;
						}
					}
					else{
						if(s[i]=='1'){
							f=0;
						}
					}
				}
				rep(i,0,l){
					if(!sc)
						break;
					if(i&1){
						if(s[i]=='1'){
							sc=0;
						}
					}
					else{
						if(s[i]=='0'){
							sc=0;
						}
					}
				}
				if(f){
					rep(i,0,l){
						if(i&1)
							put('1');
						else
							put('0');
					}
					pln("");
				}
				else if(sc){
					rep(i,0,l){
						if(i&1)
							put('0');
						else
							put('1');
					}
					pln("");
				}
				else
					pln("NO");
			}
			continue;
		}
		int r=1;
		//checking if it is possible or not.
		rep(i,0,l-1){
			if(s[i]!='?'&&s[i+1]!='?'&&s[i]==s[i+1]){
				r=0;
				break;
			}
		}
		if(s[0]!='?'&&s[l-1]!='?'&&s[0]==s[l-1])
			r=0;
		//Now its possible, so finding the given string.
		if(r){
			//first index.
			if(s[0]=='?'){
				rep(j,0,k)
					if(s[1]!=(char)(48+j) && s[l-1]!=(char)(48+j)){
						s[0]=(char)(48+j);
						break;
					}
			}
			//rest of the index.
			rep(i,1,l-1){
				if(s[i]=='?'){
					rep(j,0,k){
						if(s[i-1]!=(char)(48+j) && s[i+1]!=(char)(48+j)){
							s[i]=(char)(48+j);
							break;
						}
					}
				}
			}
			//last index.
			if(s[l-1]=='?'){
				rep(j,0,k)
					if(s[0]!=(char)(48+j) && s[l-2]!=(char)(48+j)){
						s[l-1]=(char)(48+j);
						break;
					}
			}
		}
		rep(i,0,l){
			if(s[i]=='?'){
				r=0;
				break;
			}
		}
		if(r){
			pln(s);
		}
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
