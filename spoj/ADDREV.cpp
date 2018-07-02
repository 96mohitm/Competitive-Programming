#include <iostream>

using namespace std;

int reverse(int n){
	int r,rn=0;
	while(n>0){
		r=n%10;
		rn=(rn*10)+r;
		n=n/10;
	}
	return rn;
}

int main(){
	int t,n,a,b,sum;
	cin>>t;
	while(t--){
		cin>>a>>b;
		a=reverse(a);
		b=reverse(b);
		sum=a+b;
		sum= reverse(sum);
		cout<<sum<<endl;
	}
	return 0;
}