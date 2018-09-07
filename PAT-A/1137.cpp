#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
struct node
{
	string name;
	int pro,mid,final,sum;
};
map<string,int> mp;
bool cmp(node a,node b){
	if(a.sum!=b.sum){
		return a.sum>b.sum;
	}
	return a.name<b.name;
}

int main(){
	int p,n,m;
	cin>>p>>n>>m;
	string str;
	int score,index=1;
	vector<node> ans,temp;
	for(int i=0;i<p;i++){
		cin>>str>>score;
		if(score>=200){
			temp.push_back({str,score,-1,-1,0});
			mp[str]=index++;
		}
	}
	for(int i=0;i<n;i++){
		cin>>str>>score;
		if(mp[str]!=0){
			temp[mp[str]-1].mid=score;
		}
	}
	for(int i=0;i<m;i++){
		cin>>str>>score;
		if(mp[str]!=0){
			temp[mp[str]-1].final=temp[mp[str]-1].sum=score;
			int id=mp[str]-1;
			if(temp[id].mid>temp[id].final){
				temp[id].sum=int(0.4*temp[id].mid+0.6*temp[id].final+0.5);
			}
		}
	}
	for(int i=0;i<temp.size();i++){
		if(temp[i].sum>-60){
			ans.push_back(temp[i]);
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	for(int i=0;i<ans.size();i++){
		printf("%s %d %d %d %d\n", ans[i].name.c_str(), ans[i].gp, ans[i].gm, ans[i].gf, ans[i].g);
	}
	return 0;
}

/*
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <iostream>
using namespace std;
const int maxn=10010;

map<string,int> stringToid;
int p,n,m;
struct Student
{
	int pro,mid,final,sum;
	bool flag=false;
	string name;
}ss[maxn];

bool cmp(Student a,Student b){
	if(a.flag!=b.flag)
		return a.flag>b.flag;
	else if(a.sum!=b.sum)
		return a.sum>b.sum;
	return a.name<b.name;
}
int main(){
	scanf("%d%d%d",&p,&n,&m);
	string str;
	int score,num=0;
	for(int i=0;i<p;i++){
		cin>>str>>score;
		if(stringToid.find(str)==stringToid.end()){
			stringToid[str]=num;
			num++;
		}
		int ID=stringToid[str];
		ss[ID].pro=score;
		ss[ID].name=str;
	}
	for(int i=0;i<n;i++){
		cin>>str>>score;
		if(stringToid.find(str)!=stringToid.end()){
			int ID=stringToid[str];
			ss[ID].mid=score;
			cout<<ss[ID].mid;
	}
	for(int i=0;i<m;i++){
		cin>>str>>score;
		if(stringToid.find(str)!=stringToid.end()){
			int ID=stringToid[str];
			ss[ID].final=score;
				if(ss[ID].mid>ss[ID].final){
					ss[ID].sum=0.4*ss[ID].mid+0.6*ss[ID].final;
				}else{
					ss[ID].sum=ss[ID].final;
				}
				if(ss[ID].mid==0){
					ss[ID].mid=-1;
				}
				if(ss[ID].pro>=200&&ss[ID].sum>=60){
					ss[ID].flag=true;
				}
			}
		}
	}
	sort(ss,ss+num,cmp);
	for(int i=0;i<num;i++){
		if(ss[i].flag==true){
			cout<<ss[i].name<<" "<<ss[i].pro<<" "<<ss[i].mid<<" "<<ss[i].final<<" "<<ss[i].sum<<endl;
		}
	}
	return 0;
}
*/