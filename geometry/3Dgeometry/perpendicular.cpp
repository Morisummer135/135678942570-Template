int perpendicular(line3 u,line3 v)
{
	return zero(dmult(subt(u.a,u.b),subt(v.a,v.b)));
}
int perpendicular(point3 u1,point3 u2,point3 v1,point3 v2)
{
	return zero(dmult(subt(u1,u2),subt(v1,v2)));
}
