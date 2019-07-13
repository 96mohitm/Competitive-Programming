#include <bits/stdc++.h>
using namespace std;
 
typedef long long  ll;

void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int main(void){
	fast();
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif

	int n;
	while(cin>>n){
		// first of all make a priority queue
		priority_queue<int> l, r;
		l.push(n);
		cin>>n;
		while(n!=0){
			if(n==-1){
				cout<<l.top()<<"\n";
				l.pop();
				while(l.size() > r.size()+1){
					r.push(-l.top()), l.pop();
				}
				while(r.size() > l.size())
					l.push(-r.top()), r.pop();

			}
			else{
				if(!l.empty() && l.top() < n){
					r.push(-n);
				}
				else{
					l.push(n);
				}
				while(l.size() > r.size()+1){
					r.push(-l.top()), l.pop();
				}
				while(r.size() > l.size())
					l.push(-r.top()), r.pop();
			}
			cin>>n;
		}
		cout<<"\n";
	}
}
