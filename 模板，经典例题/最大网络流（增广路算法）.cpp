#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<climits>
using namespace std;
const int maxn=10005; 
struct Edge{
	int from,to,cap,flow;
	Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};
struct EdmondsKarp{
	int n,m;
	vector<Edge>edges;//���������� 
	vector<int>G[maxn];//�ڽӱ�G[i][j]��ʾ�ڵ�i�ĵ�j������e�����е����
	int a[maxn];//��ǰ�㵽i�ĿɸĽ���
	int p[maxn];//���·����p���뻡���
	
	void init(int n){
		for(int i=0;i<n;i++)G[i].clear();
		edges.clear(); 
	}
	
	void AddEdge(int from,int to,int cap){
		edges.push_back(Edge(from,to,cap,0));
		edges.push_back(Edge(to,from,0,0));//����
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1); 
	}
	
	int Maxflow(int s,int t){
		int flow=0;
		for(;;){
			memset(a,0,sizeof(a));
			queue<int>Q;
			Q.push(s);
			a[s]=INT_MAX;
			while(!Q.empty()){
				int x=Q.front();Q.pop();
				for(int i=0;i<(int)G[x].size();i++){
					Edge& e=edges[G[x][i]];
					if(a[e.to]==0&&e.cap>e.flow){
						p[e.to]=G[x][i];
						a[e.to]=min(a[x],e.cap-e.flow);
						Q.push(e.to);
					}
				}
				if(a[t]>0)break;
			}
			if(a[t]==0)break;
			for(int u=t;u!=s;u=edges[p[u]].from){
				edges[p[u]].flow+=a[t];
				edges[p[u]^1].flow-=a[t];//һ����ż���ı߻�Ϊ�෴�ߣ�����^1�Ϳ��໥�õ� 
			}
			flow+=a[t];
		}
		return flow;
	}
};
int main(){
	EdmondsKarp E; 
	int n,m,s,t,u,v,c;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&c);
		E.AddEdge(u,v,c);
	}
	printf("%d",E.Maxflow(s,t));
	return 0;
}

