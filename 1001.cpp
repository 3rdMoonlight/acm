#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<string>
#include<bitset>
using namespace std;

int cnt,n;
int ipm[100010],pm[100010],pl;
int loc[100010];
int vex[500010],g[100010],nextt[500010],tot;
int val[100010];
void addin(int u,int v)
{
	tot++;
	vex[tot]=v;
	nextt[tot]=g[u];
	g[u]=tot;
}
void makep()
{
	for(int i=2;i<=100000;i++)
	{
		if(!ipm[i])
		{
			pm[++pl]=i;
			for(int j=i+i;j<=100000;j+=i)
				ipm[j]=1;
			loc[i]=pl;
		}
	}
}
int main()
{
	makep();
	while(scanf("%d",&n)>0)
	{
		cnt++;
		for(int i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			addin(x,y);
			addin(y,x);
		}
		for(int i=1;i<=n;i++)
			scanf("%d",&val[i]);
	}
	return 0;
}
