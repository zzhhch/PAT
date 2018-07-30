#include<cstdio>
#include<algorithm>

using namespace std;

struct pepole
{
	long id;
	int  virtue;
	int  talent;
	int  sum;
	int  flag;
}pp[100010],temp;

bool cmp(pepole a,pepole b)
{
	if(a.flag!=b.flag)
		return a.flag<b.flag;
	else if(a.sum!=b.sum)
		return a.sum>b.sum;
	else if(a.virtue!=b.virtue)
		return a.virtue>b.virtue;
	else 
		return a.id<b.id;
}
int main()
{
	int n,l,h,k;
	scanf("%d%d%d",&n,&l,&h);
	k=n;

	for(int i=0;i<n;i++)
	{
		scanf("%ld%d%d",&pp[i].id,&pp[i].virtue,&pp[i].talent);
			pp[i].sum=pp[i].virtue+pp[i].talent;
			if(pp[i].virtue<l||pp[i].talent<l)
			{
				pp[i].flag=5;
				k--;
			}	
			else if(pp[i].virtue>=h&&pp[i].talent>=h)
				pp[i].flag=1;
			else if(pp[i].virtue>=h&&pp[i].talent<h)
				pp[i].flag=2;
			else if(pp[i].virtue<h&&pp[i].talent<=pp[i].virtue)
				pp[i].flag=3;
			else if(pp[i].virtue<h&&pp[i].talent>pp[i].virtue)
				pp[i].flag=4;
	}
	sort(pp,pp+n,cmp);
	/*
	sort(首地址，末地址，比较条件)  一般根据数据采用最合适的排序，不会超过O(n^2)
	*/

	printf("%d\n",k);
	for(int i=0;i<k;i++)
		printf("%ld %d %d\n",pp[i].id,pp[i].virtue,pp[i].talent);
	return 0;
}