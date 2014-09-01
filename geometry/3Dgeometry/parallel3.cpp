int parallel(line3 l,plane3 s)
{
	return zero(dmult(subt(l.a,l.b),pvec(s)));
}
int parallel(point3 l1,point3 l2,point3 s1,point3 s2,point3 s3)
{
	return zero(dmult(subt(l1,l2),pvec(s1,s2,s3)));
}
