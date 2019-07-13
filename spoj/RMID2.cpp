#include <bits/stdc++.h>
using namespace std;

void fast(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main(void){
	fast();
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		priority_queue<int> l,r;
		while(n!=0){
			if(n==-1){
				cout<<l.top()<<"\n";
				l.pop();
			}
			else{
				if(!l.empty() && l.top() < n)
					r.push(-n);
				else
					l.push(n);
			}
			while(l.size() > r.size() +1)
				r.push(-l.top()), l.pop();
			while(r.size() > l.size())
				l.push(-r.top()), r.pop();
			cin>>n;
		}
	}
}