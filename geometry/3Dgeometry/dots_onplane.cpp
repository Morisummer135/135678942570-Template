int dots_onplane(point3 a,point3 b,point3 c,point3 d)
{
	return zero(dmult(pvec(a,b,c),subt(d,a)));
}
