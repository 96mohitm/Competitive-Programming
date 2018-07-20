#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int, int> pii;

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
	// fast();
	int t;
	get(t);
	ld x1, x2, x3, v1, v2;
	while(t--){
		// get(x1);get(x2);get(x3);get(v1);get(v2);
		scanf("%Lf%Lf%Lf%Lf%Lf",&x1,&x2,&x3,&v1,&v2);
		ld t1 = (x3-x1)/v1;
		ld t2 = (x2-x3)/v2;
		// watch(t1);watch(t2);
		if(t1<t2)
			printf("Chef\n");
			// cout<<"Chef\n";
		else if(t1>t2)
			printf("Kefa\n");
			// cout<<"Kefa\n";
		else
			printf("Draw\n");
			// cout<<"Draw\n";
	}
}