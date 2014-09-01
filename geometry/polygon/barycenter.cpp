point intersection(line u,line v)
{
	point ret=u.a;
	double t=((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))
			/((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
	ret.x+=(u.b.x-u.a.x)*t;
	ret.y+=(u.b.y-u.a.y)*t;
	return ret;
}

point barycenter(point a,point b,point c)
{
	line u,v;
	u.a.x=(a.x+b.x)/2;
	u.a.y=(a.y+b.y)/2;
	u.b=c;
	v.a.x=(a.x+c.x)/2;
	v.a.y=(a.y+c.y)/2;
	v.b=b;
	return intersection(u,v);
}

//多边形重心
point barycenter(int n,point* p)
{
	point ret,t;
	double t1=0,t2;
	int i;
	ret.x=ret.y=0;
	for (i=1;i<n-1;i++)
		if (fabs(t2=xmult(p[0],p[i],p[i+1]))>eps){
			t=barycenter(p[0],p[i],p[i+1]);
			ret.x+=t.x*t2;
			ret.y+=t.y*t2;
			t1+=t2;
		}
	if (fabs(t1)>eps)
		ret.x/=t1,ret.y/=t1;
	return ret;
}
