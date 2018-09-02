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
		double n,s;
		get(n);get(s);
		double sum = s*s*n;
		double a[(int)n];
		if(n==1&&s==0){
			pln("1");
			continue;
		}
		else if(n==1&&s!=0){
			pln("-1");
			continue;
		}
		else{
			if(s==0){
				for(int i=0;i<n;i++)
					a[i]=0;
			}
			else if(((int)n)&1){//n is odd.
				n--;
				double x = sum/n;
				n++;
				x=sqrt(x);
				a[0]=0;
				for(int i=1;i<n;){
					a[i++] = x;
					a[i++] = -x;
				}
			}
			else{//n is even
				double x = sum/n;
				x=sqrt(x);
				for(int i=0;i<n;){
					a[i++] = x;
					a[i++] = -x;
				}
			}
		}
		for(int i=0;i<n;i++){
			pls(a[i]);
		}
		pln("");
	}
}
