#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=800005;
struct interval{
	int a,b;
	bool operator < (const interval& x)const{return b<x.b;}
	/*bool operator < (const interval& x)const{
		if(b!=x.b)return b<x.b;
		else return a<x.a;
	}*/
}work[maxn];
/*bool cmp(interval x,interval y){//ddl��ͬ�Ļ�����ʱ�̵����ȼ��� 
	if(x.b!=y.b)return x.b<y.b;
	else return x.a<y.a;
}*/
int main(){
	//freopen("in.txt","r",stdin);
	int kase,n;
	scanf("%d",&kase);
	while(kase--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d%d",&work[i].a,&work[i].b);
		sort(work,work+n);//ddl����������� 
		//for(int i=0;i<n;i++)printf("%d%c",work[i].b," \n"[i==n-1]);
		int ans=0,tmp=0;
		priority_queue<int>pq;
		for(int i=0;i<n;i++){
			if(tmp+work[i].a<=work[i].b){
				tmp+=work[i].a;
				ans++;
				pq.push(work[i].a);
			}else{//����һ������ 
				if(!pq.empty()){//�п��ܸտ�ʼ�����������Ѿ�����ʱ�����ddl 
					if(work[i].a<pq.top()){
						if(tmp-pq.top()+work[i].a<=work[i].b){//Ҳ������������ھ�break 
						//if(tmp-pq.top()+work[i].a>work[i].b)break;	
							tmp=tmp-pq.top()+work[i].a;
							pq.pop();
							pq.push(work[i].a);
						}
					}
				}
			}
		}
		printf("%d\n",ans);
		if(kase)puts("");
		memset(work,0,sizeof(work));
	}
	return 0;
}
