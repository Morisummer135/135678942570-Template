#include<bits/stdc++.h>
#define clr(x)  memset(x,0,sizeof(x));
using namespace std;
int U[333333];
int D[333333];
int L[333333];
int R[333333];
int S[333333];
int H[333333];
int C[333333];
int res[333333];
char mp[22][22];
void del(int CC)
{
	R[L[CC]]=R[CC];
	L[R[CC]]=L[CC];
	for(int i=D[CC];i!=CC;i=D[i])
		for(int j=R[i];j!=i;j=R[j])
		{
			D[U[j]]=D[j];
			U[D[j]]=U[j];
			S[C[j]]--;
		}
}
void bac(int CC)
{
	R[L[CC]]=CC;
	L[R[CC]]=CC;
	for(int i=D[CC];i!=CC;i=D[i])
		for(int j=R[i];j!=i;j=R[j])
		{
			D[U[j]]=j;
			U[D[j]]=j;
			S[C[j]]++;
		}
}
int dfs(int dep)
{
	if(R[0]==0)
	{
		for(int i=0;i<dep;i++)
			mp[res[i]/256][res[i]%256/16]=res[i]%16+'A';
		return 1;
	}
	if(R[0]>256)
	return 0;
	int w=INF;
	int now;
	int nxt;
	for(int i=R[0];i!=0;i=R[i])
		if(S[i]<w)
		{
			now=i;
			w=S[i];
		}
	nxt=D[now];
	del(now);
	while(nxt!=now)
	{
		res[dep]=H[nxt];
		for(int i=R[nxt];i!=nxt;i=R[i])
			del(C[i]);
		if(dfs(dep+1))
			return 1;
		for(int i=L[nxt];i!=nxt;i=L[i])
			bac(C[i]);
		nxt=D[nxt];
	}
	bac(now);
	return 0;
}
int last;
int cnt=256*4;
void linkinit(int u,int v)
{
	L[v]=u,R[u]=v,D[v]=U[v]=v,last=v;
}
void init()
{
	last=0;
	for(int i=1;i<=256;i++)
	{
		if(mp[(i-1)/16][(i-1)%16]!='-')
			continue;
		linkinit(last,i);
	}
	for(int i=1;i<=256;i++)
	{
		int flag=1;
		int h=(i-1)/16;
		int nn=(i-1)%16;
		for(int ii=0;ii<=15;ii++)
			if(mp[h][ii]==nn+'A')
			{
				flag=0;
				break;
			}
		if(flag)
			linkinit(last,i+256);
	}
	for(int i=1;i<=256;i++)
	{
		int flag=1;
		int h=(i-1)/16;
		int nn=(i-1)%16;
		for(int ii=0;ii<=15;ii++)
			if(mp[ii][h]==nn+'A')
			{
				flag=0;
				break;
			}
		if(flag)
			linkinit(last,i+256+256);
	}
	for(int i=1;i<=256;i++)
	{
		int flag=1;
		int nx=((i-1)/16/4*4);
		int ny=((i-1)/16%4*4);
		int nn=(i-1)%16;
		for(int ii=0;ii<=3;ii++)
			for(int jj=0;jj<=3;jj++)
				if(mp[ii+nx][jj+ny]==nn+'A')
				{
					flag=0;
					ii=4;
					break;
				}
		if(flag)
			linkinit(last,i+256+256+256);
	}
	R[last]=0;
	L[0]=last;
}
void linknode(int pos,int h)
{
    cnt++;
    H[cnt]=h;
    C[cnt]=pos;
    D[cnt]=C[cnt];
    U[cnt]=U[C[cnt]];
    D[U[C[cnt]]]=cnt;
    U[C[cnt]]=cnt;
    S[C[cnt]]++;
}
int main()
{
	while(scanf("%s",mp[0])>0)
	{
	    cnt=256*4;
		clr(U);clr(D);clr(R);clr(L);clr(H);clr(C);clr(res);clr(S);
		for(int i=1;i<16;i++)
			scanf("%s",mp[i]);
		init();
		for(int i=0;i<16;i++)
			for(int j=0;j<16;j++)
				if(mp[i][j]=='-')
				for(int k=0;k<16;k++)
				{
					int flag=1;
					for(int ii=0;ii<16;ii++)
						if(mp[ii][j]=='A'+k||mp[i][ii]=='A'+k)
						{
							flag=0;
							break;
						}
					int nx=i/4*4;
					int ny=j/4*4;
					for(int ii=0;ii<4;ii++)
						for(int jj=0;jj<4;jj++)
							if(mp[nx+ii][ny+jj]=='A'+k)
							{
								flag=0;
								ii=5;
								break;
							}
					if(flag==0)
						continue;
					int h=i*256+j*16+k;
					int fg=0;
					if(D[i*16+j+1])
					{
					    linknode(i*16+j+1,h);
						fg=cnt;
                    }
                    if(D[257+i*16+k])
                    {
					    linknode(257+i*16+k,h);
						if(fg) L[cnt]=cnt-1,R[cnt-1]=cnt;
						else fg=cnt;
					}
					if(D[513+j*16+k])
					{
					    linknode(513+j*16+k,h);
						if(fg) L[cnt]=cnt-1,R[cnt-1]=cnt;
						else fg=cnt;
					}
					if(D[769+(i/4*4+j/4)*16+k])
					{
					    linknode(769+(i/4*4+j/4)*16+k,h);
						if(fg) L[cnt]=cnt-1,R[cnt-1]=cnt;
						else fg=cnt;
					}
					if(fg) L[fg]=cnt,R[cnt]=fg;
				}
		dfs(0);
		for(int i=0;i<16;i++)
		{
			mp[i][16]=0;
			printf("%s\n",mp[i]);
		}
		puts("");
	}
	return 0;
}
