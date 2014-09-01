point incenter(point a,point b,point c)
{
	line u,v;
	double m,n;
	u.a=a;
	m=atan2(b.y-a.y,b.x-a.x);
	n=atan2(c.y-a.y,c.x-a.x);
	u.b.x=u.a.x+cos((m+n)/2);
	u.b.y=u.a.y+sin((m+n)/2);
	v.a=b;
	m=atan2(a.y-b.y,a.x-b.x);
	n=atan2(c.y-b.y,c.x-b.x);
	v.b.x=v.a.x+cos((m+n)/2);
	v.b.y=v.a.y+sin((m+n)/2);
	return intersection(u,v);
}
