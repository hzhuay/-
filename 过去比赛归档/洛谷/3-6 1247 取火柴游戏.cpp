//Nimģ�ͣ����ÿ��ʯ���������ֵ,a1^a2^a3^......^an 
//��Ϊ0�����ֱ��䣻����Ϊ�㣬����Ҫ�ø�ֵΪ0���ú����� 
#include<cstdio>
int a[500005];
int main(){
	int n,nim=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		nim^=a[i];
	}
	if(nim==0)puts("lose");
	else{
		for(int i=0;i<n;i++){
//nim=a1^a2^a3^......^an������a1^(a2^nim)^...^an=0 
			if((a[i]^nim)<a[i]){//a[i]^nim��ʣ�µ�ʯͷ����ӦС��a[i]���ǺϷ����� 
				printf("%d %d\n",a[i]-(a[i]^nim),i+1);
				a[i]^=nim;
				break; 
			}
		}
		for(int i=0;i<n;i++)printf("%d ",a[i]);
	}
	return 0;
}
