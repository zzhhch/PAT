#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int maxn=110;

vector<int> tree[maxn];
int n,m,maxNum=0,Depth=0;
int hashTable[maxn]={0};

void DFS(int index,int depth){
	hashTable[depth]++;
	for(int i=0;i<tree[index].size();i++){
		DFS(tree[index][i],depth+1);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int temp,num,x;
		scanf("%d%d",&temp,&num);
		for(int j=0;j<num;j++){
			scanf("%d",&x);
			tree[temp].push_back(x);
		}
	}
	DFS(1,1);
	for(int i=0;i<maxn;i++){
		if(hashTable[i]>maxNum){
			maxNum=hashTable[i];
			Depth=i;
		}
	}
	printf("%d %d\n",maxNum,Depth);
	return 0;
}