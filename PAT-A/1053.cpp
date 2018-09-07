#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=110;

struct node{
	int weight;
	vector<int> child;
}tree[maxn];

int path[maxn];
int n,m,ans,numNode=0;

void DFS(int index,int numNode,int sum){
	if(sum>ans) return;
	if(sum==ans){
		if(tree[index].child.size()==0){
			for(int i=0;i<numNode;i++){
				printf("%d",tree[path[i]].weight);
				if(i<numNode-1) printf(" ");
				else printf("\n");
			}
		}
		return;
	}
	for(int i=0;i<tree[index].child.size();i++){
		int child=tree[index].child[i];
		path[numNode]=child;
		DFS(child,numNode+1,sum+tree[child].weight);
	}
}



bool cmp(int a,int b){
	return tree[a].weight>tree[b].weight;
}

int main(){
	scanf("%d%d%d",&n,&m,&ans);
	for(int i=0;i<n;i++){
		scanf("%d",&tree[i].weight);
	}
	for(int i=0;i<m;i++){
		int now,num,temp;
		scanf("%d%d",&now,&num);
		for(int j=0;j<num;j++){
			scanf("%d",&temp);
			tree[now].child.push_back(temp);
		}
		sort(tree[now].child.begin(),tree[now].child.end(),cmp);
	}
	path[0]=0;
	DFS(0,1,tree[0].weight);
	return 0;
}