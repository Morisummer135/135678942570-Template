#include <math.h>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point
{
	double x,y;
	point(double a=0.0,b=0.0)
	{
		x=a,y=b;
	}
};
struct line
{
	point a,b;
	line(point s=point(),point e=point())
	{
		a=s,b=e;
	}
};
double xmult(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
double xmult(double x1,double y1,double x2,double y2,double x0,double y0)
{
	return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}
double dmult(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
}
double dmult(double x1,double y1,double x2,double y2,double x0,double y0)
{
	return (x1-x0)*(x2-x0)+(y1-y0)*(y2-y0);
}
