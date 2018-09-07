#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=1010;

struct node
{
	int id,layer;
};
vector<node> Adj[maxn];
bool flag[maxn]={0};
int n,k,level=0,trsn=0;

int BFS(int x,int L){
	int numF=0;
	queue<node> q;
	node start;
	start.id=x;
	start.layer=0;
	q.push(start);
	flag[start.id]=true;
	while(!q.empty()){
		node top=q.front();
		q.pop();
		int u=top.id;
		for(int i=0;i<Adj[u].size();i++){
			node next=Adj[u][i];
			next.layer=top.layer+1;
			if(flag[next.id]==false&&next.layer<=L){
				q.push(next);
				flag[next.id]=true;
				numF++;
			}
		}
	}
	return numF;
}

int main(){
	node user;
	int n,L,numFollow,idFollow;
	scanf("%d%d",&n,&L);
	for(int i=1;i<=n;i++){
		user.id=i;
		scanf("%d",&numFollow);
		for(int j=0;j<numFollow;j++){
			scanf("%d",&idFollow);
			Adj[idFollow].push_back(user);
		}
	}
	int query,s;
	scanf("%d",&query);
	for(int i=0;i<query;i++){
		memset(flag,false,sizeof(flag));
		scanf("%d",&s);
		int numFF=BFS(s,L);
		printf("%d\n",numFF);
	}
	return 0;
}