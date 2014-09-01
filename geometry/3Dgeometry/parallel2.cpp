int parallel(plane3 u,plane3 v)
{
	return vlen(xmult(pvec(u),pvec(v)))<eps;
}
int parallel(point3 u1,point3 u2,point3 u3,point3 v1,point3 v2,point3 v3)
{
	return vlen(xmult(pvec(u1,u2,u3),pvec(v1,v2,v3)))<eps;
}
