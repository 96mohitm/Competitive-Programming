#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef unsigned long long int ul;
 
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
		int p,s,x,y,i,j;
		get(p);get(s);
		vector<vii > sc(p, vii(s));
		vvi ns(p, vi(s));
		rep(i,0,p){
			rep(j,0,s){
				get(x);
				sc[i][j] = {x,j};
			}
			rep(j,0,s){
				get(x);
				ns[i][j] = (x);
			}
		}
		vii r(p);
		rep(i,0,p){
			vsort(sc[i]);
			int n=0;
			rep(j,0,s-1){
				if(ns[i][sc[i][j].second]>ns[i][sc[i][j+1].second]) n++;
			}
			r[i] = {n,(i+1)};
		}
		vsort(r);
		rep(i,0,p){
			// pls(r[i].first);
			pln(r[i].second);
			// pln("");
		}
}
 
