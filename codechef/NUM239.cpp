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
	int t,n,r,m,i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		r=0;
		if(m-n<20){
			rep(i,n,m+1){
				if(i%10==2||i%10==3||i%10==9)
					r++;
			}
			printf("%d\n",r);
			continue;
		}
		rep(i,n,m){
			if(i%10==0) break;
			if(i%10==2||i%10==3||i%10==9)
				r++;
		}
		j=m-i;
		j/=10;
		r+=(j*3);
		i=i+(j*10);
		rep(i,i,m+1){
			if(i%10==2||i%10==3||i%10==9)
				r++;
		}
		printf("%d\n",r );
	}
}
