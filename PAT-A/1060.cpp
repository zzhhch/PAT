#include<iostream>
#include<cstring>
using namespace std;
int n;

string deal(string a,int &b)
{
	int k=0;
	while(a.length()>0&&a[0]=='0')
	{
		a.erase(a.begin());
	}
	if(a[0]=='.')
	{
		a.erase(a.begin());
		while(a.length()>0&&a[0]=='0')
		{
			a.erase(a.begin());
			b--;
		}
	}
	else
	{
		while(k<int(a.length())&&a[k]!='.')
		{
			k++;
			b++;
		}
		if(k<int(a.length()))
		{
			a.erase(a.begin()+k);
		}
	}
	if(a.length()==0)
	{
		b=0;
	}
	int num=0;
	k=0;
	string ans;
	while(num<n)
	{
		if(k<int(a.length()))
			ans+=a[k++];
		else
			ans+='0';
		num++;
	}
	return ans;
}

int main()
{
	string s1,s2,s3,s4;
	cin>>n>>s1>>s2;
	int e1=0,e2=0;
	s3=deal(s1,e1);
	s4=deal(s2,e2);
	if(s3==s4&&e1==e2)
	{
		cout<<"YES 0."<<s3<<"*10^"<<e1<<endl;
	}
	else
	{
		cout<<"NO 0."<<s3<<"*10^"<<e1<<" 0."<<s4<<"*10^"<<e2<<endl;
	}
	return 0;
}