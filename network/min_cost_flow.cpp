//{{{ min_cost_flow
const Int INF=100000000000000000ll;
const int MAX_V=150;

struct edge{ int to,cap,cost,rev;};

int V;
vector<edge> G[MAX_V];
Int dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];

void add_edge(int from,int to,int cap,int cost){
	G[from].push_back((edge){to,cap,cost,G[to].size()});
	G[to].push_back((edge){from,0,-cost,G[from].size()-1});
}

Int min_cost_flow(int s,int t,int f){
	Int res=0;
	while(f>0){
		fill(dist,dist+V,INF);
		dist[s]=0;
		bool update=true;
		while(update){
			update=false;
			for(int v=0;v<V;v++){
				if(dist[v]==INF)continue;
				for(int i=0;i<G[v].size();i++){
					edge &e=G[v][i];
					if(e.cap>0 && dist[e.to]>dist[v]+e.cost){
						dist[e.to]=dist[v]+e.cost;
						prevv[e.to]=v;
						preve[e.to]=i;
						update=true;
					}
				}
			}
		}
		if(dist[t]==INF)return -1;

		int d=f;
		for(int v=t;v!=s;v=prevv[v]){
			d=min(d,G[prevv[v]][preve[v]].cap);
		}
		f-=d;
		res+=d*dist[t];
		for(int v=t;v!=s;v=prevv[v]){
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
	}
	return res;
}
//}}}
