#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;
const int maxn=210;
const int INF=1000000000;

int G[maxn][maxn],dis[maxn],happy[maxn];
int numCity,sumHappy=0,n,k,numPath=0;
float avgHappy=0;
bool vis[maxn]={false};
vector<int> pre[maxn];
vector<int> ans,temp;
map<string,int> stringTonum;
map<int,string> numTostring;

void Dijkstra(int s){
	fill(dis,dis+maxn,INF);
	dis[s]=0;
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
			if(vis[v]==false){
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
		int sHappy=0;
		float ahappy=0;
		numPath++;
		for(int i=temp.size()-2;i>=0;i--){
			sHappy+=happy[temp[i]];
		}
		ahappy=sHappy/(temp.size()-1);
		if(sHappy>sumHappy){
			sumHappy=sHappy;
			avgHappy=ahappy;
			ans=temp;
		}else if(sHappy==sumHappy&&ahappy>avgHappy){
			avgHappy=ahappy;
			ans=temp;
		}
		temp.pop_back();
		return;
	}
	temp.push_back(v);
	for(int i=0;i<int(pre[v].size());i++){
		DFS(pre[v][i]);
	}
	temp.pop_back();
}

int main(){
	string start,p,q;
	cin>>n>>k>>start;
	stringTonum[start]=0;
	numTostring[0]=start;
	for(int i=1;i<=n-1;i++){
		cin>>p>>happy[i];
		stringTonum[p]=i;
		numTostring[i]=p;
	}
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=0;i<k;i++){
		cin>>p>>q;
		int id1=stringTonum[p],id2=stringTonum[q];
		scanf("%d",&G[id1][id2]);
		G[id2][id1]=G[id1][id2];
	}
	Dijkstra(0);
	int ed=stringTonum["ROM"];
	DFS(ed);
	printf("%d %d %d %d\n",numPath,dis[ed],sumHappy,int(avgHappy));
	for(int i=ans.size()-1;i>=0;i--){
		cout<<numTostring[ans[i]];
		if(i>0) printf("->");
	}
	return 0;
}