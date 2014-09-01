using namespace std;
struct Edge
{
    int st,en,cap,flow,cost,next;
} edge[E];
int head[N] , tot , now[N];
int source,sink;
int pre[N] , dis[N];
queue<int> q;
bool vs[N];

void add(int st,int en,int cap,int cost)
{
    edge[tot].st=st;
    edge[tot].en=en;
    edge[tot].cap=cap;
    edge[tot].flow=0;
    edge[tot].cost=cost;
    edge[tot].next=head[st];
    head[st]=tot++;

    edge[tot].st=en;
    edge[tot].en=st;
    edge[tot].cap=0;
    edge[tot].flow=0;
    edge[tot].cost=-cost;
    edge[tot].next=head[en];
    head[en]=tot++;
}

bool SPFA()
{
    for(int i=0; i<N; i++)
        dis[i]=INF;
    memset(vs,0,sizeof(vs));
    memset(now,-1,sizeof(now));
    while(!q.empty()) q.pop();
    q.push(source); dis[source]=0; vs[source]=1;
    while(!q.empty())
    {
        int u=q.front(); q.pop(); vs[u]=0;
        for(int i=head[u],v; i!=-1; i=edge[i].next)
            if(edge[i].cap-edge[i].flow>0 && dis[v=edge[i].en]>dis[u]+edge[i].cost)
            {
                dis[v]=dis[u]+edge[i].cost;
                now[v]=i;
                if(!vs[v])
                {
                    vs[v]=1;
                    q.push(v);
                }
            }
    }
    if(dis[sink]!=INF) return true;
    else return false;
}

int MCMF()
{
    int cost=0;
    while(SPFA())
    {
        int flow=INF;
        for(int u=sink; u!=source; u=edge[now[u]].st)
            if(flow>edge[now[u]].cap-edge[now[u]].flow)
                flow=edge[now[u]].cap-edge[now[u]].flow;
        for(int u=sink; u!=source; u=edge[now[u]].st)
        {
            edge[now[u]].flow+=flow;
            edge[now[u]^1].flow-=flow;
        }
        cost+=flow*dis[sink];
    }
    return cost;
}
int n,m;
struct node 
{
    int x;
    int y;
    node(int x=0,int y=0){this->x=x,this->y=y;};
};
node ph[111],pm[111];
char maz[111][111]={0};
int dist[111][111]={0};
void build()
{
    clr_1(head);
    tot=0;
    clr(dist);
    int cnt1=0;
    int cnt2=0;
    source=0; sink=(n+m)+1;
    for(int i=0;i<n;i++)
    {
       scanf("%s",maz[i]);
       for(int j=0;j<m;j++)
       {
           if(maz[i][j]=='H')
           {
               ph[++cnt1]=node(i,j);
               add(0,cnt1,1,0);
           }
           else if(maz[i][j]=='m')
           {
               pm[++cnt2]=node(i,j);
           }
       }
    }
    sink=cnt1+cnt2+1;
    for(int i=1;i<=cnt2;i++)
        add(cnt1+i,sink,1,0);
    for(int i=1;i<=cnt1;i++)
    {
        for(int j=1;j<=cnt2;j++)
        {
            int go=abs(ph[i].x-pm[j].x)+abs(ph[i].y-pm[j].y);
            add(i,cnt1+j,INF,go);
        }
    }
    printf("%d\n",MCMF());
    return;
}

int main()
{
   // fop;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==m&&m==0)
           break;
        build();
    }
    return 0;
}