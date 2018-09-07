

//1033 未解决

//1067 ac

//1038 ac  		 用的string

//1085 24/25

//1010 

//1044

//1048 多种方法

//1089

//1029

//1101

//1051 ac		stack,注意判断栈空

//1056 

//1003B

//1039 ac 		vector,用hash把名字转换成int

//1047 ac       用string会超时,要用char[]

//1063 ac		set答案

//1060 ac   	string答案

//1100 ac    	map答案

//1054 ac		map

//1071 ac		map

//1022 ac		map<string,set<int>>

//1056 ac		queue

//1103 ac		DFS

//1074 19/25

//1032 24/25	一个测试点超时 //用bool标记结点

//1052 ac		link

//1097 ac		link  	记住link的模板


//1091 ac

//1086 ac

//1102 ac

//1079 ac

//1090 ac

//1094 ac

//1106 ac

//1004 ac

//1053 ac

//1043 16/25

//DFS
void DFS(int index,int nowK,int sum,int facsum)
{
	if(是否满足所需条件)
	{
		更新结果;
	}
	//选择此层
	DFS(index,nowK+1,sum+,facsum+)
	//不选择此层
	DFS(index+1,nowK,sum,facsum)
}



#include<cstido>
#include<queue>
using namespace std;

struct node
{
	int x,y,z;
}Node;

int ipexl[1300][130][65];
bool flag[1300][130][65]={false};
int X[6]={1,-1,0,0,0,0};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={0,0,0,0,1,-1};
int m,n,l,T;

bool judge(int x,int y,int z)
{
	if(x>=m||x<0||y>=n||y<0||z>=l||z<0)
		return false;
	if(ipexl[x][y][z]==0||flag[x][y][z]==true)
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
	scanf("%d%d%d%d",&m,&n,&l,&T);
	for(int z=0;z<l;z++)
		for(int x=0;x<m;x++)
			for(int y=0;y<n;y++)
				scanf("%d",&ipexl[x][y][z]);
			int ans=0;
			for(int z=0;z<l;z++)
				for(int x=0;x<m;x++)
					for(int y=0;y<n;y++)
					{
						if(ipexl[x][y][z]==1&&flag[x][y][z]==false)
						{
							ans+=BFS(x,y,z);
						}
					}
					printf("%d\n",ans);
					return 0;
				}


//1147
#include<cstdio>
#include<vector>	
				using namespace std;
				const int maxn=1010;

				vector<int> p[maxn],q[maxn],ans;

				int main()
				{
					int n,m,a,b,k,temp;
					scanf("%d%d",&n,&m);
					for(int i=0;i<m;i++)
					{
						scanf("%d%d",&a,&b);
						p[a].push_back(b);
						q[b].push_back(a);
					}
					scanf("%d",&k);
					for(int i=0;i<k;i++)
					{
						int j;
						for(j=0;j<n;j++)
						{
							scanf("%d",&temp);
							if(q[temp].size()==0)
							{
								for(int x=0;x<p[temp].size();x++)
								{	
									int flag=p[temp][x];
									vector<int>::iterator it=q[flag].begin();
									for(;it!=q[flag].end();it++)
									{
										if(*it==temp)
											q[flag].erase(it);
									}
								}
							}
							else
							{
								break;
							}
						}
						if(j==n-1)
							ans.push_back(i);
					}
					for(int i=0;i<ans.size();i++)
					{
						printf("%d",ans[i]);
						if(i!=ans.size()-1)
							printf(" ");
					}

					return 0;
				}				