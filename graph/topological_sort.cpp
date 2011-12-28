//{{{ topological sort
bool visit(const Graph &g, int v, vector<int> &order, vector<int> &color,vector<int> &next) {
	color[v] = 1;
	FOR(e, g[v]) {
		if (color[e->dst] == 2) continue;
		if (color[e->dst] == 1){
			order.clear();
			int t=e->dst;
			while(1){
				order.push_back(t);
				if(t==v)break;
				t=next[t];
			}
			return false;
		}
		next[v]=e->dst;
		if (!visit(g, e->dst, order, color, next)) return false;
		next[v]=-1;
	}
	order.push_back(v); color[v] = 2;
	return true;
}
bool topologicalSort(const Graph &g, vector<int> &order) {
	int n = g.size();
	vector<int> color(n),next(n,-1);
	REP(u, n) if (!color[u] && !visit(g, u, order, color, next))
		return false;
	reverse(ALL(order));
	return true;
}
//}}}
