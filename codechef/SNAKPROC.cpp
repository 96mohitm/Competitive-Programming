#include <bits/stdc++.h>
using namespace std;
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int r=1;
		int tail =0, head=1;
		for(int i=0;i<n;i++){
			if(s[i]=='.')
				continue;
			else if(s[i]=='H'){
				if(tail)
					r=0;
				else{
					head=0;tail=1;
				}
			}
			else if(s[i]=='T'){
				if(head)
					r=0;
				else{
					tail=0;head=1;
				}
			}
		}
		if(tail)
			r=0;
		if(r)
			cout<<"Valid\n";
		else
			cout<<"Invalid\n";
	}
}