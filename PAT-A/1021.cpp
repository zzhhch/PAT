#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int maxn=10010;

vector<int> G[maxn],temp;
set<int> ans;
int n,maxdepth=1;
bool flag[maxn]={0};

void DFS(int x,int depth){
	if(depth>maxdepth){
		temp.clear();
		temp.push_back(x);
		maxdepth=depth;
	}else if(depth==maxdepth){
		temp.push_back(x);
	}
	flag[x]=true;
	for(int i=0;i<G[x].size();i++){
		if(flag[G[x][i]]==false){
			DFS(G[x][i],depth+1);
		}
	}
}

int main(){
	scanf("%d",&n);
	int a,b;
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int cnt=0,s1;
	for(int i=1;i<=n;i++){
		if(flag[i]==false){
			DFS(i,1);
			if(i==1){
				if(temp.size()!=0) s1=temp[0];
				for(int j=0;j<temp.size();j++){
					ans.insert(temp[j]);
				} 
			}
			cnt++;
		}
		
	}
	if(cnt>=2){
		printf("Error: %d components",cnt)	;
	}else{
		temp.clear();
		fill(flag,flag+maxn,false);
		DFS(s1,1);
		for(int i=0;i<temp.size();i++){
			ans.insert(temp[i]);
		}
		for(set<int>::iterator it=ans.begin();it!=ans.end();it++){
			printf("%d\n",*it);
		}
	}
	return 0;
}