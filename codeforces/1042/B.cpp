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
	int n;
	get(n);
	int ct;
	string s[n];
	int k[7];
	rep(i,0,7) k[i]=1000000;
	// a,b,c,ab,ac,bc,abc
	int ua,ub,uc;
	ua=ub=uc=0;
	rep(i,0,n){
		get(ct);
		get(s[i]);
		// pln(c[i]);pln(s[i]);
		int l = s[i].length();
		int a,b,c;
		a=b=c=0;
		rep(j,0,l){
			if(s[i][j]=='A')
				ua=a=1;
			else if(s[i][j]=='B')
				ub=b=1;
			else if(s[i][j]=='C')
				uc=c=1;
		}
		if(a==1&&b==0&&c==0){
			if(k[0]>ct)
				k[0]=ct;
		}
		else if(a==0&&b==1&&c==0){
			if(k[1]>ct)
				k[1]=ct;
		}
		else if(a==0&&b==0&&c==1){
			if(k[2]>ct)
				k[2]=ct;
		}
		else if(a==1&&b==1&&c==0){
			if(k[3]>ct)
				k[3]=ct;
		}
		else if(a==1&&b==0&&c==1){
			if(k[4]>ct)
				k[4]=ct;
		}
		else if(a==0&&b==1&&c==1){
			if(k[5]>ct)
				k[5]=ct;
		}
		else if(a==1&&b==1&&c==1){
			if(k[6]>ct)
				k[6]=ct;
		}
	}
	// rep(i,0,7) watch(k[i]);
	int r=0;
	if(ua==1&&ub==1&&uc==1){
		r=k[6];
		r=min(r,k[0]+k[5]);
		r=min(r,k[1]+k[4]);
		r=min(r,k[2]+k[3]);
		r=min(r,k[3]+k[4]);
		r=min(r,k[3]+k[5]);
		r=min(r,k[4]+k[5]);
		r=min(r,k[0]+k[1]+k[2]);
	}
	else{
		r=-1;
	}
	pln(r);
}
