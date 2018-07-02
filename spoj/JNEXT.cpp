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

#define repr(i, a, b) \
for( i = int(a)-1; i>= int(b); i--)

int main(void){
	int t,n,i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int arr[n];
		rep(i,0,n) scanf("%d",&arr[i]);
		// rep(i,0,n) printf("%d ",arr[i]);
		for(i=n-2;i>-1;i--){
			// printf("i=%d\n",i );
			if(arr[i]<arr[i+1]) break;
		}
		if(i==-1){
			printf("-1\n");
		}
		else{
			int x=arr[i];
			rep(j,i+1,n){
				// printf("arr=%d\n",arr[i] );
				if(arr[j]<=arr[i]){
					// x=arr[j];
					break;
				}
			}
			swap(arr[i],arr[j-1]);
			sort(arr+i+1,arr+n);
			// printf("x=%d\n",x );
			// rep(j,0,i) printf("%d",arr[j]);
			// printf("\n");
			// printf("%d",x);
			rep(j, 0, n){
				// if(arr[j]==x) continue;
				// else
					printf("%d",arr[j]);
			}
			printf("\n");

		}
		// else printf("-1\n");
	}
}
