#include <cstdio>
#include <algorithm>
#include <cmath>
const double eps=1e-8;
using namespace std;
struct point
{
	double x,y;
	point(){}
	point(double x,double y)
	{
		this->x=x;
		this->y=y;
	}
	point operator -(const point &b) const
	{
		return point(x-b.x,y-b.y);
	}
	double operator *(const point &b) const
	{
		return x*b.y-y*b.x;
	}
};
struct line
{
	point s,e;
	double k;
	line(point a=point(),point b=point())
	{
		s=a,e=b;
		k=atan2(e.y-s.y,e.x-s.x);
	}
	point operator &(const line &b) const
	{
		point res=s;
		double t=((s-b.s)*(b.s-b.e))/((s-e)*(b.s-b.e));
		res.x+=(e.x-s.x)*t;
		res.y+=(e.y-s.y)*t;
		return res;
	}
};
line Q[1101];
double xmult(point p0,point p1,point p2)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
bool HPIcmp(line a,line b)
{
	if(fabs(a.k-b.k)>eps)
		return a.k<b.k;
	return ((a.s-b.s)*(b.e-b.s))<0;
}
void HPI(line L[],int n,point res[],int &resn)
{
	int tot=n;
	sort(L,L+n,HPIcmp);
	tot=1;
	for(int i=1;i<n;i++)
		if(fabs(L[i].k-L[i-1].k)>eps)
			L[tot++]=L[i];
	int head=0,tail=1;
	Q[0]=L[0];
	Q[1]=L[1];
	resn=0;
	for(int i=2;i<tot;i++)
	{
		if(fabs((Q[tail].e-Q[tail].s)*(Q[tail-1].e-Q[tail-1].s))<eps
			||fabs((Q[head].e-Q[head].s)*(Q[head+1].e-Q[head+1].s))<eps)
			return;
		while(head<tail&&(((Q[tail]&Q[tail-1])-L[i].s)*(L[i].e-L[i].s))>eps)
			tail--;
		while(head<tail&&(((Q[head]&Q[head+1])-L[i].s)*(L[i].e-L[i].s))>eps)
			head++;
		Q[++tail]=L[i];
	}
	while(head<tail&&(((Q[tail]&Q[tail-1])-Q[head].s)*(Q[head].e-Q[head].s))>eps)
		tail--;
	while(head<tail&&(((Q[head]&Q[head+1])-Q[tail].s)*(Q[tail].e-Q[tail].s))>eps)
		head++;
	if(tail<=head+1)
		return;
	for(int i=head;i<tail;i++)
		res[resn++]=Q[i]&Q[i+1];
	if(head<tail+1)
		res[resn++]=Q[head]&Q[tail];
}
int main()
{
	// fop;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		point P[1011];
		for(int i=0;i<n;i++)
			scanf("%lf%lf",&P[i].x,&P[i].y);
		int dir=0;
		double sum=0;
		for(int i=0;i<n;i++)
			sum+=xmult(P[i],P[(i+1)%n],P[(i+2)%n]);
		if(sum<0) dir=0;
		else dir=1;
		line LL[1011];
		if(dir)
			for(int i=0;i<n;i++)
				LL[i]=line(P[i],P[(i+1)%n]);
		else for(int i=n-1;i>=0;i--)
				LL[i]=line(P[i],P[(i-1+n)%n]);
		point res[1011];
		int resn=0;
		HPI(LL,n,res,resn);
		puts(resn?"YES":"NO");
	}
}
