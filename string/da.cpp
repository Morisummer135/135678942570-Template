const int maxn=100000;
int sa[maxn],rank[maxn],rank2[maxn],height[maxn],c[maxn],*x,*y,s[maxn],n;
void radix_sort(int n,int sz)
{
    memset(c,0,sizeof(c));
    for(int i=0;i<n;i++) c[x[y[i]]]++;
    for(int i=1;i<sz;i++) c[i]+=c[i-1];
    for(int i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
}
void get_sa(int *s,int n,int sz=222)
{
    x=rank,y=rank2;
    for(int i=0;i<n;i++)
        x[i]=s[i],y[i]=i;
    radix_sort(n,sz);
    for(int len=1;len<n;len<<=1)
    {
        int yid=0;
        for(int i=n-len;i<n;i++) y[yid++]=i;
        for(int i=0;i<n;i++) if(sa[i]>=len) y[yid++]=sa[i]-len;
        radix_sort(n,sz);
        swap(x,y);
        x[sa[0]]=yid=0;
        for(int i=1;i<n;i++)
        {
            if(y[sa[i]]==y[sa[i-1]]&&sa[i-1]+len<n&&sa[i]+len<n&&y[sa[i]+len]==y[sa[i-1]+len])
                x[sa[i]]=yid;
            else x[sa[i]]=++yid;
        }
        sz=yid+1;
        if(sz>=n) break;
    }
    for(int i=0;i<n;i++)
        rank[i]=(n==1?0:x[i]);
}
void get_height(int * s,int n)
{
    int k=0;height[0]=0;
    for(int i=0;i<n;i++)
    {
        if(rank[i]==0) continue;
        k=max(0,k-1);
        int j=sa[rank[i]-1];
        while(i+k<n&&j+k<n&&s[i+k]==s[j+k]) k++;
        height[rank[i]]=k;
    }
}