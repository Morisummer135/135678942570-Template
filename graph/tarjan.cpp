const int MAX=1605000;
struct node 
{
    int v,next,w;
}g[MAX],g2[MAX];
int adj[MAX],low[MAX],dfn[MAX],bel[MAX];
int e,Index,cnt,n,m,x[MAX],y[MAX],inStack[MAX];
int maxx,vis[MAX],e2,adj2[MAX];
stack<int>s;
void add(int u,int v)
{
    g[e].v=v; g[e].next=adj[u]; adj[u]=e++;
}
void tarjan(int u)
{
    low[u]=dfn[u]=++Index;
    s.push(u);
    inStack[u]=1;
    int i,v;
    for(i=adj[u];i!=-1;i=g[i].next)
    {
        v=g[i].v;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(inStack[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        cnt++;
        do
        {
            v=s.top();
            s.pop();
            inStack[v]=0;
            bel[v]=cnt;
        }while(u!=v);
    }
}