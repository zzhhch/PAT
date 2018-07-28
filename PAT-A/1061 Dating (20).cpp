#include<cstdio>
#include<cstring>

char mp[7][5]={"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main()
{
	char str1[70],str2[70],str3[70],str4[70];
	scanf("%s%s%s%s",str1,str2,str3,str4);

	int i;
	for(i=0;i<65;i++)
	{
		if(str1[i]==str2[i]&&str1[i]-'A'>=0&&str1[i]-'G'<=0)
		{
			printf("%s ",mp[str1[i]-'A']);
			break;
		}
	}
	for(i++;i<65;i++)
	{
		if(str1[i]==str2[i])
		{
			if(str1[i]-'0'>=0&&str1[i]-'9'<=0)
			{
				printf("%02d:",str1[i]-'0');
				break;
			}				   
			else if(str1[i]-'A'>=0&&str1[i]-'N'<=0)
			{
				printf("%02d:", str1[i]-'A'+10);
				break;
			}
		}
	}
	for(i=0;i<65;i++)
	{
		if((str3[i]==str4[i]&&str3[i]-'a'>=0&&str3[i]-'z'<=0)||(str3[i]==str4[i]&&str3[i]-'A'>=0&&str3[i]-'Z'<=0))
		{
			printf("%02d",i);
			break;
		}
	}
	return 0;
}
