#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1005;
int n,d[maxn];
bool G[maxn][maxn];
struct Rectangle{
	int w,h;
}rec[maxn];
int dp(int i){
	int &ans=d[i];//������������������ 
	if(ans>0)return ans;
	ans=1;
	for(int j=0;j<n;j++)
		if(G[i][j])ans=max(ans,dp(j)+1);
	return ans;
}
void build_Graph(){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(rec[i].w>rec[j].w&&rec[i].h>rec[j].h)
				G[i][j]=1;//i���԰���j 	
}
void print_ans(int i){//����ж�⣬���α�ŵ��ֵ�����С 
	printf("%d ",i+1);//��Ŵ�1��ʼ
	for(int j=0;j<n;j++)
		if(G[i][j]&&d[i]==d[j]+1){
			print_ans(j);
			break;
		}
}
int main(){
	int kase;
	scanf("%d",&kase);
	while(kase--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&rec[i].w,&rec[i].h);
			if(rec[i].h>rec[i].w)swap(rec[i].h,rec[i].w);
		}
		build_Graph();
		int ans=0;
		for(int i=1;i<n;i++)
			if(d[ans]<dp(i))ans=i;
		printf("%d\n",d[ans]);
		print_ans(ans);
		memset(d,0,sizeof(d));
		memset(G,0,sizeof(G));
		memset(rec,0,sizeof(rec));
	}
	return 0;
}
