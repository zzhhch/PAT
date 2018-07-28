#include<cstdio>


int main()
{
	int n,b,i=0,A[35]={0};
	scanf("%d %d",&n,&b);
	bool tcase=true;

	do
	{
		A[i++]=n%b;
		n=n/b;
	}while(n);//必须要考虑到0这个特殊情况
	for(int j=0;j<i/2;j++)
	{
		if(A[j]!=A[i-1-j])
		{
			tcase=false;
			break;
		}
	}
	if(tcase)
		printf("Yes\n");
	else
		printf("No\n");
	for(i=i-1;i>=0;i--)
	{
		printf("%d",A[i]);
		if(i!=0)
			printf(" ");
	}

	return 0;
}