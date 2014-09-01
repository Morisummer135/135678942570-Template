#include <set>
#include <cmath>
#include <stack>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <vector>
#include <ctime>
#include <queue>
#include <list>
#include <map>
#define pi acos(-1.0)
#define INF 0x3f3f3f3f
#define clr(x)  memset(x,0,sizeof(x));
#define clrto(x,siz,y)  for(int xx=0;xx<=siz;xx++)  x[xx]=y;
#define clrset(x,siz)  for(int xx=0;xx<=siz;xx++)  x[xx]=xx;
#define clr_1(x) memset(x,-1,sizeof(x));
#define clrmax(x) memset(x,0x3f,sizeof(x));
#define clrvec(x,siz) for(int xx=0;xx<=siz;xx++)  x[xx].clear();
#define fop2   freopen(".in","r",stdin); //freopen(".out","w",stdout);
#define fop   freopen("in.txt","r",stdin);//freopen("out.txt","w",stdout);
#define myprogram By_135678942570
#define clrcpy(x,siz,y)  for(int xx=0;xx<siz;xx++)  x[xx]=y[xx];
#define pb push_back
using namespace std;
const int INF = (-1u) >> 2;
const int maxn = 200010;
const int kind = 27;
struct NODE{
	int fail, next[kind], step;
	int pos; //该节点在字符串中的位置 
	int id; //副本与本体拥有相同的 id 
	void clear(){
		clr(next);
		id = step = fail = pos = 0;	
	}
};
struct suffix_automation{ //支持删除的后缀自动机 ！！！ 
	NODE node[maxn << 1]; //原串长+ 可能插入的 <= maxn ,但每个可能还有一个副本，乘 2 
	int last, total;
	int len; //当前字符串长度 
	int idx[maxn << 1]; //字符串中第 i 个字符对应结点 idx[i] 
	bool is_del[maxn << 1];
	void init(){
		total = last = 0;
		len = 0;
		node[0].clear();
		is_del[0] = 0;
		clr(idx);
	}
	void push_back(int step_val){
		int p = ++total;
		node[p].clear();
		node[p].step = step_val;
		node[p].id = p;
		is_del[p] = 0;
	}
	bool unExistNorDel(int x){
		return x == 0 || is_del[node[x].id];	
	}
	void insert(int ch){
		push_back(node[last].step + 1);
		node[total].pos = ++len;idx[len] = total; // 第 len 个字符对应第 total 个结点 
		int p = last, np = total;
		for (;unExistNorDel(node[p].next[ch]); p = node[p].fail) node[p].next[ch] = np;
		if (node[p].next[ch] == np) //此时p一定等于 0 
			node[np].fail = p; 
		else {
			int q = node[p].next[ch];
			if (node[q].step == node[p].step + 1) node[np].fail = q;
			else {
				int nq = ++total;
				node[nq] = node[q]; 
				node[nq].step = node[p].step + 1;
				node[q].fail = node[np].fail = nq;
				for (;node[p].next[ch] == q; p = node[p].fail) node[p].next[ch] = nq;	
			}
		}
		last = np;
	}
	void addString(char *str){
		int i;
		for (i = 0; str[i]; i++)
			insert(str[i] - 'a' + 1);
	}
	void delString(int k){ //从后往前删除 k个字符 
		int  i;
		for (i = 1; i <= k; i++){
			is_del[node[idx[len - i + 1]].id] = 1;
		}	
		last = idx[len - k];
		len -= k;
	}
	bool first;
	int dfs(int x, int &l){
		if (l == 0) return node[x].pos;
		int i;
		for (i = 0; i < kind; i++){
			if (i == 0 && first){
				first = 0;
				continue;	
			}	
			if (unExistNorDel(node[x].next[i]))continue;
			l--;
			return dfs(node[x].next[i], l);
		}	
		return node[x].pos;
	}
	int query(int l){ //求长度为l的子串中字典序最小的子串，返回位置 若l为len则为所有子串中字典序最小的那个 
		first = 1;
		insert(0);
		int tmp = l;
		int id = dfs(0, tmp);
		delString(1);
		int det = l - tmp;
		return id - det + 1;		 
	}
}obj;
int main()
{
	
}