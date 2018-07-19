#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
 
 
#define rep(i, a, b) \
for( i = int(a); i< int(b); i++)
 
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
	int t,n,m,i,j,no,r;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		int a[n];
		r=0;
		rep(i,0,n){
			scanf("%d",&a[i]);
			a[i]%=m;
			if(a[i]==0) r++;
		}
		// r=0;
		// no = (1<<n);
		// vi sum(no-1,0);
		// watch(no);
		// rep(i,1,no){
		// 	for(j=0;j<n;j++){
		// 		if(i&(1<<j)) sum[i-1] = (sum[i-1]+a[j])%m;
		// 	}
		// }
		// rep(i,0,no-1){
		// 	if(sum[i]==0) r++;
		// }
		r=(1<<r)-1;
		printf("%d\n",r );
	}
}
