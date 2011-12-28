//{{{ isBipartite
bool visit(const Graph &g,int v,int col,vector<int> &color){
	if(color[v]!=-1){
		if(col==color[v])return true;
		else return false;
	}
	color[v]=col;
	FOR(e,g[v]){
		bool b=visit(g,e->dst,1-col,color);
		if(!b)return false;
	}
	return true;
}

bool isBipartite(const Graph &g,vector<int> &A){
	int n=g.size();
	vector<int> color(n,-1);
	REP(v,n){
		if(color[v]!=-1)continue;
		bool b=visit(g,v,0,color);
		if(!b)return false;
	}
	A.clear();
	REP(v,n)if(color[v])A.push_back(v);
	return true;
}
//}}}
