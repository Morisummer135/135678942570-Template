int same_side(point p1,point p2,line l)
{
	return xmult(l.a,p1,l.b)*xmult(l.a,p2,l.b)>eps;
}
int same_side(point p1,point p2,point l1,point l2)
{
	return xmult(l1,p1,l2)*xmult(l1,p2,l2)>eps;
}
