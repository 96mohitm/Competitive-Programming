#include <bits/stdc++.h>
using namespace std;
 
typedef long long 		ll;
typedef long double 	ld;
typedef vector<int> 	vi;
typedef vector<ll> 		vl;
typedef vector<vi> 		vvi;
typedef vector<ll> 		vl;
typedef vector<vl> 		vvl;
typedef pair<int, int> 	pii;

typedef unsigned long long int 	ul;

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

int main(void){
	fast();
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	int n,x;
	int a[101]={0};
	get(n);
	vi v(n);
	rep(i,0,n){
		get(v[i]);
		// v[i].second=i;
		a[v[i]]++;
	}
	int t=0;
	rep(i,1,101){
		if(a[i]==1)
			t++;
	}
	int r=1;
	char st[n+1];
	st[n]='\0';
	if(t&1){//tis odd
		r=0;
		int e,nu;
		rep(i,0,n){
			if(a[v[i]]>2){
				e=i;
				r=1;
				nu = v[i];
				break;
			}
		}
		if(r){ 
			int u=0;int b=1;
			for(int i=0;i<n;i++){
				if(nu==v[i]&&b){
					st[i]='A';
					b=0;
				}
				else if(a[v[i]]>1){
					st[i]='B';
				}
				else if(a[v[i]]==1){
					if(u&1)
						st[i]='A';
					else
						st[i]='B';
					u++;
				}
			}

		}
	}
	else{
		int u=0;
		for(int i=0;i<n;i++){
			if(a[v[i]]>1){
				st[i]='A';
			}
			else if(a[v[i]]==1){
				if(u&1)
					st[i]='A';
				else
					st[i]='B';
				u++;
			}
		}
	}
	if(r==0)
		pln("NO");
	else{
		pln("YES");
		pln(st);
	}
}
