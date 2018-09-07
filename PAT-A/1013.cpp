#include<cstdio>
#include<vector>
#include <cstring>
using namespace std;
const int maxn=1010;

vector<int> G[maxn];
bool flag[maxn];
int n,m,k,depoint;

void DFS(int x){
	if(x==depoint) return;
	flag[x]=true;
	for(int i=0;i<G[x].size();i++){
		if(flag[G[x][i]]==false){
			DFS(G[x][i]);
		}
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	int a,b;
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=0;i<k;i++){
		scanf("%d",&depoint);
		int block=0;
		memset(flag,false,sizeof(flag));
		for(int i=1;i<=n;i++){
			if(i!=depoint&&flag[i]==false){
				DFS(i);
				block++;
			}
		}
		printf("%d\n",block-1);
	}
	return 0;
}