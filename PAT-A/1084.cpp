#include<cstdio>
#include<cstring>

bool isPrint[130]={false};
int main()
{
	char origin[90],type_out[80];

	scanf("%s%s",origin,type_out);

	int len1=strlen(origin),len2=strlen(type_out);

	for(int i=0;i<len1;i++)
	{
		int j=0;
		char a,b;
		for(j=0;j<len2;j++)
		{
			a=origin[i];
			b=type_out[j];
			if(a-'a'>=0&&a-'z'<=0)
				a-=32;
			if(b-'a'>=0&&b-'z'<=0)
				b-=32;
			if(a==b)
				break;
		}
		if(j==len2&&isPrint[a]==false)
		{
			printf("%c",a);
			isPrint[a]=true;
		}
	}
	
	return 0;
}