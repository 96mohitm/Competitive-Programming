#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
 
 
#define rep(i, a, b) \
for( i = ll(a); i< int(b); i++)
 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define watch(x) cout << (#x) << " is " << (x) << endl

int main(void){
	int t,n,i,j,x,y;
	// scanf("%d",&t);
	// while(t--){
		scanf("%d",&n);
		int a[n];
		rep(i,0,n){
			scanf("%d",&a[i]);
			if(!(a[i]&1)) a[i]--;
		}
		rep(i,0,n) printf("%d ",a[i] );
		printf("\n");
	// }
}