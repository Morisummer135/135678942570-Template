int parallel(line3 u,line3 v)
{
	return vlen(xmult(subt(u.a,u.b),subt(v.a,v.b)))<eps;
}
int parallel(point3 u1,point3 u2,point3 v1,point3 v2)
{
	return vlen(xmult(subt(u1,u2),subt(v1,v2)))<eps;
}
