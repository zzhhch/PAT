#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=510;
const int INF=1000000000;

int G[maxn][maxn],cost[maxn][maxn],dis[maxn];
vector<int> pre[maxn];
vector<int> ans,temp;
bool vis[maxn]={false};
int n,m,s,d,minCost=INF;

void Dijkstra(int x){
	fill(dis,dis+maxn,INF);
	dis[x]=0;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&dis[j]<MIN){
				u=j;
				MIN=dis[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=INF){
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

void DFS(int x){
	if(x==s){
		temp.push_back(x);
		int costm=0;
		for(int i=temp.size()-1;i>0;i--){
			int id=temp[i],idNext=temp[i-1];
			costm+=cost[id][idNext];
		}
		if(costm<minCost){
			ans=temp;
			minCost=costm;
		}
		temp.pop_back();
		return;
	}
	temp.push_back(x);
	for(int i=0;i<pre[x].size();i++){
		DFS(pre[x][i]);
	}
	temp.pop_back();
}

int main(){
	scanf("%d%d%d%d",&n,&m,&s,&d);
	fill(G[0],G[0]+maxn*maxn,INF);
	fill(cost[0],cost[0]+maxn*maxn,INF);
	int a,b,c,d;
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		G[a][b]=G[b][a]=c;
		cost[a][b]=cost[b][a]=d;
	}
	Dijkstra(s);
	DFS(d);
	for(int i=ans.size()-1;i>=0;i--){
		printf("%d ",ans[i]);
	}
	printf("%d %d",dis[d],minCost);
	return 0;
}