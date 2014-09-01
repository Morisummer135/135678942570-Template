double disptoseg(point p,line l)
{
	point t=p;
	t.x+=l.a.y-l.b.y,t.y+=l.b.x-l.a.x;
	if (xmult(l.a,t,p)*xmult(l.b,t,p)>eps)
		return distance(p,l.a)<distance(p,l.b)?distance(p,l.a):distance(p,l.b);
	return fabs(xmult(p,l.a,l.b))/distance(l.a,l.b);
}
double disptoseg(point p,point l1,point l2)
{
	point t=p;
	t.x+=l1.y-l2.y,t.y+=l2.x-l1.x;
	if (xmult(l1,t,p)*xmult(l2,t,p)>eps)
		return distance(p,l1)<distance(p,l2)?distance(p,l1):distance(p,l2);
	return fabs(xmult(p,l1,l2))/distance(l1,l2);
}
