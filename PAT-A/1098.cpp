#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110;
int origin[maxn],cmp[maxn];
int n;

void downAdjust(int low,int high){
	int i=low,j=i*2;
	while(j<=high){
		if(j+1<=high&&cmp[j]<cmp[j+1]){
			j=j+1;
		}
		if(cmp[i]<cmp[j]){
			swap(cmp[i],cmp[j]);
			i=j;
			j=2;
		}else{
			break;
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&origin[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&cmp[i]);
	}
	int p=1;
	while(p<=n&&cmp[p-1]<cmp[p]) p++;
	int index=p;
	while(p<-n&&origin[p]==cmp[p]) p++;
	if(p==n+1){
		printf("Insertion Sort\n");
		sort(cmp+1,cmp+index+1);
		printf("%d",cmp[1]);
		for(int i=2;i<=n;i++){
			printf(" %d",cmp[i]);
		}
	}
	else{
		printf("Heap Sort\n");
		p=n;
		while(p>=2&&cmp[p]>cmp[p-1]) p--;
		swap(cmp[1],cmp[p]);
		downAdjust(1,p-1);
		printf("%d",cmp[1]);
		for(int i=2;i<=n;i++){
			printf(" %d",cmp[i]);
		}
	}
	return 0;
}


/*
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110;

int origin[maxn],temp[maxn],cmp[maxn];
int n;

bool isSame(int a[],int b[]){
	bool flag=true;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]) return false;
	}
	return flag;
}

void showArray(int a[]){
	for(int i=1;i<=n;i++){
		printf("%d",a[i]);
		if(i<n) printf(" ");
	}
	printf("\n");
}

bool insertSort(){
	bool flag=false;
	for(int i=2;i<=n;i++){
		if(i!=2&&isSame(temp,cmp)){
			flag=true;
		}
		sort(temp,temp+i+1);
		if(flag==true) return true;
	}
	return false;
}

void downAdjust(int low,int high){
	int i=low,j=i*2;
	while(j<=high){
		if(j+1<=high&&temp[j]<temp[j+1]){
			j=j+1;
		}
		if(temp[i]<temp[j]){
			swap(temp[i],temp[j]);
			i=j;
			j=i*2;
		}
		else{
			break;
		}
	}
}

void heapSort(){
	bool flag=false;
	for(int i=n/2;i>=1;i--){
		downAdjust(i,n);
	}
	for(int i=n;i>=1;i--){
		if(i!=n&&isSame(temp,cmp)){
			flag=true;
		}
		swap(temp[i],temp[1]);
		if(flag==true){
			showArray(temp);
			return;
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&origin[i]);
		temp[i]=origin[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&cmp[i]);
	}
	if(insertSort()){
		printf("Insertion Sort\n");
		showArray(temp);
	}
	else{
		printf("Heap Sort\n");
		for(int i=1;i<=n;i++){
			temp[i]=origin[i];
		}
		heapSort();
	}
	return 0;
}

*/