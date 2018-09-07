#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxm=1300;
const int maxn=130;
const int maxl=65;

struct node
{
	int x,y,z;
}Node;
bool flag[maxm][maxn][maxl]={false};
int ipexl[maxm][maxn][maxl];
int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={1,-1,0,0,0,0};
int n,m,slice,T;

bool judge(int x,int y,int z)
{
	if(x>=n||x<0||y>=m||y<0||z>=slice||z<0)
		return false;
	if(flag[x][y][z]==true||ipexl[x][y][z]==0)
		return false;
	return true;
}

int BFS(int x,int y,int z)
{
	int tot=0;
	queue<node> q;
	Node.x=x;
	Node.y=y;
	Node.z=z;
	q.push(Node);
	flag[x][y][z]=true;
	while(!q.empty())
	{
		node top=q.front();
		q.pop();
		tot++;
		for(int i=0;i<6;i++)
		{
			int newX=top.x+X[i];
			int newY=top.y+Y[i];
			int newZ=top.z+Z[i];
			if(judge(newX,newY,newZ))
			{
				Node.x=newX;
				Node.y=newY;
				Node.z=newZ;
				q.push(Node);
				flag[newX][newY][newZ]=true;
			}
		}
		
	}
	if(tot>=T)
			return tot;
		else
			return 0;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&slice,&T);
	for(int z=0;z<slice;z++)
		for(int x=0;x<n;x++)
			for(int y=0;y<m;y++)
			{
				scanf("%d",&ipexl[x][y][z]);
			}
	int ans=0;
	for(int z=0;z<slice;z++)
		for(int x=0;x<n;x++)
			for(int y=0;y<m;y++)
			{
				if(ipexl[x][y][z]==1&&flag[x][y][z]==false)
				{
					ans+=BFS(x,y,z);
				}
			}
	printf("%d\n",ans);
	return 0;
}