//1�ڸ�Լ1.5s,1000���Լ0.3s 
//n�����������Դ���x/lnx,1���ڲ���5761455��1000����664579��100���ڲ�����78498
#include<cstdio>
#include<cstring>
#include<cmath>
bool vis[100005];
int prime[100000];
void build_prime(){
	int n=30000;
	int m=sqrt(n+0.5);
	for(int i=2;i<=m;i++)
		if(!vis[i])
			for(int j=i*i;j<=n;j+=i)
				vis[j]=true;
	int k=0;
	for(int i=2;i<=n;i++)if(!vis[i])prime[k++]=i;
	printf("%d %d\n",k,prime[k-1]); 
	for(int i=0; i<k; i++)
		printf("%d %d\n",i, prime[i]);
} 
int main(){
	//freopen("primenumber.txt","w",stdout);
	build_prime(); 
	
	return 0;
}

