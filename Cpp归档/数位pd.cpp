#include<cstdio>
int dp[10],C[15][15];
int table[10]={0,0,9,189,2889,38889,488889,5888889,68888889,788888889};
int quick(int x,int y){
	int a=1;
	while(y>0){
		if(y&1)a=a*x;
		y>>=1;
		x=x*x;
	}
	return a;
}
int f(int l,int m,bool flag,int be){//true��ʾ��0�������������ȡ��false��ʾ�ɶ��������������ȡ 
	if(l<0)return m;
	int i,ans=0,up=flag?9:dp[l];
	for(i=up;i>0;i--){
		if(i==dp[l]&&!flag)
			ans+=f(l-1,m,0,be);
		else for(int j=0;j<=l;j++)
			ans+=quick(9,l-j)*C[l][j]*(m+j);
	}
	if(l!=be){
		if(flag||dp[l]>0)ans+=f(l-1,m+1,1,be);//ǰ��������ȡ||4388->4088���Կ�ʼ���ȡ 
		else ans+=f(l-1,m+1,0,be);//�������ȡ 
	}
	return ans;
}
int main(){
	int n,i,j,be;
	for(i=0;i<=10;i++)
		for(j=0;j<=i;j++)
			C[i][j]=(j==i||j==0)?1:(C[i-1][j-1]+C[i-1][j]);
	scanf("%d",&n);
	for(i=0;i<10;i++){
		dp[i]=n%10;
		n/=10;
	}//��λ�ڵ�0�� 
	for(be=10;be>=0;be--)if(dp[be]!=0)break;
	printf("%d",f(be,0,0,be)+table[be]);
	return 0;
}
