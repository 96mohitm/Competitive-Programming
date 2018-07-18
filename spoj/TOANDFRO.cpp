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
	int c;
	scanf("%d",&c);
	char a[201];
	while(c){
		scanf("%s",a);
		// printf("%s\n",a );
		int l = strlen(a);
		int n = l/c;
		char m[n][c];
		int i=0,j=0,ai=0;
		while(i<n){
			//odd case
			if(i&1){
				j=c-1;
				while(j>-1){
					m[i][j]=a[ai++];
					j--;
				}
			}
			//even case
			else{
				j=0;
				while(j<c){
					m[i][j]=a[ai++];
					j++;
				}
			}
			i++;
		}
		// rep(i,0,n){
		// 	rep(j,0,c) printf("%c ",m[i][j] );
		// 	printf("\n");
		// }
		rep(i,0,c){
			rep(j,0,n) printf("%c",m[j][i]);
		}
		printf("\n");
		scanf("%d",&c);
	}
}