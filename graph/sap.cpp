#include <bits/stdc++.h>
using namespace std;
int m;
struct Edge
{
    int en,cap,flow,next;
} edge[E];
int head[N] , tot , now[N];
int source,sink,tot_num;
int pre[N] , dis[N] , gap[N];
int n;
struct node
{
     int x,y,z,f,l;
}p[122];
void add(int st,int en,int cap)
{
    edge[tot].en=en;
    edge[tot].cap=cap;
    edge[tot].flow=0;
    edge[tot].next=head[st];
    head[st]=tot++;

    edge[tot].en=st;
    edge[tot].cap=0;
    edge[tot].flow=0;
    edge[tot].next=head[en];
    head[en]=tot++;
}

void augment(int flow)
{
    for(int i=source;i!=sink;i=edge[now[i]].en)
    {
        edge[now[i]].flow+=flow;
        edge[now[i]^1].flow-=flow;
    }
}
int summ=0;
int sap()
{
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    memset(pre,-1,sizeof(pre));
    for(int i=0;i<tot_num;i++)
        now[i]=head[i];
    gap[0]=tot_num;
    int point=source,flow=0,min_flow=INT_INF;
    while(dis[source]<tot_num)
    {
        bool fg=false;
        for(int i=now[point];i!=-1;i=edge[i].next)
            if(edge[i].cap-edge[i].flow>0 && dis[point]==dis[edge[i].en]+1)
            {
                min_flow=min(min_flow,edge[i].cap-edge[i].flow);
                now[point]=i;
                pre[edge[i].en]=point;
                point=edge[i].en;
                if(point==sink)
                {
                    flow+=min_flow;
                    augment(min_flow);
                    point=source;
                    min_flow=INT_INF;
                }
                fg=true;
                break;
            }
        if(fg) continue;
        if(--gap[dis[point]]==0) break;
        int Min=tot_num;
        for(int i=head[point];i!=-1;i=edge[i].next)
            if(edge[i].cap-edge[i].flow>0 && Min>dis[edge[i].en])
            {
                Min=dis[edge[i].en];
                now[point]=i;
            }
        gap[dis[point]=Min+1]++;
        if(point!=source) point=pre[point];
    }
    return flow;
}
int main()
{
  	while(scanf("%d%d",&m,&n)>0)
  	{
        tot=0;
        source=0;
        sink=n-1;
        tot_num=n;
        memset(head,-1,sizeof(head));
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add(a-1,b-1,c);
        }
        printf("%d\n",sap());
    }
}