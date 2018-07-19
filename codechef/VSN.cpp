#include <bits/stdc++.h>
using namespace std;
 
int main(void){
	int t;
	scanf("%d",&t);
	double px, py, pz, qx, qy, qz, dx, dy, dz, cx, cy, cz, r,a,b,c,d,e,f,na,nb,nc,ng,rs,as,asn;
	while(t--){
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&px,&py,&pz,&qx,&qy,&qz,&dx,&dy,&dz,&cx,&cy,&cz,&r);
		d = (dx*dx);
		d+=(dy*dy);
		d+= (dz*dz);
		f = ((qx-px)*dx);
		f+= (qy-py)*dy;
		f+= (qz-pz)*dz;
		f=f*2;
		e = (qx-px)*(qx-px) ;
		e+= (qy-py)*(qy-py) ;
		e+= (qz-pz)*(qz-pz);
		b = dx*(px-cx) ;
		b+= dy*(py-cy);
		b += dz*(pz-cz);
		a = (qx-px)*(px-cx) ;
		a+= (qy-py)*(py-cy) ;
		a+= (qz-pz)*(pz-cz);
		c = (cx-px)*(cx-px) ;
		c+= (cy-py)*(cy-py);
		c += (cz-pz)*(cz-pz) - (r*r);
		na = (b*b)-(c*d);
    	nb = ((2*a)*b)-(c*f);
       	nc = (a*a)-(c*e);
      	ng = sqrt((nb*nb)-(4*na*nc));
 
      	if(!na){
      		rs=(-nc)/nb;
      	}
      	else{
      		 as = ((-nb)+(ng))/(2*na);
      		 asn = ((-nb)-(ng))/(2*na);
      		  if(!(as < 0) && !(asn < 0))
      		   rs = (as < asn) ? as : asn;
      		  else if(!(as > 0) && !(asn < 0))
      		   rs = asn;
      		  else if(!(as < 0) && !(asn > 0))
      		   rs = as;
 
      	}
      	printf("%lf\n",rs );
	}
} 
