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
	while(t--){
		char a[101];
		scanf("%s",a);
		int l = strlen(a);
		if(l>10){
			l-=2;
			printf("%c%d%c\n",a[0],l,a[l+1]);
			continue;
		}
		// printf("%d\n",l );
		// printf("%s\n",a );
		printf("%s\n",a );
	}
}