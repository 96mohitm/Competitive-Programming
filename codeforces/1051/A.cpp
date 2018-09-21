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
	 	string a;
	 	get(a);
	 	int u=0,l=0,d=0;
	 	int ln = a.length();
	 	rep(i,0,ln){
	 		if(d&&l&&u)
	 			break;
	 		if(a[i]>='0'&&a[i]<='9')
	 			d+=1;
	 		else if(a[i]>='a'&&a[i]<='z')
	 			l+=1;
	 		else if(a[i]>='A'&&a[i]<='Z')
	 			u+=1;
	 	}
	 	if(u&&l&&d);
	 	else if(u==0&&l==0){
	 		a[0]='a';a[1]='A';
	 	}
	 	else if(l==0&&d==0){
	 		a[0]='a';a[1]='1';
	 	}
	 	else if(u==0&&d==0){
	 		a[0]='A';a[1]='1';
	 	}
	 	else if(l==0){
	 		if(u>1){
	 			rep(i,0,ln){
	 				if(a[i]>='A'&&a[i]<='Z'){
	 					a[i]='a';
	 					break;
	 				}
	 			}
	 		}
	 		else{
	 			rep(i,0,ln){
	 				if(a[i]>='0'&&a[i]<='9'){
	 					a[i]='a';
	 					break;
	 				}
	 			}
	 		}
	 	}
	 	else if(u==0){
	 		if(l>1){
	 			rep(i,0,ln){
	 				if(a[i]>='a'&&a[i]<='z'){
	 					a[i]='A';
	 					break;
	 				}
	 			}
	 		}
	 		else{
	 			rep(i,0,ln){
	 				if(a[i]>='0'&&a[i]<='9'){
	 					a[i]='A';
	 					break;
	 				}
	 			}
	 		}

	 	}
	 	else if(d==0){
	 		if(u>1){
	 			rep(i,0,ln){
	 				if(a[i]>='A'&&a[i]<='Z'){
	 					a[i]='1';
	 					break;
	 				}
	 			}
	 		}
	 		else{
	 			rep(i,0,ln){
	 				if(a[i]>='a'&&a[i]<='z'){
	 					a[i]='1';
	 					break;
	 				}
	 			}
	 		}

	 	}
	 	pln(a);
	}
}
