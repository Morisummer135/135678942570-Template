int inside_convex_v2(point q,int n,point* p)
{
	int i,s[3]={1,1,1};
	for (i=0;i<n&&s[0]&&s[1]|s[2];i++)
		s[_sign(xmult(p[(i+1)%n],q,p[i]))]=0;
	return s[0]&&s[1]|s[2];
}
