#include <bits/stdc++.h>
using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	int t;
	scanf("%d",&t);
	int n,d;
	while(t--){
		scanf("%d",&n);
		scanf("%d",&d);
		if(d)
			printf("Pagfloyd wins.\n");
		else
			printf("Airborne wins.\n");
	}
}