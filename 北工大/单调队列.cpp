#include<cstdio>
#include<cstring>
const int N=1000005;
int n,m;
int s[N];
int front,rear;
int q[N],ed[N];//ed�� 
void getmin(){//front>rear 
	front=1;rear=0;
	for(int i=1;i<m;i++){
		while(front<=rear&&q[rear]>=s[i])rear--;
		rear++;q[rear]=s[i];ed[rear]=i;
	}
	for(int i=m;i<=n;i++){
		while(front<=rear&&q[rear]>=s[i])rear--;//�Ӷ�β��һ��С�����Ԫ��
		rear++;q[rear]=s[i];ed[rear]=i;//�����Ԫ�ط��������� 
		while(ed[front]<=i-m)front++;//ȷ����ͷ���ڻ��������� 
		printf("%d ",q[front]);
	}
	printf("\n");
}
void getmax(){
	front=1;rear=0;
	for (int i=1;i<m;i++){
		while(front<=rear&&q[rear]<=s[i])rear--;
		rear++;q[rear]=s[i];ed[rear]=i;
	}
	for (int i=m;i<=n;i++){
		while(front<=rear&&q[rear]<=s[i])rear--;
		rear++;q[rear]=s[i];ed[rear]=i;
		while(ed[front]<=i-m)front++;
		printf("%d ",q[front]);
	}
	printf("\n");
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	getmin();getmax();
	return 0;
}
