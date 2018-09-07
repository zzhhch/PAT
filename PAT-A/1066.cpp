#include<cstdio>
#include<algorithm>
using namespace std;

struct node{
	int val;
	node *lchild,*rchild;
};

node* L(node* &root){
	node *temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	root=temp;
	return root;
}

node* R(node* &root){
	node *temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	root=temp;
	return root;
}

int getHeight(node* root){
	if(root==NULL) return 0;
	return max(getHeight(root->lchild),getHeight(root->rchild))+1;
}

node* Insert(node* &root,int val){
	if(root==NULL){
		root = new node();
		root->val=val;
		root->lchild=root->rchild=NULL;
	}
	else if(val<root->val){
		Insert(root->lchild,val);
		if(getHeight(root->lchild)-getHeight(root->rchild)==2){
			if(val<root->lchild->val){
				R(root);
			}
			else{
				L(root->lchild);
				R(root);
			}
		}
	}
	else{
		Insert(root->rchild,val);
		if(getHeight(root->lchild)-getHeight(root->rchild)==-2){
			if(val>root->rchild->val){
				L(root);
			}
			else{
				R(root->rchild);
				L(root);
			}
		}
	}
	return root;
}

int main(){
	int n,val;
	node* root=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&val);
		Insert(root,val);
	}
	printf("%d\n",root->val);
	return 0;
}



/*
#include<cstdio>
#include<algorithm>
using namespace std;

struct node
{
	int data,height;
	node *lchild,*rchild;
}*root;

node* newNode(int v){
	node* Node=new node();
	Node->data=v;
	Node->lchild=Node->rchild=NULL;
	Node->height=1;
	return Node;
}

int getHeight(node *root){
	if(root==NULL) return 0;
	return root->height;
}

void updateHeight(node *root){
	root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}

int Fac(node *root){
	return getHeight(root->lchild)-getHeight(root->rchild);
}

void L(node* &root){
	node *temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}

void R(node* &root){
	node *temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}

void Insert(node* &root,int v){
	if(root==NULL){
		root=newNode(v);
		return;
	}
	if(v < root->data){
		Insert(root->lchild,v);
		updateHeight(root);
		if(Fac(root)==2){
			if(Fac(root->lchild)==1){
				R(root);
			}
			else if(Fac(root->lchild)==-1){
				L(root->lchild);
				R(root);
			}
		}
	}
	else{
		Insert(root->rchild,v);
		updateHeight(root);
		if(Fac(root)==-2){
			if(Fac(root->rchild)==-1){
				L(root);
			}
			else if(Fac(root->rchild)==1){
				R(root->rchild);
				L(root);
			}
		}
	}
}

node* create(int data[],int n){
	node* root=NULL;
	for(int i=0;i<n;i++){
		Insert(root,data[i]);
	}
	return root;
}

int main(){
	int n,v;
	scanf("%d%d",&n,&v);
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		Insert(root,v);
	}
	printf("%d\n",root->data);
	return 0;
*/