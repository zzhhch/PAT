#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n,a,start[100010];
	scanf("%d",&n);
	int right=n-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		start[a]=i;
		if(a==i&&a!=0)
			right--;
	}
	int num=0,k=1;
	while(right>0)
	{
		if(start[0]==0)
		{
			while(k<n)
			{
				if(start[k]!=k)
				{
					swap(start[0],start[k]);
					num++;
					break;
				}
				k++;
			}
		}
		while(start[0]!=0)
		{
			swap(start[0],start[start[0]]);
			num++;
			right--;
		}
		
	}

	printf("%d",num);

	return 0;
}