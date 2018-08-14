#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int hashTable[80]={0};

int change(char a)
{
	if(a>='0'&&a<='9')
		return a-'0';
	if(a>='a'&&a<='z')
		return a-'a'+10;
	if(a>='A'&&a<='Z')
		return a-'A'+36;
}
int main()
{
	char s1[1010],s2[1010];
	scanf("%s%s",s1,s2);
	int len1=strlen(s1),len2=strlen(s2);

	for(int i=0;i<len1;i++)
	{
		int k=change(s1[i]);
		hashTable[k]++;
	}
	int miss=0;
	for(int i=0;i<len2;i++)
	{
		int id=change(s2[i]);
		hashTable[id]--;
		if(hashTable[id]<0)
			miss++;
	}

	if(miss>0)
		printf("No %d\n",miss);
	else
		printf("Yes %d\n",len1-len2);

	return 0;
}