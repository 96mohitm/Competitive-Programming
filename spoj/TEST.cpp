#include <iostream>

using namespace std;

int main()
{
	int a,b[99999],c;
	for(a=0;a>=0;a++){
	cin>>b[a];
	if(b[a-1]==42)break;
	}
	for(c=0;c<a-1;c++){
	cout<<b[c]<<endl;
	}
	return 0;
}
