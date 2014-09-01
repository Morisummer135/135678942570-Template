//on_edge表示点在多边形边上时的返回值,offset为多边形坐标上限
int inside_polygon(point q,int n,point* p,int on_edge=1)
{
	point q2;
	int i=0,count;
	while (i<n)
		for (count=i=0,q2.x=rand()+offset,q2.y=rand()+offset;i<n;i++)
			if (zero(xmult(q,p[i],p[(i+1)%n]))&&(p[i].x-q.x)*(p[(i+1)%n].x-q.x)<eps&&(p[i].y-q.y)*(p[(i+1)%n].y-q.y)<eps)
				return on_edge;
			else if (zero(xmult(q,q2,p[i])))
				break;
			else if (xmult(q,p[i],q2)*xmult(q,p[(i+1)%n],q2)<-eps&&xmult(p[i],q,p[(i+1)%n])*xmult(p[i],q2,p[(i+1)%n])<-eps)

				count++;
	return count&1;
}
