#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=510;
const int INF=1000000000;

int Cmax,n,m,Sp,minNeed=INF,minRemain=INF;
int G[maxn][maxn],weight[maxn],dis[maxn];
bool flag[maxn]={0};
vector<int> pre[maxn];
vector<int> ans,temp;


void Dijkstra(int x){
	fill(dis,dis+maxn,INF);
	dis[x]=0;
	for(int i=0;i<=n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<=n;j++){
			if(flag[j]==false&&dis[j]<MIN){
				u=j;
				MIN=dis[j];
			}
		}
		if(u==-1) return;
		flag[u]=true;
		for(int v=0;v<=n;v++){
			if(flag[v]==false&&G[u][v]!=INF){
				if(dis[u]+G[u][v]<dis[v]){
					dis[v]=dis[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(dis[u]+G[u][v]==dis[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}

void DFS(int v){
	if(v==0){
		temp.push_back(v);
		int need=0,remain=0;
		for(int i=temp.size()-1;i>=0;i--){
			int id=temp[i];
			if(weight[id]>0){
				remain+=weight[id];
			}else{
				if(remain>abs(weight[id])){
					remain-=abs(weight[id]);
				}else{
					need+=abs(weight[id])-remain;
					remain=0;
				}
			}
		}
		if(need<minNeed){
			minNeed=need;
			minRemain=remain;
			ans=temp;
		}else if(need==minNeed&&remain<minRemain){
			minRemain=remain;
			ans=temp;
		}
		temp.pop_back();
		return;
	}
	temp.push_back(v);
	for(int i=0;i<pre[v].size();i++){
		DFS(pre[v][i]);
	}
	temp.pop_back();
}


int main(){
	int a,b,c;
	fill(G[0],G[0]+maxn*maxn,INF);
	scanf("%d%d%d%d",&Cmax,&n,&Sp,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&weight[i]);
		weight[i]-=Cmax/2;
	}
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);
		G[a][b]=c;
		G[b][a]=c;
	}
	Dijkstra(0);
	DFS(Sp);
	printf("%d ",minNeed);
	for(int i=ans.size()-1;i>=0;i--){
		printf("%d",ans[i]);
		if(i>0) printf("->");
	}
	printf(" %d",minRemain);
	return 0;
}