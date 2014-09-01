double disptoline(point p,line l)
{
	return fabs(xmult(p,l.a,l.b))/distance(l.a,l.b);
}
double disptoline(point p,point l1,point l2)
{
	return fabs(xmult(p,l1,l2))/distance(l1,l2);
}
double disptoline(double x,double y,double x1,double y1,double x2,double y2)
{
	return fabs(xmult(x,y,x1,y1,x2,y2))/distance(x1,y1,x2,y2);
}
