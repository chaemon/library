//{{{ 2SAT stronglyConnectedComponents and topologicalSort
#define VAR(x) ((x) << 1)
#define NOT(x) ((x) ^ 1)

vector<int> sr;
vector<vector<int> > scc;

typedef pair<int,int> clause;
bool two_satisfiability(int m, const vector<clause> &cs) {
	int n = m * 2; // m positive vars and m negative vars
	Graph g(n), h(n);
	for (int i = 0; i < cs.size(); ++i) {
		int u = cs[i].first, v = cs[i].second;
		g[NOT(u)].push_back( Edge(NOT(u), v) );
		g[NOT(v)].push_back( Edge(NOT(v), u) );
	}
	//	vector<vector<int> > scc;
	stronglyConnectedComponents(g,scc);
	sr.clear();
	sr.assign(n,-1);
	REP(i,scc.size())
		REP(j,scc[i].size())sr[scc[i][j]]=i;
	for (int i = 0; i < n; ++i)
		if (sr[i] == sr[NOT(i)])
			return false;
	return true;
}

vector<int> build_example(int m,const vector<clause> &cs){
	Graph g(scc.size());
	vector<int> ans;
	for(int i=0;i<cs.size();i++){
		int u=cs[i].first,v=cs[i].second;
		if(sr[NOT(u)]!=sr[v]){
			assert(sr[NOT(v)]!=sr[u]);
			g[sr[NOT(u)]].push_back( Edge(sr[NOT(u)], sr[v]) );
			g[sr[NOT(v)]].push_back( Edge(sr[NOT(v)], sr[u]) );
		}
	}
	vector<int> order;
	bool b2=topologicalSort(g,order);
	assert(b2);
	for(int i=0;i<m;i++){
		int u=VAR(i),nu=NOT(u);
		if(order[sr[u]]>order[sr[nu]])ans.push_back(i);
	}
	return ans;
}
//}}}
