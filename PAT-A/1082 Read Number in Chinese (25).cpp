#include<cstdio>
#include<cstring>

char mp1[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char mp2[5][5]={"Shi","Bai","Qian","Wan","Yi"};
int main()
{
	char input[15];
	scanf("%s",input);
	int len=strlen(input);
	int left=0,right=len-1;

	if(input[0]=='-')
	{
        printf("Fu");
        left++;
	}
	while(left+4<right)
	{
		right-=4;
	}
	while(left<len)
	{
		bool flag=false;
		bool Isprint=false;

		while(left<=right)
		{
			if(left>0&&input[left]=='0')
				flag=true;
			else 
			{
				if(flag==true)
			    {
				    printf(" ling");
				    flag=false;
			    }
			    if(left>0)
				    printf(" ");
			    printf("%s",mp1[input[left]-'0']);
			    Isprint=true;
			    if(left!=right)
				    printf(" %s",mp2[right-left-1]);
			}
			left++;
		}
		if(Isprint==true&&right!=len-1)
			printf(" %s",mp2[(len-1-right)/4+2]);
		right+=4;
	}
	return 0;
}
