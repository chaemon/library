//{{{ ford-fulkerson maxflow
struct maxFlow{
	static const int INF=2000000005;
	int n;
	struct edge{int to,cap,rev;};
	vector<vector<edge> > G;
	vector<bool> used;
	maxFlow(int n):n(n){
		G.assign(n,vector<edge>());
	}
	void add_edge(int from ,int to, int cap1, int cap2){
		G[from].push_back((edge){to,cap1,G[to].size()});
		G[to].push_back((edge){from,cap2,G[from].size()-1});
	}
	int dfs(int v, int t, int f){
		if(v==t)return f;
		used[v]=true;
		for(int i=0;i < (int)G[v].size();i++){
			edge &e=G[v][i];
			if(!used[e.to]&&e.cap>0){
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
			used.assign(n,false);
			int f=dfs(s,t,INF);
			if(f==0)return flow;
			flow+=f;
		}
	}
};
//}}}
