// the code for horrible spoj.
#include <bits/stdc++.h>
using namespace std;

void fast(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
int a[100001],tr[400005], lz[400005];
void build(int n, int s, int e){
	if(s==e){
		tr[n] = a[s];
		return;
	}
	int m = (s+e)>>1;
	build(2*n, s, m);
	build(2*n+1, m+1, e);
	tr[n] = tr[2*n]+tr[2*n+1];
}
// #define cout<<s<<"\t"<<e<<"\t"<<"\n";
void update(int n, int s, int e, int qs, int qe){
	if(lz[n]==1){
		tr[n] = abs(tr[n] - (e-s+1));
		if(s!=e){
			lz[2*n]^=1;
			lz[2*n+1]^=1;
		}
		lz[n]=0;
	}
	// cout<<s<<"\t"<<e<<"\t"<<tr[n]<<"\n";
	// no overlap.
	if(s>e||s>qe||qs>e)
		return;
	if(s >= qs && e<=qe){
		tr[n] = abs(tr[n] - (e-s+1));
		if(s!=e){
			lz[2*n]^=1;
			lz[2*n+1]^=1;
		}
		return;
	}
	int m = (s+e)>>1;
	update(2*n, s, m, qs, qe);
	update(2*n+1, m+1, e, qs, qe);
	tr[n] = tr[2*n] + tr[2*n+1];
}

int query(int n, int s, int e, int qs, int qe){
	if(lz[n]==1){
		tr[n] = abs(tr[n] - (e-s+1));
		if(s!=e){
			lz[2*n]^=1;
			lz[2*n+1]^=1;
		}
		lz[n]=0;
	}
	// cout<<s<<"\t"<<e<<"\t"<<tr[n]<<"\n";
	// no overlap.
	if(s>e||s>qe||qs>e)
		return 0;
	if(s >= qs && e<=qe)
		return tr[n];
	int m = (s+e)>>1;
	int l = query(2*n, s, m, qs, qe);
	int r = query(2*n+1, m+1, e, qs, qe);
	int x = l+r;
	return x;
}

int main(void){
	fast();
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n,m;
	for(int i=0; i<400005; i++){
		tr[i]=lz[i]=0;
	}
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int x,y,z;
		cin>>x>>y>>z;
		if(x==0){
			update(1,1,n,y,z);
			// cout<<query(1,1,n,y,z)<<"\n";
		}
		else{
			cout<<query(1,1,n,y,z)<<"\n";
		}
	}
}