#include<cstdio>
#include<vector>
using namespace std;

struct node
{
	int data;
	node* lchild;
	node* rchild;
};

void insert(node* &root,int x){
	if(root==NULL){
		root=new node;
		root->data=x;
		root->lchild=root->rchild=NULL;
		return;
	}
	if(x<root->data) insert(root->lchild,x);
	else insert(root->rchild,x);
}

void preOrder(node* root,vector<int> &vi){
	if(root==NULL) return;
	vi.push_back(root->data);
	preOrder(root->lchild,vi);
	preOrder(root->rchild,vi);
}

void preOrderMirror(node* root,vector<int> &vi){
	if(root==NULL) return;
	vi.push_back(root->data);
	preOrderMirror(root->rchild,vi);
	preOrderMirror(root->lchild,vi);
}

void postOrder(node* root,vector<int> &vi){
	if(root==NULL) return;
	postOrder(root->lchild,vi);
	postOrder(root->rchild,vi);
	vi.push_back(root->data);
}

void postOrderMirror(node* root,vector<int> &vi){
	if(root==NULL) return;
	postOrder(root->rchild,vi);
	postOrder(root->lchild,vi);
	vi.push_back(root->data);
}
int n;
vector<int> origin,pre,preMirror,post,postMirror;

int main(){
	scanf("%d",&n);
	int x;
	node* root=NULL;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		origin.push_back(x);
		insert(root,x);
	}
	preOrder(root,pre);
	preOrderMirror(root,preMirror);
	postOrder(root,post);
	postOrderMirror(root,postMirror);
	if(origin==pre){
		printf("YES\n");
		for(int i=0;i<post.size();i++){
			printf("%d",post[i]);
			if(i<post.size()-1) printf(" ");
		}
	}
	else if(origin==preMirror){
		printf("YES\n");
		for(int i=0;i<postMirror.size();i++){
			printf("%d",postMirror[i]);
			if(i<postMirror.size()-1) printf(" ");
		}
	}
	else printf("NO\n");

	return 0;
}