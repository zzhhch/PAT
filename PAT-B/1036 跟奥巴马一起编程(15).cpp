#include <stdio.h>

int main()
{
	char x;
	int row,col;

	scanf("%d %c",&col,&x);
	if(col%2==0)
		row=col/2;
	else
		row=col/2+1;

	for(int i=1;i<=row;i++)
	{
		for(int j=1;j<=col;j++)
		   {
		   	   if(i==1||i==row)
		   	   {
		   	   	   printf("%c",x);
		   	   }
		   	   else
		   	   {
		   	   	   if(j==1||j==col)
		   	   	     printf("%c",x );
		   	   	   else
		   	   	     printf(" ");
		   	   }  
		   }
		   printf("\n");
	}	   
	return 0;
}
		   		




