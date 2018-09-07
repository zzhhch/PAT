#include <iostream>
#include <algorithm>
using namespace std;

string add(string a){
	string ans,b=a;
	reverse(b.begin(),b.end());
	int len=a.length(),carry=0;
	for(int i=0;i<len;i++){
		int num=(a[i]-'0'+b[i]-'0')+carry;
		carry=0;
		if(num>=10){
			num-=10;
			carry=1;
		}
		ans+=char(num+'0');
	}
	if(carry==1) ans+='1';
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){
	string s;
	cin>>s;
	int cnt=0;
	while(cnt<10){
		string t=s;
		reverse(t.begin(),t.end());
		if(t==s){
			cout<<s<<" is a palindromic number."<<endl;
			break;
		}else{
			cout<<s<<" + "<<t<<" = "<<add(s)<<endl;
			s=add(s);
			cnt++;
		}

	}
	if(cnt==10)
		cout<<"Not found in 10 iterations.";
	return 0;
}
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1010;

char origin[maxn],ans[maxn],temp[maxn];

void change(char a[]){
	int len=strlen(a),j=0;
	for(int i=len-1;i>=0;i--){
		temp[j++]=a[i];
	}
}

bool isPali(char a[]){
	int len=strlen(a);
	for(int i=0;i<len/2;i++){
		if(a[i]!=a[len-i-1]){
			return false;
		}
	}
	return true;
}

char * Add(char a[],char b[]){
	char s[maxn];
	int len=strlen(a),num=0;
	bool flag=false;
	for(int i=len-1;i>=0;i--){
		int x=(a[i]-'0');
		int y=(b[i]-'0');
		int c=x+y;
		if(c>=10){
			if(flag==true){
				s[num++]=(c%10+1)+'0';
			}else{
				s[num++]=(c%10)+'0';
			}
			flag=true;
		}else{
			if(flag==true){
				s[num++]=c+1+'0';
			}else{
				s[num++]=c+'0';
			}
			flag=false;
		}
	}
	return s;
}
int main(){
	scanf("%s",origin);
	bool x=false;
	for(int i=0;i<10;i++){
		temp=reverse(origin,origin+strlen(origin));
		ans=Add(origin,temp);
		ans=reverse(ans,ans+strlen(ans));
		printf("%s + %s = %s\n",origin,temp,ans);
		if(ifPali(ans)){
			x=true;
			printf("%s is a palindromic number.",ans);
			break;
		}
		origin=ans;
	}
	if(!x){
		printf("Not found in 10 iterations");
	}
	return 0;
}
*/