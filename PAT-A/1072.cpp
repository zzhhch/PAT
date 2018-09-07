#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=1020;
const int INF=1000000000;

int G[maxn][maxn],dis[maxn];
int n,m,k,ds;
bool vis[maxn]={false};

int change(char s[]){
	int i=0,len=strlen(s),ID=0;
	while(i<len){
		if(s[i]!='G'){
			ID=ID*10+(s[i]-'0');
		}
		i++;
	}
	if(s[0]=='G') return n+ID;
	return ID;
}

void Dijkstra(int v){
	memset(vis,false,sizeof(vis));
	fill(dis,dis+maxn,INF);
	dis[v]=0;
	for(int i=0;i<n+m;i++){
		int u=-1,MIN=INF;
		for(int j=1;j<=n+m;j++){
			if(vis[j]==false&&dis[j]<MIN){
				u=j;
				MIN=dis[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=1;v<=n+m;v++){
			if(vis[v]==false&&G[u][v]!=INF){
				if(dis[u]+G[u][v]<dis[v]){
					dis[v]=dis[u]+G[u][v];
				}
			}
		}
	}
}

int main(){
	fill(G[0],G[0]+maxn*maxn,INF);
	scanf("%d%d%d%d",&n,&m,&k,&ds);
	int s1,s2,w;
	char str1[5],str2[5];
	for(int i=0;i<k;i++){
		scanf("%s %s %d",str1,str2,&w);
		s1=change(str1);
		s2=change(str2);
		G[s1][s2]=G[s2][s1]=w;
	}
	double ansDis=-1,ansAvg=INF;
	int ansId=-1;
	for(int i=n+1;i<=n+m;i++){
		double minDis=INF,avg=0;
		Dijkstra(i);
		for(int j=1;j<=n;j++){
			if(dis[j]>ds){
				minDis=-1;
				break;
			}
			if(dis[j]<minDis){
				minDis=dis[j];
			}
			avg+=1.0*dis[j]/n;
		}
		if(minDis==-1) continue;
		if(minDis>ansDis){
			ansDis=minDis;
			ansId=i;
			ansAvg=avg;
		}else if(minDis==ansDis&&avg<ansAvg){
			ansId=i;
			ansAvg=avg;
		}
	}	
	if(ansDis==-1) printf("No Solution\n");
	else{
		printf("G%d\n",ansId-n);
		printf("%.1f %.1f\n",ansDis,ansAvg);
	}
	return 0;
}