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
	int t;
	get(t);
	while(t--){
		string m,n;
		get(m);get(n);
		int q;
		get(q);
		int sm = m.length();
		int sn = n.length();
		char col[sm+2],col2[sm+2];
		char row[sn+2],row2[sn+2];
		col[0]=row[0]='0';
		col[sm+1]=row[sn+1]='\0';
		col2[sm+1]=row2[sn+1]='\0';
		if(m[0]=='0'||n[0]=='0'){
			col[1]=row[1]='1';
		}
		else
			col[1]=row[1]='0';
		rep(i,2,sm+1){
			if(col[i-1]=='0'||m[i-1]=='0')
				col[i]='1';
			else
				col[i]='0';
		}
		rep(i,2,sn+1){
			if(row[i-1]=='0'||n[i-1]=='0')
				row[i]='1';
			else
				row[i]='0';
		}
		if(sm>1){	//generate row2
			row2[0] = m[1];
			row2[1] = col[2];
			rep(i,2,sn+1){
				if(row2[i-1]=='0'||row[i]=='0')
					row2[i]='1';
				else
					row2[i]='0';
			}
		}
		if(sn>1){	//generate col2
			col2[0] = n[1];
			col2[1] = row[2];
			rep(i,2,sm+1){
				if(col2[i-1]=='0'||col[i]=='0')
					col2[i]='1';
				else
					col2[i]='0';
			}
		}
		// pln(col);pln(col2);
		char rst[q+1];
		rst[q]='\0';
		rep(i,0,q){
			int l,r;
			get(l);get(r);
			int x = min(l,r);
			if(x==1){
				if(l==1){
					rst[i]=col[r];
				}
				else{
					rst[i]=row[l];
				}
			}
			else{
				x--;
				l-=x;
				r-=x;
				if(l==1){
					rst[i]=col2[r+1];
				}
				else{
					rst[i]=row2[l+1];
				}

			}
		}
		pln(rst);
	}
}
