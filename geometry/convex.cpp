#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define maxn 100000
struct point{double x,y;}a[maxn],b[maxn];
int top;
int N;
point vex[maxn];
bool cmp(const point &x,const point &y)
{
	if(x.y==y.y) return x.x<y.x;
	return x.y<y.y;
}
double xmult(point a,point b,point c){return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);}
void convex(int n,point P[])
{
	sort(P,P+n,cmp);
	vex[0]=P[0];
	vex[1]=P[1];
	top=1;
	for(int i=2;i<n;i++)
	{
		while(top&&xmult(vex[top],vex[top-1],P[i])<=0) top--;
		vex[++top]=P[i];
	}
	int len=top;
	vex[++top]=P[n-2];
	for(int i=n-3;i>=0;i--)
	{
		while(top!=len&&xmult(vex[top],vex[top-1],P[i])<=0) top--;
		vex[++top]=P[i];
	}
}
double cha(point a,point b)
{
	return a.x*b.y-b.x*a.y;
}
double dian(point a,point b,point c)
{
    return (c.x-b.x)*(a.x-b.x)+(c.y-b.y)*(a.y-b.y);
}
bool pan(point a,point b,point c)
{
    if(dian(a,b,c)>0&&dian(c,a,b)>0)
        return 1;
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%lf%lf",&a[i].x,&a[i].y);
            b[i]=a[i];
        }
        convex(N,b);
        double are=0;
        for(int i=0;i<N;i++)
        {
            are+=cha(a[i],a[(i+1)%N]);
          //  printf("%f\n",are);
        }
        are/=2.0;//fabs(are)/2.0;
        point zhong;
        zhong.x=0;
        zhong.y=0;
        for(int i=0;i<N;i++)
            zhong.x+=(a[i].x+a[(i+1)%N].x)*cha(a[i],a[(i+1)%N]);
        for(int i=0;i<N;i++)
            zhong.y+=(a[i].y+a[(i+1)%N].y)*cha(a[i],a[(i+1)%N]);
        zhong.x/=(6.0*are);
        zhong.y/=(6.0*are);
    }
}
