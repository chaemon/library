//{{{ Dijkustra Shortest Path
int n,m,k,d;

const int M=10010;
int dist[M][11];
bool vis[M][11];

Graph g;

struct S{
	int a,b,v;
	bool operator<(const S &s)const {
		return v>s.v;
	}
	S(int a,int b,int v):a(a),b(b),v(v){}
};

void shortestPath(int s) {
	memset(vis,false,sizeof(vis));
	priority_queue<S> Q; // "e < f" <=> "e.weight > f.weight"
	REP(a,M)REP(b,11)dist[a][b]=INF;
	for (Q.push(S(s, d, 0)); !Q.empty(); ) {
		const S &s = Q.top();
		const int a=s.a,b=s.b,v=s.v;
		Q.pop();
		if (vis[a][b]) continue;
		vis[a][b]=true;
		dist[a][b]=v;
		FOR(f,g[a]) {
			int a2=f->dst, b2=b;
			if(f->rev)b2--;
			if(b2<0)continue;
			if(dist[a2][b2]>dist[a][b]+f->weight){
				dist[a2][b2]=dist[a][b]+f->weight;
				Q.push(S(a2,b2,dist[a2][b2]));
			}
		}
	}
}
//}}}
