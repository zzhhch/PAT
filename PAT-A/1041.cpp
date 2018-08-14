#include<cstdio>

int hashTable[10010]={0};

int main()
{
	int n,num[10010],a,k=0;
	bool isPrint=false;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		hashTable[a]++;
		if(hashTable[a]==1)
			num[k++]=a;
	}
	for(int i=0;i<k;i++)
	{
		if(hashTable[num[i]]==1)
		{
			printf("%d",num[i]);
			isPrint=true;
			break;
		}	
	}
	if(isPrint==false)
		printf("None");

	return 0;
}