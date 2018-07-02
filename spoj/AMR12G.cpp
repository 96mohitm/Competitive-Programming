#include <bits/stdc++.h>
#define rep(i, a, b) \
for( i = int(a); i< int(b); i++)

using namespace std;
typedef vector<int> vi;

int main(void){
	int t,n,m,k,i,j;
	scanf("%d",&t);
	while(t--){
		// scanf("%d%d%d",&n,&m,&k);
		cin>>n>>m>>k;
		vi v(n, 0);
		char a;
		rep(i,0,n){
			rep(j,0,m){
				// scanf("%c",&a);
				cin>>a;
				if(a=='*') v[i]++;
			}
		}
		sort(v.begin(), v.end());
		j=0;
		while(k>0&&m-v[j]>v[j]&&j<n){
			k--;
			v[j]=m-v[j];
			j++;
		}
		if(k&&k%2){
			auto it = min_element(v.begin(), v.end());
			*it = m-*it;
		}
		// printf("%d\n",accumulate(v.begin(), v.end(), 0) );
		cout<<accumulate(v.begin(), v.end(), 0)<<"\n";
	}
}