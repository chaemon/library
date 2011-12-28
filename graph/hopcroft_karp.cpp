//{{{ bipartite Match (hopcroft karp)
bool augment(const Graph &g,int left,const int &n,vector<bool> &visited,vector<int> &levels,vector<int> &matching) {
	if (left == n)return true;
	if (visited[left])return false;
	visited[left] = true;
	REP(i, g[left].size()) {
		int right = g[left][i].dst;
		int next = matching[right];
		if (levels[next] > levels[left] && augment(g,next,n,visited,levels,matching)) {
			matching[right] = left;
			return true;
		}
	}
	return false;
}

int bipartiteMatching(const Graph &g,int n,int m,Edges &ans) {
	vector<bool> matched(n,false),visited;
	vector<int> levels,matching(m,n);
	bool cont;
	do {
		levels.assign(n+1, -1);
		levels[n] = n;
		queue<int> q;
		REP(left, n) {
			if (!matched[left]) {
				q.push(left);
				levels[left] = 0;
			}
		}
		while(!q.empty()) {
			int left = q.front();
			q.pop();
			REP(i, g[left].size()) {
				int right = g[left][i].dst, next = matching[right];
				if (levels[next] < 0) {
					levels[next] = levels[left] + 1;
					q.push(next);
				}
			}
		}
		visited.assign(n, false);
		cont = false;
		REP(left, n)
			if (!matched[left] && augment(g,left,n,visited,levels,matching))
				matched[left] = cont = true;
	} while(cont);
	ans.clear();
	REP(i,m)if(matching[i]!=n)ans.push_back(Edge(matching[i],i));
	return count(ALL(matched), true);
}
//}}}
