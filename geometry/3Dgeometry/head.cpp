#include <math.h>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point3{double x,y,z;};
struct line3{point3 a,b;};
struct plane3{point3 a,b,c;};

point3 xmult(point3 u,point3 v)
{
	point3 ret;
	ret.x=u.y*v.z-v.y*u.z;
	ret.y=u.z*v.x-u.x*v.z;
	ret.z=u.x*v.y-u.y*v.x;
	return ret;
}

double dmult(point3 u,point3 v)
{
	return u.x*v.x+u.y*v.y+u.z*v.z;
}

point3 subt(point3 u,point3 v)
{
	point3 ret;
	ret.x=u.x-v.x;
	ret.y=u.y-v.y;
	ret.z=u.z-v.z;
	return ret;
}

double dist3(point3 p1,point3 p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z));
}

double vlen(point3 p)
{
	return sqrt(p.x*p.x+p.y*p.y+p.z*p.z);
}
