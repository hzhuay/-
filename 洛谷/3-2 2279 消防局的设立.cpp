#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1005;
int f[maxn],order[maxn],layer[maxn],dis[maxn];
bool cmp(int i,int j){return layer[i]>layer[j];}//������� 
int main(){
	int n,ans=0,fa,now,gf;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		scanf("%d",&f[i]);//�����ϣ��������ÿ���ڵ�ĸ��ڵ� 
		layer[i]=layer[f[i]]+1;
	}
	for(int i=0;i<=n;i++){
		order[i]=i;
		dis[i]=maxn;
	}
	sort(order+1,order+n+1,cmp);//�����b����Ϊ�ڵ㴦��˳�����Ĳ�α��� 
//��������ڲ���� 
	for(int i=1;i<=n;i++){
		now=order[i];
		fa=f[now];
		gf=f[f[now]];
		dis[now]=min(dis[now],min(dis[fa]+1,dis[gf]+2));
		if(dis[now]>2){
			dis[gf]=0;
			ans++;
			dis[f[gf]]=min(dis[f[gf]],1);
			dis[f[f[gf]]]=min(dis[f[f[gf]]],2);
		}
	}
	printf("%d",ans);
	return 0;
}
