#include<cstdio>
#include<stack>
using namespace std;

const int maxn=1010;
int arr[maxn];
stack<int> st;

int main()
{

	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	while(k--)
	{
		while(!st.empty())
		{
			st.pop();
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&arr[i]);
		}
		int cur=1;
		bool flag=true;
		for(int i=1;i<=m;i++)
		{
			st.push(i);
			if(int(st.size())>n)
			{
				flag=false;
				break;
			}
			while(!st.empty()&&st.top()==arr[cur])
			{
				st.pop();
				cur++;
			}
		}
		if(st.empty()&&flag==true)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}