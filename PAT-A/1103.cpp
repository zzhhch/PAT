#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> ans,temp,fac;
int Max=-1,n,m,p;

void DFS(int index,int nowK,int Sum,int facSum)
{
	if(Sum==n&&nowK==m)
	{
		if(facSum>Max)
		{
			ans=temp;
			Max=facSum;
		}	
		return;
	}
	if(Sum>n||nowK>m)
		return;
	if(index-1>=0)
	{
		temp.push_back(index);
		DFS(index,nowK+1,Sum+fac[index],facSum+index);
		temp.pop_back();
		DFS(index-1,nowK,Sum,facSum);
	}
}
int power(int a)
{
	int ans=1;
	for(int i=0;i<p;i++)
	{
		ans*=a;
	}
	return ans;
}

int main()
{
	scanf("%d%d%d",&n,&m,&p);
	int pe=0,x=0;
	while(pe<=n)
	{
		fac.push_back(pe);
		pe=power(++x);
	}
	DFS(fac.size()-1,0,0,0);
	if(Max==-1)
	{
		printf("Impossible\n");
	}
	else
	{
		printf("%d = %d^%d",n,ans[0],p);
		for(int i=1;i<int(ans.size());i++)
		{
			printf(" + %d^%d",ans[i],p);
		}
	}
	return 0;
	
}
