

/*
#include<cstdio>
const int maxn=50010;


int main(){
	int pre[maxn],in[maxn];
	int n,ans;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	int low=0,high=n-1;
	for(int i=0;i<n;i++){
		int root=pre[i],j;
		for(j=0;j<n;j++){
			if(root==in[j]){
				break;
			}
		}
		if(j!=low){
			high=j-1;
		}else{
			low=j+1;
		}
		if(low==high){
			ans=in[low];
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
*/