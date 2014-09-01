int dots_inline(point p1,point p2,point p3)
{
	return zero(xmult(p1,p2,p3));
}
int dots_inline(double x1,double y1,double x2,double y2,double x3,double y3)
{
	return zero(xmult(x1,y1,x2,y2,x3,y3));
}
