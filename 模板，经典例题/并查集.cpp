//���鼯 
#include<bits/stdc++.h>
using namespace std;
int f[10010];
int find(int k){
    if(f[k]==k)return k;
    return f[k]=find(f[k]);
}
int main(){
	int n,m,p1,p2,p3;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)f[i]=i;//��ʼ��i���ϴ�Ϊ�Լ� 
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&p1,&p2,&p3);
        if(p1==1)
            f[find(p2)]=find(p3);//p3��Ӯ��p2
        else
            if(find(p2)==find(p3))//�Ƿ���һ��� 
                printf("Y\n");
            else
                printf("N\n");
    }
    return 0;
}
