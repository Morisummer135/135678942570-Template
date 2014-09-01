#include <bits/stdc++.h>
using namespace std;
const double eps=1e-12;
const double pi=acos(-1.0);
struct point
{
    double x,y;
    point(double _x=0,double _y=0)
    {
        x=_x;
        y=_y;
    };
    point(point s,point e)
    {
        x=e.x-s.x;
        y=e.y-s.y;
    };
    double length()
    {
        return sqrt(x*x+y*y);
    }
};
struct circle
{
    point c;
    double r;
};
struct event
{
    double tim;
    int typ;
    event(double _tim=0,int _typ=0)
    {
        tim=_tim;
        typ=_typ;
    }
};
int cmp(const double &a,const double &b)
{
    if(fabs(a-b)<eps)
        return 0;
    if(a<b)
        return -1;
    return 1;
}
bool eventcmp(const event &a,const event &b)
{
    return cmp(a.tim,b.tim)<0;
}
double area(double theta,double r)
{
    return 0.5*r*r*(theta-sin(theta));
}
double xmult(point a,point b)
{
    return a.x*b.y-a.y*b.x;
}
int n,cur,tote;
circle c[1001];
double ans[1011],pre[1011],AB,AC,BC,theta,fai,a0,a1;
event e[4004];
point lab;
int N;
bool del[1100];
void calc()
{
    for(int i=0;i<n;i++)
        del[i]=0;
    for(int i=0;i<n;i++)
        if(del[i]==0)
        {
            for(int j=0;j<n;j++)
                if(i!=j)
                {
                    if(del[j]==0)
                        if(cmp(point(c[i].c,c[j].c).length()+c[j].r,c[i].r)<=0)
                            del[j]=1;
                }
        }
    int tn=n;
    n=0;
    for(int i=0;i<tn;i++)
        if(del[i]==0)
            c[n++]=c[i];
    for(int i=1;i<=tn;i++)
        ans[i]=0.0;
    for(int i=0;i<n;i++)
    {
        tote=0;
        e[tote++]=event(-pi,1);
        e[tote++]=event(pi,-1);
        for(int j=0;j<n;j++)
            if(j!=i)
            {
                lab=point(c[j].c.x-c[i].c.x,c[j].c.y-c[i].c.y);
                AB=lab.length();
                AC=c[i].r;
                BC=c[j].r;
                if(cmp(AB+AC,BC)<=0)
                {
                    e[tote++]=event(-pi,1);
                    e[tote++]=event(pi,-1);
                    continue;
                }
                if(cmp(AB+BC,AC)<=0)
                    continue;
                if(cmp(AB,AC+BC)>0)
                    continue;
                theta=atan2(lab.y,lab.x);
                fai=acos((AC*AC+AB*AB-BC*BC)/(2.0*AC*AB));
                a0=theta-fai;
                if(cmp(a0,-pi)<0) a0+=2*pi;
                a1=theta+fai;
                if(cmp(a1,pi)>0) a1-=2*pi;
                if(cmp(a0,a1)>0)
                {
                    e[tote++]=event(a0,1);
                    e[tote++]=event(pi,-1);
                    e[tote++]=event(-pi,1);
                    e[tote++]=event(a1,-1);
                }
                else
                {
                    e[tote++]=event(a0,1);
                    e[tote++]=event(a1,-1);
                }
            }
        sort(e,e+tote,eventcmp);
        cur=0;
        for(int j=0;j<tote;j++)
        {
            if(cur!=0&&cmp(e[j].tim,pre[cur])!=0)
            {
                ans[cur]+=area(e[j].tim-pre[cur],c[i].r);
                ans[cur]+=xmult(point(c[i].c.x+c[i].r*cos(pre[cur]),c[i].c.y+c[i].r*sin(pre[cur])),
                                point(c[i].c.x+c[i].r*cos(e[j].tim),c[i].c.y+c[i].r*sin(e[j].tim)))/2.0;
            }
            cur+=e[j].typ;
            pre[cur]=e[j].tim;
        }
    }
    printf("%.3f\n",ans[1]);
    for(int i=1;i<n;i++)
        ans[i]-=ans[i+1];
}
int main()
{
    while(scanf("%d",&n)>0)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf%lf",&c[i].c.x,&c[i].c.y,&c[i].r);
        }
        calc();
    }
}
