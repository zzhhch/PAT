#include<stdio.h>

char A[3]={'B','C','J'};
int times_A[3]={0},times_B[3]={0};
int hand_A[3]={0},hand_B[3]={0};
//用以将字符转化成数字
int change(char c)
{
	if(c=='B')
		return 0;
	if(c=='C')
		return 1;
	if(c=='J')
		return 2;
}
int main()
{
	int n,c1,c2;
	char x,y;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		getchar();//因为scanf会读入\n 所以用getchar消除\n
		scanf("%c %c",&x,&y);
		c1=change(x);
		c2=change(y);
        if((c1+1)%3==c2)
        {
        	times_A[0]++;
        	times_B[2]++;
        	hand_A[c1]++;
        }
        else if(c1==c2)
        {
        	times_A[1]++;
        	times_B[1]++;
        }
        else
        {
        	times_A[2]++;
        	times_B[0]++;
        	hand_B[c2]++;
        }
	}
	printf("%d %d %d\n",times_A[0],times_A[1],times_A[2]);
	printf("%d %d %d\n",times_B[0],times_B[1],times_B[2]);
	int id1=0,id2=0;
	for(int i=0;i<3;i++)
	{
		if(hand_A[i]>hand_A[id1])
			id1=i;
		if(hand_B[i]>hand_B[id2])
			id2=i;
	}
	printf("%c %c\n",A[id1],A[id2]);

	return 0;
}