int intersect_line_circle(point c,double r,point l1,point l2)
{
	return disptoline(c,l1,l2)<r+eps;
}
