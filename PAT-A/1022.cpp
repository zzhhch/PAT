#include<iostream>
#include<map>
#include<string>
#include<set>
using namespace std;

map<string,set<int> > mpTitle,mpAuthor,mpKeys,mpPublish,mpYear;

void Print(map<string,set<int> > &mp,string &str)
{
	if(mp.find(str)==mp.end())
		printf("Not Found\n");
	else
	{
		for(set<int>::iterator it=mp[str].begin();it!=mp[str].end();it++)
		{
			printf("%07d\n",*it);
		}
	}
}

int main()
{
	int n,id,m;
	scanf("%d",&n);
	string title,author,keys,publish,year,key;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&id);
		char c=getchar();
		getline(cin,title);
		mpTitle[title].insert(id);
		getline(cin,author);
		mpAuthor[author].insert(id);
		while(cin>>keys)
		{
			mpKeys[keys].insert(id);
			c=getchar();
			if(c=='\n')
				break;
		}
		getline(cin,publish);
		mpPublish[publish].insert(id);
		getline(cin,year);
		mpYear[year].insert(id);
	}
	scanf("%d",&m);
	string temp;
	for(int i=0;i<m;i++)
	{
		int k;
		scanf("%d: ",&k);
		getline(cin,temp);
		cout<<k<<": "<<temp<<endl;
		if(k==1)
			Print(mpTitle,temp);
		else if(k==2)
			Print(mpAuthor,temp);
		else if(k==3)
			Print(mpKeys,temp);
		else if(k==4)
			Print(mpPublish,temp);
		else
			Print(mpYear,temp);
	}
	return 0;
}