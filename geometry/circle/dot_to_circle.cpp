point dot_to_circle(point c,double r,point p)
{
	point u,v;
	if (distance(p,c)<eps)
		return p;
	u.x=c.x+r*fabs(c.x-p.x)/distance(c,p);
	u.y=c.y+r*fabs(c.y-p.y)/distance(c,p)*((c.x-p.x)*(c.y-p.y)<0?-1:1);
	v.x=c.x-r*fabs(c.x-p.x)/distance(c,p);
	v.y=c.y-r*fabs(c.y-p.y)/distance(c,p)*((c.x-p.x)*(c.y-p.y)<0?-1:1);
	return distance(u,p)<distance(v,p)?u:v;
}
