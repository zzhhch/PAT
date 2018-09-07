#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=10010;
const int maxc=210;

int hashTable[maxc];
int a[maxn],dp[maxn];

int main(){
	int n,m,l,x,num=0;
	memset(hashTable,-1,sizeof(hashTable));
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		hashTable[x]=i;
	}
	scanf("%d",&l);
	for(int i=0;i<l;i++){
		scanf("%d",&x);
		if(hashTable[x]>=0){
			a[num++]=hashTable[x];
		}
	}
	int ans=-1;
	for(int i=0;i<num;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(a[j]<=a[i]&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
			}
		}
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}