#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(void){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	scanf("%d",&n);
	while(n){
		vector<int> v(n);
		for(int i =0;i<n;i++)
			scanf("%d",&v[i]);
		sort(v.begin(), v.end());
		int r=0;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				int x = v[i]+v[j];
				auto it = upper_bound(v.begin(), v.end(), x) - v.begin();
				it = n - it;
				r+=it;
			}
		}
		printf("%d\n",r );
		scanf("%d",&n);
	}
}
