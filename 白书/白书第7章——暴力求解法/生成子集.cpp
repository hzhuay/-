#include<cstdio>
/*void print_subset(int n,int *A,int cur){//�������취 
	for(int i=0;i<cur;i++)printf("%d",A[i]);
	puts("");
	int s=cur?A[cur-1]+1:0;
	for(int i=s;i<n;i++){
		A[cur]=i;
		print_subset(n,A,cur+1);
	}
}*/
/*void print_subset(int n,int *B,int cur){//λ������ 
	if(cur==n){
		for(int i=0;i<cur;i++)
			if(B[i])printf("%d",i);
		puts("");
		return;
	}
	B[cur]=1;
	print_subset(n,B,cur+1);
	B[cur]=0;
	print_subset(n,B,cur+1);
}*/
void print_subset(int n,int s){//�����Ʒ� 
	for(int i=0;i<n;i++)
		if(s&(1<<i))printf("%d",i);
	puts("");
}
int main(){
	int A[10]={1,2,4,8,16};
	int n=5;
	for(int i=0;i<(1<<n);i++)
		print_subset(n,i);
	return 0;
}
