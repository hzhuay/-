#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=100000+5;
int to[maxn],ori[maxn],in[maxn],from_ori[maxn],size[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&to[i]);
	for(int i=1;i<=n;i++){
		for(int j=i,cnt=0;;j=to[j],cnt++){
			if(!ori[j]){//��һ�η��� 
				ori[j]=i;
				from_ori[j]=cnt;
			}else if(ori[j]==i){//�ص���� 
				size[i]=cnt-from_ori[j];
				in[i]=from_ori[j];
				printf("%d\n",cnt); 
				break;
			}else{//������㲻ͬ���߹�����· 
				size[i]=size[ori[j]];
				in[i]=cnt+max(in[ori[j]]-from_ori[j],0);
				printf("%d\n",in[i]+size[i]);
				break;
			}
		}
	}
	return 0;
} 
