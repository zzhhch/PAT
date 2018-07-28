#include <stdio.h>

int main()
{
	int socer[100000]={0};
	int number,num,soc;
  
	scanf("%d",&number);
	int a=number;
	while(number--)
	{
		scanf("%d %d",&num,&soc);
		socer[num]+=soc;
	}
    int max1=a,max2=socer[a];
    while(--a)
    {
    	if(socer[a]>max2)
    	{
    		max2=socer[a];
    		max1=a;
    	}
    }
    printf("%d %d",max1,max2 );

    return 0;
}

