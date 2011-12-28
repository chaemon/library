//{{{ read graph
void read_graph(Graph &g,int n=-1,int m=-1){
	if(n==-1)scanf("%d",&n);
	g.assign(n,Edges());
	if(m==-1)scanf("%d",&m);
// m=n-1 tree??
	REP(i,m){
		int a,b;
		scanf("%d%d",&a,&b);
		//a--;b--; //if a, b is 1-based
		int w=1;
//		scanf("%d",&w);
		g[a].push_back(Edge(a,b,w));
		g[b].push_back(Edge(b,a,w));
	}
}
//}}}
