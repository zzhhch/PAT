#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=110;

struct node
{
	int data;
	int lchild,rchild;
}tree[maxn];
int origin[maxn];
int n,index=0,num;

void inOrder(int root){
	if(root==-1) return;
	inOrder(tree[root].lchild);
	tree[root].data=origin[index++];
	inOrder(tree[root].rchild);
}

void levelOrder(int root){
	queue<int> q;
	q.push(root);
	num=0;
	while(!q.empty()){
		int top=q.front();
		q.pop();
		printf("%d",tree[top].data);
		num++;
		if(num<n) printf(" ");
		if(tree[top].lchild!=-1) q.push(tree[top].lchild);
		if(tree[top].rchild!=-1) q.push(tree[top].rchild);
	}

}

int main(){
	scanf("%d",&n);
	int a,b;
	for(int i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		tree[i].lchild=a;
		tree[i].rchild=b;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&origin[i]);
	}
	sort(origin,origin+n);
	inOrder(0);
	levelOrder(0);
	return 0;
}