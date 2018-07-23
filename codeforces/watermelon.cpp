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
#define tr(container, it) \
for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
	
int main(void){
	int t,n;
	scanf("%d",&t);
	if(((t&1)==0)&&(t>3)) printf("YES\n");
	else printf("NO\n");
}