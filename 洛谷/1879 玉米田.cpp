#include<cstdio>
#include<algorithm>
using namespace std;
const int P=1000000000;
int a[15][15],F[15],dp[15][1<<12+5];//dp[i][j]ָ��i��״̬Ϊjʱ��ǰi�еĺϷ������� 
bool mark[1<<12+5];//mark[i]��¼i���״̬�Ƿ�Ϸ� 
int main(){
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			F[i]=(F[i]<<1)+a[i][j];
		}
	int M=1<<m;
	for(int i=0;i<M;i++)
		mark[i]=(!(i&(i<<1)))&&(!(i&(i>>1)));//Ԥ���� 
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<M;j++){//ö��һ�����п��ܵ�״̬ 
			if(mark[j]&&((j&F[i])==j)){//���״̬�Ϸ�&&���и��ֲݵĵط������ֲ� 
				for(int k=0;k<M;k++){//ö����һ�е�����״̬ 
					if((k&j)==0){//����������һ�е�ĳ��״̬��ì�� 
						dp[i][j]=(dp[i][j]+dp[i-1][k])%P;
					}
				}
			}
		}
	}
	for(int i=0;i<M;i++)
		ans=(ans+dp[n][i])%P;//ǰn�����кϷ��������ۼ� 
	printf("%d",ans);
	return 0;
}
