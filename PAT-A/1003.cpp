#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=510;

int G[maxn][maxn],weight[maxn],w[maxn],num[maxn],dis[maxn];
int n,m,s1,s2;
const int INF=1000000000;
bool flag[maxn]={false};

void Dijkstra(int s){
	fill(dis,dis+maxn,INF);
	memset(w,0,sizeof(w));
	memset(num,0,sizeof(num));
	w[s]=weight[s];
	num[s]=1;
	dis[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(flag[j]==false&&dis[j]<MIN){
				u=j;
				MIN=dis[j];
			}
		}
		if(u==-1) return;
		flag[u]=true;
		for(int v=0;v<n;v++){
			if(flag[v]==false&&G[u][v]!=INF){
				if(dis[u]+G[u][v]<dis[v]){
					dis[v]=dis[u]+G[u][v];
					w[v]=w[u]+weight[v];
					num[v]=num[u];
				}else if(dis[u]+G[u][v]==dis[v]){
					if(w[u]+weight[v]>w[v]){
						w[v]=w[u]+weight[v];
					}
					num[v]+=num[u];
				}
			}
		}
	}
}

int main(){
	scanf("%d%d%d%d",&n,&m,&s1,&s2);
	for(int i=0;i<n;i++){
		scanf("%d",&weight[i]);
	}
	int a,b,c;
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);
		G[a][b]=c;
		G[b][a]=c;
	}
	Dijkstra(s1);
	printf("%d %d\n",num[s2],w[s2]);
	return 0;
}