#include<cstdio>

int count[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char mp[11]={'1','0','X','9','8','7','6','5','4','3','2'};


int main()
{
	int n,sum;
	char id[20];
	bool tcase=true,Isnum,Isright;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		scanf("%s",id);
		getchar();
		sum=0;
		Isnum=true;
		Isright=true;
		for(int i=0;i<17;i++)
		    {
                if(id[i]-'0'<0&&id[i]-'0'>9)
				{
					Isnum=false;
				    Isright=false;
				    break;
				}    
			    else
			    {
				    sum=sum+(id[i]-'0')*count[i];
			    }
			}
		if(Isnum)
		{
			sum%=11;
			if(mp[sum]!=id[17])
				Isright=false;
		}
		if(!Isright)
		{
			tcase=false;
			printf("%s\n",id);
		}		
	}
	if(tcase)
		printf("All passed");

	return 0;

}
