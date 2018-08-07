#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


struct Cars
{
	char id[8];
	int hh,mm,ss,num;
	bool is_in,is_valid=false;
}cars[10010];
struct Time
{
	char id[8];
	int hh,mm,ss;
}s_time[5010];
struct query
{
	int hh,mm,ss;
}qu[80010];

bool cmp(Cars a,Cars b)
{
	if(strcmp(a.id,b.id)!=0)
		return strcmp(a.id,b.id)<0;
	else if(a.hh!=b.hh)
		return a.hh<b.hh;
	else if(a.mm!=b.mm)
		return a.mm<b.mm;
	else
		return a.ss<b.ss;
}

bool cmp1(Cars a,Cars b)
{
	if(a.is_valid!=b.is_valid)
		return a.is_valid>b.is_valid;
	else if(a.hh!=b.hh)
		return a.hh<b.hh;
	else if(a.mm!=b.mm)
		return a.mm<b.mm;
	else if(a.ss!=b.ss)
		return a.ss<b.ss;
	else
		return strcmp(a.id,b.id)<0;
}
bool cmp2(Time a,Time b)
{
	if(a.hh!=b.hh)
		return a.hh>b.hh;
	else if(a.mm!=b.mm)
		return a.mm>b.mm;
	else if(a.ss!=b.ss)
		return a.ss>b.ss;
	else
		return strcmp(a.id,b.id)<0;
}
bool cmp_time(query a,Cars b)
{
	if(a.hh!=b.hh)
		return a.hh>b.hh;
	else if(a.mm!=b.mm)
		return a.mm>b.mm;
	else
		return a.ss>b.ss;
}


void count_time(Cars a,Cars b,int ans)
{
	int sum_time=0;
	Cars c=a;
	while(c.hh<b.hh||c.mm<b.mm||c.ss<b.ss)
	{
		sum_time++;
		c.ss++;
		if(c.ss==60)
		{
			c.ss=0;
			c.mm++;
		}
		if(c.mm==60)
		{
			c.mm=0;
			c.hh++;
		}
	}
	strcpy(s_time[ans].id,b.id);
	s_time[ans].hh+=sum_time/3600;
	s_time[ans].mm+=sum_time%3600/60;
	s_time[ans].ss+=sum_time%60;
}


int main()
{
	int n,k;
	scanf("%d %d",&n,&k);

	for(int i=0;i<n;i++)
	{
		char a[5];
		scanf("%s %d:%d:%d %s",cars[i].id,&cars[i].hh,&cars[i].mm,&cars[i].ss,a);
		if(strcmp(a,"in")==0)
			cars[i].is_in=true;
		else
			cars[i].is_in=false;
	}

	sort(cars,cars+n,cmp);
	printf("\n\n");
	for(int i=0;i<n;i++)
	{
		printf("%s %d:%d:%d %d\n",cars[i].id,cars[i].hh,cars[i].mm,cars[i].ss,cars[i].num);
	}
	int valid_num=0,time_num=0;
	for(int i=0;i<n;i++)
	{
		while(strcmp(cars[i].id,cars[i+1].id)==0)
		{
			if(cars[i].is_in==true&&cars[i+1].is_in==false)
			{
				cars[i].is_valid=cars[i+1].is_valid=true;
				count_time(cars[i],cars[i+1],time_num);
				valid_num+=2;
				i=i+2;

			}
			else
				i++;
		}
		time_num++;
	}
	sort(cars,cars+n,cmp1);
	printf("\n\n");
	for(int i=0;i<n;i++)
	{
		printf("%s %d:%d:%d %d\n",cars[i].id,cars[i].hh,cars[i].mm,cars[i].ss,cars[i].num);
	}
	int n_count=0;
	for(int i=0;i<valid_num;i++)
	{
		if(cars[i].is_in==true)
		{
			n_count++;
			cars[i].num=n_count;
		}
		else if(cars[i].is_in==false)
		{
			n_count--;
			cars[i].num=n_count;
		}
	}
	printf("\n\n");
	for(int i=0;i<n;i++)
	{
		printf("%s %d:%d:%d %d\n",cars[i].id,cars[i].hh,cars[i].mm,cars[i].ss,cars[i].num);
	}
	for(int i=0;i<k;i++)
	{
		int j=0;
		scanf("%d:%d:%d",&qu[i].hh,&qu[i].mm,&qu[i].ss);
		while(cmp_time(qu[i],cars[j]))
		{
			j++;
		}
		printf("%d\n",cars[j].num);
	}
	sort(s_time,s_time+time_num,cmp2);
	printf("\n\n");
	for(int i=0;i<time_num;i++)
	{
		printf("%s %d:%d:%d\n",s_time[i].id,s_time[i].hh,s_time[i].mm,s_time[i].ss);
	}
	for(int i=0;i<time_num;i++)
	{
		if(s_time[i+1].hh==s_time[i].hh
		 &&s_time[i+1].mm==s_time[i].mm
		 &&s_time[i+1].ss==s_time[i].ss)
		{
			printf("%s ",s_time[i].id);
		}
		else
		{
			printf("%s %02d:%02d:%02d",s_time[i].id,s_time[i].hh,s_time[i].mm,s_time[i].ss);
			break;
		}
	}
	//printf("%s %d:%d:%d %d  %d\n",cars[i].id,cars[i].hh,cars[i].mm,cars[i].ss,cars[i].is_in,cars[i].is_valid);

	return 0;
}