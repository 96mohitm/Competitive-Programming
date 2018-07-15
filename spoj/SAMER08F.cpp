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


int main(void){
	int a[101];
	a[0]=0;
	int i;
	rep(i,1,101){
		a[i]= a[i-1]+i*i;
		// printf("i=%d %d\n",i,a[i]);
	}
	int t;
	scanf("%d",&t);
	while(t){
		printf("%d\n",a[t]);
		scanf("%d",&t);
	}
}
