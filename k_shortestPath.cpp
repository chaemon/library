//{{{ k_shortestPath
Weight k_shortestPath(const Graph &g, int s, int t, int k) {
	const int n = g.size();

	Graph h(n); // make reverse graph
	REP(u, n) FOR(e, g[u])
		h[e->dst].push_back(Edge(e->dst,e->src,e->weight));

	vector<Weight> d(n, INF); d[t] = 0; // make potential
	vector<int> p(n, -1);               // using backward dijkstra
	priority_queue<Edge> Q; Q.push(Edge(t, t, 0));
	while (!Q.empty()) {
		Edge e = Q.top(); Q.pop();
		if (p[e.dst] >= 0) continue;
		p[e.dst] = e.src;
		FOR(f, h[e.dst]) if (d[f->dst] > e.weight + f->weight) {
			d[f->dst] = e.weight + f->weight;
			Q.push(Edge(f->src, f->dst, e.weight + f->weight));
		}
	}
	int l = 0; // forward dijkstra-like method
	priority_queue<Edge> R; R.push(Edge(-1,s,0));
	set<int> si;
	while (!R.empty()) {
		Edge e = R.top(); R.pop();
//		cout<<e.src<<" "<<e.dst<<" "<<e.weight<<endl;
		if (e.dst == t ){
			si.insert(e.weight+d[s]);
			if(si.size() == k){
				set<int>::iterator it=si.end();
				it--;
				return *it;
			}
		}
		FOR(f, g[e.dst])
			R.push(Edge(f->src, f->dst, e.weight+f->weight-d[f->src]+d[f->dst]));
	}
	return -1; // not found
}
//}}}
