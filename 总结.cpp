//二叉树
//结点
struct node
{
	int data;
	node* lchild;
	node* rchild;
};
//建立新结点
node* newNode(int v){
	node* Node=new node;
	Node->data=v;
	Node->lchild=Node->rchild=NULL;
	return Node;
}
//查找 修改
void search(node* root,int x,int newdata){
	if(root==NULL) return;
	if(root->data==x){
		root->data=newdata;
	}
	search(root->lchild,x,newdata);
	search(root->rchild,x,newdata);
}
//插入
void insert(node* &root,int x){
	if(root==NULL){
		root=newNode(x);
		return;
	}
	if(根据二叉树的性质){
		insert(root->lchild,x);
	}else{
		insert(root->rchild,x);
	}
}
//建立二叉树
node* create(int data[],int n){
	node* root=NULL;
	for(int i=0;i<n;i++){
		insert(root,data[i])
	}
	return root;
}

//先序遍历
void preOrder(node* root){
	if(root==NULL) return;
	printf("%d",root->data);
	preOrder(root->lchild);
	preOrder(root->rchild);
}
//中序遍历
void inOrder(node* root){
	if(root==NULL) return;
	inOrder(root->lchild);
	printf("%d",root->data);
	inOrder(root->rchild);
}
//后序遍历
void postOrder(node* root){
	if(root==NULL) return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%d",root->data);
}
//层次遍历
void levelOrder(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* top=q.front();
		q.pop();
		printf("%d",top->data);
		if(top->lchild!=NULL) q.push(top->lchild);
		if(top->rchild!=NULL) q.push(top->rchild);
	}
}


//平衡二叉树
//结点
struct node
{
	int v,height;
	node* lchild;
	node* rchild;
};
//生成新结点
node* newNode(int v){
	node* Node=new node;
	Node->v=v;
	Node->height=1;
	Node->lchild=Node->rchild=NULL;
	return Node;
}
//获取高度
int getHeight(node* root){
	if(root==NULL) return 0;
	return root->height;
}
//获取平衡因子
int getBalanceFactor(node* root){
	return getHeight(root->lchild)-getHeight(root->return);
}
//更新树高
void update(node* root){
	root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}
//查找
void search(node* root,int x){
	if(root==NULL){
		printf("Search Failed\n");
		return;
	}
	if(x==root->data){
		printf("%d\n",root->data);
	}else if(x<root->data){
		search(root->lchild);
	}else if(x>root->data){
		search(root->rchild);
	}
}
//插入
void L(node* &root){
	node* temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	update(root);
	update(temp);
	root=temp;
}
void R(node* &root){
	node* temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	update(root);
	update(temp);
	root=temp;
}
void insert(node* &root,int x){
	if(root==NULL){
		root=newNode(x);
		return;
	}
	if(v<root->data){
		insert(root->lchild,x);
		update(root);
		if(getBalanceFactor(root)==2){
			if(getBalanceFactor(root->lchild)==1){
				R(root);
			}else if(getBalanceFactor(root->lchild)==-1){
				L(root->lchild);
				R(root);
			}
		}
	}else{
		insert(root->rchild,x);
		update(root);
		if(getBalanceFactor(root)==-2){
			if(getBalanceFactor(root->rchild)==-1){
				R(root->rchild);
				L(root);
			}
		}
	}
}
node* create(int data[],int n){
	node* root=NULL;
	for(int i=0;i<n;i++){
		insert(root,data[i]);
	}
	return root;
}

//并查集
//查找父结点
int findFather(int x){
	while(x!=father[x]){
		x=father[x];
	}
	return x;
}
//合并
void Union(int a,int b){
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA!=faB){
		father[faA]=faB;
	}
}
//路径压缩
int findFather_a(int x){
	int a=x;
	while(x!=father[x]){
		x=father[x];
	}
	while(a!=father[a]){
		int z=a;
		a=father[a];
		father[z]=x;
	}
	return x;
}
//堆
//向下调整
void downAdjust(int low,int high){
	int i=low,j=2*i;
	while(j<=high){
		if(j+1<=high&&heap[j]<heap[j+1]){
			j=j+1;
		}
		if(heap[j]>heap[i]){
			swap(heap[j],heap[i]);
			i=j;
			j=2*i;
		}else{
			break;
		}
	}
}
//向上调整
void upAdjust(int low,int high){
	int i=high,j=i/2;
	while(j>=low){
		if(heap[i]>heap[j]){
			swap(heap[i],heap[j]);
			i=j;
			j=i/2;
		}else{
			break;
		}
	}
}
//建堆
void createHeap(){
	for(int i=n/2;i>=1;i--){
		downAdjust(1,n);
	}
}
//删除堆顶元素
void deleteTop(){
	heap[1]=heap[n--];
	downAdjust(1,n-1);
}
//添加元素
void insert(int x){
	heap[++n]=x;
	upAdjust(1,n);
}
//堆排序
void heapSort(){
	createHeap();
	for(int i=n;i>1;i--){
		swap(heap[i].heap[1]);
		downAdjust(1,i-1);
	}
}


//图
//DFS
void DFS(int u){
	init()
	vis[u]==true;
	for(u能到达的顶点v){
		if(vis[v]==false){
			DFS(v);
		}
	}
}
void DFSTrave(G){
	for(G的所友顶点u){
		if(vis[u]==false){
			DFS(u);
		}
	}
}
//BFS
void BFS(u){
	queue<typename> q;
	q.push(u);
	inq[u]=true;
	while(!q.empty()){
		typename top=q.front();
		q.pop();
		for(从u能到v){
			if(inq[v]==false){
				q.push(v);
				inq[v]=true;
			}
		}
	}
}
void BFSTrave(G){
	for(G的所友顶点u){
		if(inq[u]==false){
			BFS(u);
		}
	}
}
//Dijkstra
void Dijkstra(G,dis[],s){
	init();
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
		for(从u能到v){
			if(vis[v]==false&&dis[u]+G[u][v]<dis[v]){
				dis[v]=dis[u]+G[u][v];
			}
		}
		/*需要保存序号
		for(从u能到v){
			if(vis[v]==false){
				if(dis[u]+G[u][v]<dis[v]){
					dis[v]=dis[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(dis[u]+G[u][v]==dis[v]){
					pre[v].push_back(u);
				}
			}
		}*/
	}
}


//STL
vector<typename> name;
set<typename> name;
string<typename> name;
map<typename> name;
queue<typename> name;
priority_queue<typename> name;
stcak<typename> name;
<pair>
<algorithm>
max()
min()
abs()
swap()
reverse()
next_permutation()
fill()
sort()
lower_bound()
upper_bound()

