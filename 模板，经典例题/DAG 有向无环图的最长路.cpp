#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1005;
int n,d[maxn];
bool G[maxn][maxn];
int dp(int i){
	int &ans=d[i];//������������������ 
	if(ans>0)return ans;
	ans=1;
	for(int j=0;j<n;j++)
		if(G[i][j])ans=max(ans,dp(j)+1);
	return ans;
}
void print_ans(int i){//����ж�⣬���α�ŵ��ֵ�����С
	printf("%d ",i+1);//��Ŵ�1��ʼ
	for(int j=0;j<n;j++)
		if(G[i][j]&&d[i]==d[j]+1){
			print_ans(j);
			break;
		}
}
void build_Graph(){}//����Ҫ����ͼ  
int main(){
	int kase;
	scanf("%d",&kase);
	while(kase--){
		scanf("%d",&n);
		int tmp1,tmp2; 
		for(int i=0;i<n;i++){
			scanf("%d%d",&tmp1,&tmp2);
			G[tmp1][tmp2]=G[tmp2][tmp1]=1;//����ͼ���߶���˫�� 
		}
		int ans=0;
		for(int i=1;i<n;i++)
			if(d[ans]<dp(i))ans=i;
		printf("%d\n",d[ans]);
		print_ans(ans);//���·�� 
		memset(d,0,sizeof(d));
		memset(G,0,sizeof(G));
	}
	return 0;
}
