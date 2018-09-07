#include <cstdio>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=2010;

map<string,int> stringTonum;
map<int,string> numTostring;
map<string,int> Gang;
int G[maxn][maxn]={0};
int n,k,numPerson=0,weight[maxn]={0};
bool flag[maxn]={0};

int change(string a){
	if(stringTonum.find(a)!=stringTonum.end()){
		return stringTonum[a];
	}
	else{
		stringTonum[a]=numPerson;
		numTostring[numPerson]=a;
		return numPerson++;
	}
}

void DFS(int x,int &head,int &numMenber,int &totalWeight){
	numMenber++;
	flag[x]=true;
	if(weight[x]>weight[head]){
		head=x;
	}
	for(int i=0;i<numPerson;i++){
		if(G[x][i]>0){
			totalWeight+=G[x][i];
			G[x][i]=0;
			if(flag[i]==false){
				DFS(i,head,numMenber,totalWeight);
			}
		}
	}
}

void DFSTrave(){
	for(int i=0;i<numPerson;i++){
		if(flag[i]==false){
			int head=i,numMenber=0,totalWeight=0;
			DFS(i,head,numMenber,totalWeight);
			if(numMenber>2&&totalWeight>k){
				Gang[numTostring[head]]=numMenber;
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&k);
	string s1,s2;
	int w;
	for(int i=0;i<n;i++){
		cin>>s1>>s2>> w;
		int id1=change(s1);
		int id2=change(s2);
		weight[id1]+=w;
		weight[id2]+=w;
		G[id1][id2]+=w;
		G[id2][id1]+=w;
	}
	DFSTrave();
	cout<<Gang.size()<<endl;
	for(map<string,int>::iterator it=Gang.begin();it!=Gang.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}