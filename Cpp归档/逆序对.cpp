//�������Ԫ�صĴ�С��int��Χ�Ļ���Ҫ��һ����ɢ�� 
/*���ǿ����ȿ�һ����СΪa�����ֵ������t��ÿ������һ����ʱ�����ǿ�����Ͱ�����˼�룬
��C[a[i]]����1,Ȼ������ͳ��C[1]~C[a[i]]�ĺ�ans��ans - 1��������������������������ǰ���ж��ٸ�������С��
����ֻҪ��i-ans�Ϳ��Եó�ǰ���ж�����������Ҳ��������Ե�������
*/
#include<cstdio>
#define lowbit(x) (-(x)&(x))//�����ư�λ�����㣬���ز�����x��2�����η�����
const int M=500000+5;//����Ԫ�ص����ֵ 
int C[M];
int query(int x){//ÿ����ǰ����û�У��м������Լ������ 
	int res=0;
	while(x>0){
		res+=C[x];
		x-=lowbit(x);
	}
	return res;
}
void update(int a){
	while(a<M){
		C[a]++;
		a+=lowbit(a);
	}	
}
int main(){
	int i,n,tmp,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&tmp);
		update(tmp);
		ans+=i-query(tmp);
	}
	printf("%d\n",ans);
	return 0;
}
