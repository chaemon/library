//{{{ Dinic max_flow
void addFlowEdge(Graph &g,int src,int dst,int cap){
	g[src].push_back(Edge(src,dst,cap,g[dst].size()));
	g[dst].push_back(Edge(dst,src,0,g[src].size()-1));
}

void addBiFlowEdge(Graph &g,int src,int dst,int cap){
	g[src].push_back(Edge(src,dst,cap,g[dst].size()));
	g[dst].push_back(Edge(dst,src,cap,g[src].size()-1));
}

static const int FLOW_INF=2000000005;

void bfs(const Graph &g,vector<vector<Weight> > &cap,vector<int> &level,int s){
	const int n=g.size();
	level.assign(n,-1);
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(not que.empty()){
		int v=que.front();que.pop();
		for(int i=0;i<(int)g[v].size();i++){
			const Edge &e=g[v][i];
			if(cap[v][i]>0 and level[e.dst]<0){
				level[e.dst]=level[v]+1;
				que.push(e.dst);
			}
		}
	}
}
int dfs(const Graph &g,vector<vector<Weight> > &cap,const vector<int> &level,vector<int> &iter,int v, int t, int f){
	const int n=g.size();
	if(v==t)return f;
	for(int &i=iter[v];i<(int)g[v].size();i++){
		const Edge &e=g[v][i];
		if(cap[v][i]>0 and level[v]<level[e.dst]){
			int d=dfs(g,cap,level,iter,e.dst,t,min(f,cap[v][i]));
			if(d>0){
				cap[v][i]-=d;
				cap[e.dst][e.rev]+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(const Graph &g,int s,int t){
	const int n=g.size();
	vector<int> level,iter;
	vector<vector<Weight> > cap(n);
	REP(i,n)REP(j,g[i].size())cap[i].push_back(g[i][j].weight);
	int flow=0;
	for(;;){
		bfs(g,cap,level,s);
		if(level[t]<0)return flow;
		iter.assign(n,0);
		int f;
		while((f=dfs(g,cap,level,iter,s,t,FLOW_INF))>0){
			flow+=f;
		}
	}
}
//}}}
