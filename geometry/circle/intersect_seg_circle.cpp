int intersect_seg_circle(point c,double r,point l1,point l2)
{
	double t1=distance(c,l1)-r,t2=distance(c,l2)-r;
	point t=c;
	if (t1<eps||t2<eps)
		return t1>-eps||t2>-eps;
	t.x+=l1.y-l2.y;
	t.y+=l2.x-l1.x;
	return xmult(l1,c,t)*xmult(l2,c,t)<eps&&disptoline(c,l1,l2)-r<eps;
}
