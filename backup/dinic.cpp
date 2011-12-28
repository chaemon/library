//{{{ Dinic maxflow
struct maxFlow{
	static const int INF=2000000005;
	int n;
	struct edge{int to,cap,rev;};
	vector<vector<edge> > G;
	vector<int> level,iter;
	maxFlow(int n):n(n){
		G.assign(n,vector<edge>());
	}
	void add_edge(int from ,int to, int cap1, int cap2){
		G[from].push_back((edge){to,cap1,G[to].size()});
		G[to].push_back((edge){from,cap2,G[from].size()-1});
	}
	void bfs(int s){
		level.assign(n,-1);
		queue<int> que;
		level[s]=0;
		que.push(s);
		while(not que.empty()){
			int v=que.front();que.pop();
			for(int i=0;i<(int)G[v].size();i++){
				edge &e=G[v][i];
				if(e.cap>0 and level[e.to]<0){
					level[e.to]=level[v]+1;
					que.push(e.to);
				}
			}
		}
	}
	int dfs(int v, int t, int f){
		if(v==t)return f;
		for(int &i=iter[v];i<(int)G[v].size();i++){
			edge &e=G[v][i];
			if(e.cap>0 and level[v]<level[e.to]){
				int d=dfs(e.to,t,min(f,e.cap));
				if(d>0){
					e.cap-=d;
					G[e.to][e.rev].cap+=d;
					return d;
				}
			}
		}
		return 0;
	}
	int max_flow(int s,int t){
		int flow=0;
		for(;;){
			bfs(s);
			if(level[t]<0)return flow;
			iter.assign(n,0);
			int f;
			while((f=dfs(s,t,INF))>0){
				flow+=f;
			}
		}
	}
};
//}}}
