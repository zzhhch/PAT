#include<iostream>
#include<string>
#include<map>
using namespace std;

bool check(char a)
{
	if(a>='A'&&a<='Z')
		return true;
	if(a>='a'&&a<='z')
		return true;
	if(a>='0'&&a<='9')
		return true;
	return false;
}
int main()
{
	map<string,int> strToNum;
	string str;
	getline(cin,str);
	int i=0;
	while(i<str.length())
	{
		string word;
		while(i<str.length()&&check(str[i])==true)
		{
			if(str[i]>='A'&&str[i]<='Z')
			{
				str[i]+=32;
			}
			word+=str[i];
			i++;
		}
		if(word!="")
		{
			if(strToNum.find(word)!=strToNum.end())
				strToNum[word]++;
			else
				strToNum[word]=1;
		}
		while(i<str.length()&&check(str[i])==false)
		{
			i++;
		}
	}
	string ans;
	int Max=0;
	for(map<string,int>::iterator it=strToNum.begin();it!=strToNum.end();it++)
	{
		if(it->second>Max)
		{
			ans=it->first;
			Max=it->second;
		}
	}
	cout<<ans<<" "<<Max<<endl;
	return 0;

}