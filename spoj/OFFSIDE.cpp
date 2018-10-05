#include <bits/stdc++.h>
using namespace std;
int main(void){
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	int a,d;
	scanf("%d%d",&a,&d);
	while(a){
		int f[a],s[d];
		for(int i=0;i<a;i++)
			scanf("%d",&f[i]);
		for(int i=0;i<d;i++)
			scanf("%d",&s[i]);
		sort(f,f+a);
		sort(s,s+d);
		if(f[0]>=s[1])
			printf("N\n");
		else
			printf("Y\n");
		scanf("%d%d",&a,&d);
	}
}