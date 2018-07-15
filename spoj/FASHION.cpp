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
	int t, i, sum;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int a[n], b[n];
		rep(i,0,n) scanf("%d",&a[i]);
		rep(i,0,n) scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		sum=0;
		rep(i,0,n){
			sum += (a[i]*b[i]);
		}
		printf("%d\n",sum);
	}
}