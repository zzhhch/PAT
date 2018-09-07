

/*
#include <cstdio>
#include <map>
const int maxn=610;

map<int,int> nameToid;
map<int,int> idToname;
vector<int> G[maxn];
int n,m,k;

int main(){
	scanf("%d%d",&n,&m);
	int a,b,num=0;
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		if(a<0&&nameToid.find(a)==nameToid.end()){
			a=-a;
			nameToid[a]=300+num;
			idToname[300+num]=a;
		}else if(nameToid.find()==nameToid.end()){
			nameToid[a]=num;
			idToname[num]=a;
		}
		if(b<0&&nameToid.find(b)==nameToid.end()){
			b=-b;
			nameToid[b]=300+num;
			idToname[300+num]=b;
		}else if(nameToid.find(b)==nameToid.end()){
			nameToid[b]=num;
			idToname[num]=b;
		}
		int id1=nameToid[a],id2=nameToid[b];
		G[a].push_back(b);
		G[b].push_back(a);
	}
	scanf("%d",&k);
	int num;
	bool isSame=false;
	for(int i=0;i<k;i++){
		num=0;
		scanf("%d%d",&a,&b);
		if((a>0&&b>0)||(a<0&&b<0)) isSame=true;
		if(a<0) a=-a;
		if(b<0) b=-b;
		if(isSame){
			int id1=nameToid[a],id2=nameToid[b],s1,s2;
			for(int j=0;j<G[id1].size();j++){
				s1=nameToid[G[id1][j]];
				if((id1<300&&s1<300)||(id1>=300&&s1>=300)){
					for(in)
				}
			}
		}else{

		}
	}
}
*/