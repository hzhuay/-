#include<iostream>
#include<cstdio> 
#include<queue>
#include<map>
using namespace std;
const int maxt=1000+10;
int main(){
	int t,kase=0;
	while(scanf("%d",&t)==1&&t){
		printf("Scenario #%d\n",++kase);
		//��ס�����˵ı��
		map<int,int>team;//team[x]��ʾ���Ϊx�������ڵ��Ŷӵı��
		for(int i=0;i<t;i++){
			int n,x;
			scanf("%d",&n);
			while(n--){scanf("%d",&x);team[x]=i;}
		}
		//ģ��
		queue<int>q,q2[maxt];
		for(;;){
			int x;
			char cmd[10];
			scanf("%s",cmd);
			if(cmd[0]=='S')break;
			else if(cmd[0]=='D'){
				int t=q.front();
				printf("%d\n",q2[t].front());q2[t].pop();
				if(q2[t].empty())q.pop();//����tȫ������� 
			}else if(cmd[0]=='E'){
				scanf("%d",&x);
				int t=team[x];
				if(q2[t].empty())q.push(t);//����t�������	
				q2[t].push(x); 
			}
		}
		puts("");
	}
	return 0;
}
