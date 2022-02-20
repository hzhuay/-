#include<cstdio>
#include<cmath>
int euler_phi(int n){//С��n����n���ʵ��������� 
	int m=(int)sqrt(n+0.5),ans=n;
	for(int i=2;i<=m;i++)
		if(n%i==0){
			ans=ans/i*(i-1);
			while(n%i==0)n/=i;
		}
	if(n>1)ans=ans/n*(n-1);
	return ans;
}
int main(){
	long long n;
	while(scanf("%lld",&n)!=EOF){
		if(n==1)puts("1");
		else printf("%lld\n",euler_phi(n)*n/2);//С��n����n���ʵ������ĺ� 
	}
	return 0;
}
