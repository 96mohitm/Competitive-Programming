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
	int a,b,c,r;
	scanf("%d%d%d",&a,&b,&c);
	while(a||b||c){
		if(b-a==c-b){
			r=c+(b-a);
			printf("AP %d\n",r);
		}
		else{
			r=c*(b/a);
			printf("GP %d\n",r);
		}
		scanf("%d%d%d",&a,&b,&c);
	}
}
