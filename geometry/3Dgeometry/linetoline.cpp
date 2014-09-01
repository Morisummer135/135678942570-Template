double linetoline(line3 u,line3 v)
{
	point3 n=xmult(subt(u.a,u.b),subt(v.a,v.b));
	return fabs(dmult(subt(u.a,v.a),n))/vlen(n);
}
double linetoline(point3 u1,point3 u2,point3 v1,point3 v2)
{
	point3 n=xmult(subt(u1,u2),subt(v1,v2));
	return fabs(dmult(subt(u1,v1),n))/vlen(n);
}
