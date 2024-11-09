#include<bits/stdc++.h>
using namespace std;
const int maxm=200000+5;
const int maxn=5000+5;
int n,m,ans,u[maxm],v[maxm],w[maxm],p[maxn],r[maxm];
int cmp(const int i,const int j){return w[i]<w[j];}//��������� 
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}//���鼯��find 
int kruskal(){
	for(int i=0;i<n;i++)p[i]=i;//��ʼ�����鼯 
	for(int i=0;i<m;i++)r[i]=i;//��ʼ������� 
	sort(r,r+m,cmp);//��������
	for(int i=0;i<m;i++){
		int e=r[i];
		int x=find(u[e]);
		int y=find(v[e]);//�ҳ���ǰ�������˵����ڼ��ϱ�� 
		if(x!=y){//�������ͳһ���ϣ��ϲ� 
			ans+=w[e];
			p[x]=y;
		}
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	if(kruskal())printf("%d",ans);
	else printf("orz");
	return 0;
}
