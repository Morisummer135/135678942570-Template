int dots_inline(point3 p1,point3 p2,point3 p3)
{
	return vlen(xmult(subt(p1,p2),subt(p2,p3)))<eps;
}
