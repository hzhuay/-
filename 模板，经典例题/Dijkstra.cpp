#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
#define M 10005
using namespace std;
struct node{
	int to,v;
	bool operator<(const node &b)const{
		return v>b.v;
	}
};
vector<node>edge[M];
priority_queue<node>Q;
bool mark[M];
int dis[M],pre[M];
void Dijkstra(int st,int n){
	node now,nxt;
	for(int i=1;i<=n;i++){
		dis[i]=INT_MAX;
	}
	dis[st]=0;
	Q.push((node){st,0});
	while(!Q.empty()){
		now=Q.top();
		Q.pop();
		if(mark[now.to])continue;
		//if(now.to==n)return now.v;//����ǵ���㵥�յ�����·���������ֱ��return 
		mark[now.to]=true;
		for(int i=0;i<(int)edge[now.to].size();i++){
			nxt=edge[now.to][i];
			if(dis[nxt.to]>now.v+nxt.v){
				dis[nxt.to]=now.v+nxt.v;
				pre[nxt.to]=now.to;
				Q.push((node){nxt.to,dis[nxt.to]});
			}
		}
	}
	//return INT_MAX;//������������· 
}
int main(){
	int n,m,st;
	scanf("%d%d%d",&n,&m,&st);
	while(m--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		edge[a].push_back((node){b,c});
		//edge[b].push_back((node){a,c});//�������������ͼ��������ͼ 
	}
	Dijkstra(st,n);
	for(int i=1;i<=n;i++)printf("%d ",dis[i]);
	return 0;
}
