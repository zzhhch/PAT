#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int mp[25];

struct bill
{
	char id[25];
	int month,dd,hh,mm;
	bool online;
}billn[1010],temp;

bool cmp(bill a,bill b)
{
	if(strcmp(a.id,b.id)!=0)
		return strcmp(a.id,b.id)<0;
	else if(a.month!=b.month)
		return a.month<b.month;
	else if(a.dd!=b.dd)
		return a.dd<b.dd;
	else if(a.hh!=b.hh)
		return a.hh<b.hh;
	else
		return a.mm<b.mm;
}
//
get_ans(int on,int off,int &time_n,int &money_n)
{
	temp=billn[on];
	while(temp.dd<billn[off].dd||temp.hh<billn[off].hh||temp.mm<billn[off].mm)
	{
		time_n++;
		money_n+=mp[temp.hh];
		temp.mm++;
		if(temp.mm>=60)
		{
			temp.mm=0;
			temp.hh++;
		}
		if(temp.hh>=24)
		{
			temp.hh=0;
			temp.dd++;
		}
	}
}

int main()
{
	int n;
	for(int i=0;i<24;i++)
		scanf("%d",&mp[i]);
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		char t_on[10];
		scanf("%s %d:%d:%d:%d %s",billn[i].id,&billn[i].month,&billn[i].dd,&billn[i].hh,&billn[i].mm,t_on);
		if(strcmp(t_on,"on-line")==0)
			billn[i].online=true;
		else
			billn[i].online=false;
	}
	sort(billn,billn+n,cmp);

	int on=0,off,next;
	for(int i=0;i<n;i++)
	{
		int isPrint=0;
		next=on;
		while(next<n&&strcmp(billn[on].id,billn[next].id)==0)
		{
			if(isPrint==0&&billn[next].online==true)
				isPrint=1;
			else if(isPrint==1&&billn[next].online==false)
				isPrint=2;
			next++;
		}
		if(isPrint<2)
		{
			on=next;
			continue;
		}
		int Allmoney=0;
		printf("%s %d\n",billn[on].id,billn[on].month);
		while(on<next)
		{
			while(on<next-1&&!(billn[on].online==true&&billn[on+1].online==false))
			{
				on++;
			}
			off=on+1;
			if(off==next)
			{
				on=next;
				break;
			}
			printf("%02d:%02d:%02d ",billn[on].dd,billn[on].hh,billn[on].mm);
			printf("%02d:%02d:%02d ",billn[off].dd,billn[off].hh,billn[off].mm);
			int time_n=0,money_n=0;
			get_ans(on,off,time_n,money_n);
			Allmoney+=money_n;
			printf("%d %.2f\n",time_n,money_n/100.0);
			on=off+1;
		}
		printf("Total amount: $%.2f\n",Allmoney/100.0);
	}
	return 0;
}