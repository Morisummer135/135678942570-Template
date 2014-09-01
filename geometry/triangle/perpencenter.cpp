point perpencenter(point a,point b,point c)
{
	line u,v;
	u.a=c;
	u.b.x=u.a.x-a.y+b.y;
	u.b.y=u.a.y+a.x-b.x;
	v.a=b;
	v.b.x=v.a.x-a.y+c.y;
	v.b.y=v.a.y+a.x-c.x;
	return intersection(u,v);
}
