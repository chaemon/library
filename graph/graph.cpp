//{{{ Graph
typedef int Weight;
struct Edge {
	int src, dst, rev;
	Weight weight;
	Edge(int src, int dst, Weight weight=1,int rev=-1) :
		src(src), dst(dst), weight(weight), rev(rev) { }
};
bool operator < (const Edge &e, const Edge &f) {
	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
		e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

//add bi-directional edge
void addBiEdge(Graph &g,int from ,int to, int w=1){
	while(g.size()<max(from,to)+1)g.push_back(Edges());
	g[from].push_back(Edge(from,to,w,g[to].size()));
	g[to].push_back(Edge(to,from,w,g[from].size()-1));
}
//add directional edge
void addEdge(Graph &g,int from ,int to, int w=1){
	while(g.size()<from+1)g.push_back(Edges());
	g[from].push_back(Edge(from,to,w,g[to].size()));
}
//}}}
