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
	map<pair<int, int>, int> a;
	int i=0,j=0,k=1;
	a[{0,0}] = 0;
	while(i<=10000||j<=10000){
		i++;j++;
		a.insert(make_pair(make_pair(i,j),k++));
		// a[i,j] = k++;
		i++;j--;
		a.insert(make_pair(make_pair(i,j),k++));
		i++;j++;
		a.insert(make_pair(make_pair(i,j),k++));
		i--;j++;
		a.insert(make_pair(make_pair(i,j),k++));
	}
	int t,x,y;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&x,&y);
		if(x==0&&y==0) printf("0\n");
		else if(a[{x,y}]==0) printf("No Number\n");
		else printf("%d\n",a[{x,y}]);
	}
}
