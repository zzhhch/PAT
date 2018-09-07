#include<cstdio>
const int maxn=0x7fffffff;

bool hashTable[maxn]={false};

int main()
{
	int n,a,num=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		if(a>0)
		{
			hashTable[a]=true;
			num++;
		}	
	}
	a=0;
	for(int i=1;i<maxn;i++)
	{
		if(hashTable[i]==false)
		{
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}