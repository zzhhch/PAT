#include<cstdio>
#include<stack>
#include<iostream>
#include<cstring>
using namespace std;
struct Node
{
	int data;
	Node* lchild;
	Node* rchild;
};
int n,preorder[35],inorder[35],x=0,y=0,printn=0;
Node* create(int preL,int preR,int inL,int inR)
{
	if(preL>preR)
		return NULL;
	Node* root=new Node;
	root->data=preorder[preL];
	int k;
	for(k=inL;k<=inR;k++)
	{
		if(inorder[k]==preorder[preL])
			break;
	}
	int num=k-inL;
	root->lchild=create(preL+1,preL+num,inL,inL+num-1);
	root->rchild=create(preL+num+1,preR,inL+num+1,inR);
	return root;
}

void postTravel(Node* root)
{
	if(root==NULL)
		return;
	postTravel(root->lchild);
	postTravel(root->rchild);
	printf("%d",root->data);
	if(printn++<n-1)
		printf(" ");
}

int main()
{
	stack<int> st;
	string str;
	scanf("%d",&n);
	for(int i=0;i<2*n;i++)
	{
		cin>>str;
		if(str=="Push")
		{
			scanf("%d",&preorder[x]);
			st.push(preorder[x]);
			x++;
		}
		else
		{
			int top=st.top();
			st.pop();
			inorder[y++]=top;
		}
	}
	Node* root=create(0,n-1,0,n-1);
	postTravel(root);

	return 0;

}