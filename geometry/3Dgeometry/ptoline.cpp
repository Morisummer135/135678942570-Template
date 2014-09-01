double ptoline(point3 p,line3 l)
{
	return vlen(xmult(subt(p,l.a),subt(l.b,l.a)))/dist3(l.a,l.b);
}
double ptoline(point3 p,point3 l1,point3 l2)
{
	return vlen(xmult(subt(p,l1),subt(l2,l1)))/dist3(l1,l2);
}
