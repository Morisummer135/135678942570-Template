point3 pvec(plane3 s)
{
	return xmult(subt(s.a,s.b),subt(s.b,s.c));
}
point3 pvec(point3 s1,point3 s2,point3 s3)
{
	return xmult(subt(s1,s2),subt(s2,s3));
}
