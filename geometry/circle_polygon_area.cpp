#include <bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;
const double eps=1e-10;
inline double max(double a,double b)
{
	if(a>b)
		return a;
	return b;
}
inline double min(double a,double b)
{
	if(a>b)
		return b;
	return a;
}
inline int fi(double a)
{
	if(a>eps)
		return 1;
	else if(a>=-eps)return 0;
	return -1;
}
class vector
{
	public:
	double x,y;
	vector(){}
	vector(double x0,double y0)
	{
		x=x0,y=y0;
	}
	double operator *(const vector& a) const
	{
		return x*a.y-y*a.x;
	}
	double operator %(const vector& a) const
	{
		return x*a.x+y*a.y;
	}
	vector verti() const
	{
		return vector(-y,x);
	}
	double length() const
	{
		return sqrt(x*x+y*y);
	}
	vector adjust(double len)
	{
		double o1=len/length();
		return vector(x*o1,y*o1);
	}
	vector oppose()
	{
		return vector(-x,-y);
	}
};
class point
{
public:
	double x,y;
	point (){}
	point (double x0,double y0)
	{
		x=x0,y=y0;
	}
	vector operator -(const point& a) const
	{
		return vector(x-a.x,y-a.y);
	}
	point operator +(const vector& a) const
	{
		return point(x+a.x,y+a.y);
	}
};
class segment
{
	public:
	point a,b;
	segment(){}
	segment(point a0,point b0)
	{
		a=a0,b=b0;
	}
	point intersert(const segment& s) const
	{
		vector v1=s.a-a,v2=s.b-a,v3=s.b-b,v4=s.a-b;
		double s1=v1*v2,s2=v3*v4;
		double se=s1+s2;
		s1/=se;
		s2/=se;
		return point(a.x*s2+b.x*s1,a.y*s2+b.y*s1);
	}
	point pverti(const point& p) const
	{
		vector t=(b-a).verti();
		segment uv(p,p+t);
		return intersert(uv);
	}
	bool on_seg(const point &p) const
	{
		if(fi(min(a.x,b.x)-p.x)<=0&&fi(p.x-max(a.x,b.x))<=0&&
			fi(min(a.y,b.y)-p.y)<=0&&fi(p.y-max(a.y,b.y))<=0)return true;
		else return false;
	}
};
double radius;
point polygon[10];
double kuras_area(point a,point b,point cir)
{
	point ori=point(cir.x,cir.y);
	// printf("%.2f %.2f\n",cir.x,cir.y);
	int sgn=fi((b-ori)*(a-ori));
	double da=(a-ori).length(),db=(b-ori).length();
	// printf("%.2f %.2f\n",da,db);
	int ra=fi(da-radius),rb=fi(db-radius);
	double angle = acos(((b-ori)%(a-ori))/(da*db));
	// printf("%.2f\n",angle);
	segment t(a,b); point h,u; vector seg;
	double ans,dlt,mov,tangle;
	if(fi(da)==0||fi(db)==0)
		return 0;
	else if(sgn==0)
		return 0;
	else if(ra<=0&&rb<=0)
		return fabs((b-ori)*(a-ori))/2*sgn;
	else if(ra>=0&&rb>=0)
	{
		h=t.pverti(ori);
		dlt=(h-ori).length();
		if(!t.on_seg(h)||fi(dlt-radius)>=0)
			return radius*radius*(angle/2)*sgn;
		else
		{
			ans=radius*radius*(angle/2);
			tangle=acos(dlt/radius);
			ans-=radius*radius*tangle;
			ans+=radius*sin(tangle)*dlt;
			// printf("%.2f\n",ans);
			return ans*sgn;
		}
	}
	else
	{
		h=t.pverti(ori);
		dlt=(h-ori).length();
		seg=b-a;
		mov=sqrt(radius*radius-dlt*dlt);
		seg=seg.adjust(mov);
		if(t.on_seg(h+seg)) u=h+seg;
		else u=h+seg.oppose();
		if(ra==1) swap(a,b);
		ans=fabs((a-ori)*(u-ori))/2;
		tangle=acos(((u-ori)%(b-ori))/((u-ori).length()*(b-ori).length()));
		ans+=radius*radius*(tangle/2);
		return ans*sgn;
	}
}	
int main()
{
	int cas=0;
	double x1,x2,x3,y1,y2,y3;
	while(scanf("%lf%lf%lf",&x1,&y1,&radius)>0)
	{
		if(cas++)
			puts("");
		scanf("%lf%lf%lf%lf",&x2,&y2,&x3,&y3);
		polygon[0]=point(x2,y2);
		polygon[3]=point(x2,y3);
		polygon[2]=point(x3,y3);
		polygon[1]=point(x3,y2);
		double area=0;
		for(int i=0;i<4;i++)
		{
			area+=kuras_area(polygon[i],polygon[(i+1)%4],point(x1,y1));
		}
		printf("%.16f\n",fabs(area));
	}
}
