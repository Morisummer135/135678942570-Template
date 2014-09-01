int perpendicular(line3 l,plane3 s)
{
	return vlen(xmult(subt(l.a,l.b),pvec(s)))<eps;
}
int perpendicular(point3 l1,point3 l2,point3 s1,point3 s2,point3 s3)
{
	return vlen(xmult(subt(l1,l2),pvec(s1,s2,s3)))<eps;
}
