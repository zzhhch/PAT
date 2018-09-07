#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

string trs(int a)
{
	if(a==1)
		return "1";
	else if(a==2)
		return "2";
	else if(a==3)
		return "3";
	else if(a==4)
		return "4";
	else if(a==5)
		return "5";
	else if(a==6)
		return "6";
	else if(a==7)
		return "7";
	else if(a==8)
		return "8";
	else
		return "9";
}
int main()
{
	int d,n;
	string str,temp;
	scanf("%d%d",&d,&n);
	str+=trs(d);
	for(int i=2;i<=n;i++)
	{	
		int count=1;
		for(int j=0;j<str.size();j++)
		{
			
			if(str[j+1]==str[j])
			{
				count++;
			}
			else
			{
				temp+=str[j];
				temp+=trs(count);
				count=1;
			}
		}
		str=temp;
		temp.clear();
	}
	cout<<str<<endl;
	return 0;
}