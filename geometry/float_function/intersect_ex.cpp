int intersect_ex(line u,line v)
{
	return opposite_side(u.a,u.b,v)&&opposite_side(v.a,v.b,u);
}
int intersect_ex(point u1,point u2,point v1,point v2)
{
	return opposite_side(u1,u2,v1,v2)&&opposite_side(v1,v2,u1,u2);
}
