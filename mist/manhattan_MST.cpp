const long long N = 200005;
vector<pair<long long,long long> >V[N];
struct Point
{
    long long x,y,id;
    bool operator<(const Point p)const
    {
        return x!=p.x?x<p.x:y<p.y;
    }
}p[N],p2[N];
struct BIT
{
    long long min_val,pos;
    void init(){
        min_val=(1ll<<60);
        pos=-1;
    }
}bit[N];
struct Edge
{
    long long u,v,d;
    bool operator<(const Edge e)const
    {
        return d<e.d;
    }
}e[N<<2];
long long n,tot,pre[N];
long long a[N],b[N];
long long find(long long x)
{
    return pre[x]=(x==pre[x]?x:find(pre[x]));
}
long long dist(long long i,long long j)
{
    return abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y);
}
long long dist2(long long i,long long j)
{
    return abs(p2[i].x-p2[j].x)+abs(p2[i].y-p2[j].y);
}
void addedge(long long u,long long v,long long d)
{
    e[tot].u=u;
    e[tot].v=v;
    e[tot++].d=d;
}
void update(long long x,long long val,long long pos)
{
    for(long long i=x;i>=1;i-=lowbit(i))
        if(val<bit[i].min_val)
            bit[i].min_val=val,bit[i].pos=pos;
}
long long ask(long long x,long long m)
{
    long long min_val=(1ll<<60),pos=-1;
    for(long long i=x;i<=m;i+=lowbit(i))
        if(bit[i].min_val<min_val)
            min_val=bit[i].min_val,pos=bit[i].pos;
    return pos;
}
long long k;
long long st,ed;
long long res;
long long Manhattan_minimum_spanning_tree(long long n,Point *p)
{
    for(long long dir=0;dir<4;dir++)
    {
        if(dir==1||dir==3)
        {
            for(long long i=0;i<n;i++)
                swap(p[i].x,p[i].y);
        }
        else if(dir==2)
        {
            for(long long i=0;i<n;i++)
            {
                p[i].x=-p[i].x;
            }
        }
        sort(p,p+n);
        // printf("%lld\n",n);
        // return 0;
        for(long long i=0;i<n;i++)
        {
            a[i]=b[i]=p[i].y-p[i].x;
        }
        // return 0;
        sort(b,b+n);
        long long m=unique(b,b+n)-b;
        for(long long i=1;i<=m;i++)
            bit[i].init();
        for(long long i=n-1;i>=0;i--)
        {
            long long pos=lower_bound(b,b+m,a[i])-b+1;
            long long ans=ask(pos,m);
            if(ans!=-1)
                addedge(p[i].id,p[ans].id,dist(i,ans));
            update(pos,p[i].x+p[i].y,i);
        }
    }
    sort(e,e+tot);
    for(long long i=0;i<n;i++)
        pre[i]=i;
    for(long long i=0;i<tot;i++)
    {
        long long u=e[i].u,v=e[i].v;
        long long fa=find(u),fb=find(v);
        if(fa!=fb)
        {
            pre[fa]=fb;
            V[u+1].pb(make_pair(v+1,dist2(u,v)));
            V[v+1].pb(make_pair(u+1,dist2(u,v)));
            // printf("%d %d\n",u,v);
        }
    }
}