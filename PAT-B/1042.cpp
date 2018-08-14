#include<cstdio>
#include<algorithm>
using namespace std;

int hashTable[30]={0};

int main()
{
	char a;
	while((a=getchar())!='\n')
	{
		if(a>='a'&&a<='z')
			hashTable[a-'a']++;
		else if(a>='A'&&a<='Z')
			hashTable[a-'A']++;
	}
	int k=0;
	for(int i=1;i<30;i++)
	{
		if(hashTable[i]>hashTable[k])
			k=i;
		//printf("%d\n",hashTable[i]);
	}
	printf("%c %d\n",'a'+k,hashTable[k]);

	return 0;
}