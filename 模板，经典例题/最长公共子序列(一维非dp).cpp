#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int dis[maxn],a[maxn],b[maxn],f[maxn];
inline int max(int a,int b){return a<b?b:a;}
int main(){
	freopen("in.txt","r",stdin);
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dis[a[i]]=i;
	}
//��ɢ������ԭ����a��������.��Ϊ���� 
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		b[i]=dis[b[i]];
		f[i]=INT_MAX;
	}
//������ת��Ϊ��b���е�����½������� 
	for(int i=1;i<=n;i++){
		if(b[i]>f[ans])f[++ans]=b[i];
		else{
			int tmp=lower_bound(f+1,f+n+1,b[i])-f;
			f[tmp]=min(b[i],f[tmp]);
		}
	}
	printf("%d",ans);
	return 0;
}
