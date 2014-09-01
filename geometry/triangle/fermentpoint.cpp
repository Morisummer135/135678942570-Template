point fermentpoint(point a,point b,point c)
{
	point u,v;
	double step=fabs(a.x)+fabs(a.y)+fabs(b.x)+fabs(b.y)+fabs(c.x)+fabs(c.y);
	int i,j,k;
	u.x=(a.x+b.x+c.x)/3;
	u.y=(a.y+b.y+c.y)/3;
	while (step>1e-10)
		for (k=0;k<10;step/=2,k++)
			for (i=-1;i<=1;i++)
				for (j=-1;j<=1;j++)
				{
					v.x=u.x+step*i;
					v.y=u.y+step*j;
					if (distance(u,a)+distance(u,b)+distance(u,c)>distance(v,a)+distance(v,b)+distance(v,c))
						u=v;
				}
	return u;
}
