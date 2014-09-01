int intersect_circle_circle(point c1,double r1,point c2,double r2)
{
	return distance(c1,c2)<r1+r2+eps&&distance(c1,c2)>fabs(r1-r2)-eps;
}
