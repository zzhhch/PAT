#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1010;

int father[maxn];
int isRoot[maxn];
int course[maxn];

bool cmp(int x,int y){
	return x>y;
}
int findFather(int x){
	while(father[x]!=x){
		x=father[x];
	}
	return x;
}

void Union(int x,int y){
	int Fa=findFather(x);
	int Fb=findFather(y);
	if(Fa!=Fb) father[Fa]=Fb;
}

int main(){
	for(int i=0;i<maxn;i++){
		father[i]=i;
		isRoot[i]=0;
	}
	int n,num,val;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d:",&num);
		for(int j=0;j<num;j++){
			scanf(" %d",&val);
			if(course[val]==0){
				course[val]=i;
			}
			Union(i,findFather(course[val]));
		}
	}
	for(int i=1;i<=n;i++){
		isRoot[findFather(i)]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(isRoot[i]!=0){
			ans++;
		}
	}
	sort(isRoot+1,isRoot+n+1,cmp);
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++){
		printf("%d",isRoot[i]);
		if(i<ans) printf(" ");
	}
	return 0;
}